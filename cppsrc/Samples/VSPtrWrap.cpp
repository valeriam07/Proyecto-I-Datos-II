#include <napi.h>
#include "VSPtrWrap.h"


Napi::FunctionReference VSWrap::constructor;

Napi::Object VSWrap::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "VSWrap", {
    InstanceMethod("add", &VSWrap::Add),
    InstanceMethod("getValue", &VSWrap::GetValue),
  });


  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("VSWrap", func);
  return exports;
}


VSWrap::VSWrap(const Napi::CallbackInfo& info) : Napi::ObjectWrap<VSWrap>(info)  {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int length = info.Length();
  
  if (length != 1) {
    Napi::TypeError::New(env, "Only one argument expected").ThrowAsJavaScriptException();
  }

  if(!info[0].IsNumber()){
    Napi::Object object_parent = info[0].As<Napi::Object>();
    VSWrap* example_parent = Napi::ObjectWrap<VSWrap>::Unwrap(object_parent);
    GarbageCollector* parent_actual_class_instance = example_parent->GetInternalInstance();
    this->garbageCollector_ = new GarbageCollector(parent_actual_class_instance->getValue());
    return;
  }

  Napi::Number value = info[0].As<Napi::Number>();
  this->garbageCollector_ = new GarbageCollector(value.DoubleValue());
}

Napi::Value VSWrap::GetValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  double num = this->garbageCollector_->getValue();
  return Napi::Number::New(env, num);
}


Napi::Value VSWrap::Add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1 || !info[0].IsNumber()) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }

  Napi::Number toAdd = info[0].As<Napi::Number>();
  double answer = this->garbageCollector_->add(toAdd.DoubleValue());

  return Napi::Number::New(info.Env(), answer);
}

GarbageCollector* VSWrap::GetInternalInstance() {
  return this->garbageCollector_;
}













/*
Napi::FunctionReference VSWrap::constructor;

Napi::Object VSWrap::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

Napi::Function func = DefineClass(env, "VSWrap",{
	InstanceMethod("getID", &VSWrap::GetID),
	InstanceMethod("getAdress", &VSWrap::GetAdress),

});

constructor = Napi::Persistent(func);
constructor.SuppressDrestruct; //no entendi

exports.Set("VSWraptr", func);
return exports;
*/






/*
  Napi::Function func = DefineClass(env, "VSWraptr", {
	  
    InstanceMethod("add", &VSWrap::Add),
    InstanceMethod("getValue", &VSWrap::GetValue),
	
  });


  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("VSWrap", func);
  return exports;
  */



