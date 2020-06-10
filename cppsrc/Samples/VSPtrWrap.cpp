#include "VSPtrWrap.h"

Napi::FunctionReference VsptrWrap::constructor;

Napi::Object VsptrWrap::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "VsptrWrap", {
    InstanceMethod("getAddressList", &VsptrWrap::GetID),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("VsptrWrap", func);
  return exports;
}
//-------------------------------------------------------------------------------------------------------

VsptrWrap::VsptrWrap(const Napi::CallbackInfo& info) : Napi::ObjectWrap<VsptrWrap>(info)  {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

    //Napi::Object object_parent = info[0].As<Napi::Object>();
    // VsptrWrap* example_parent = Napi::ObjectWrap<VsptrWrap>::Unwrap(object_parent);
    //GarbageCollector* parent_actual_class_instance = example_parent->GetInternalInstance();
    // this->garbageCollector_ = GarbageCollector::getInstance();
    // return;
  

 // Napi::Array value = info[0].As<Napi::Array>();
 //this->garbageCollector_ = GarbageCollector::getInstance();
}


Napi::Value VsptrWrap::GetID(const Napi::CallbackInfo& info) {
 // Napi::Env env = info.Env();
  // Napi::Array & num = {this->garbageCollector_->getAddressList()};
 // return Napi::Array::New(env);
}





GarbageCollector* VsptrWrap::GetInternalInstance() {
 // return this->garbageCollector_;
}