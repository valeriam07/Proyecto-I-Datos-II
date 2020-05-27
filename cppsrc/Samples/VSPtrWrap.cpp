#include <napi.h>
#include "VSPtrWrap.h"


Napi::FunctionReference VSWrap::constructor;

Napi::Object VSWrap::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "VSWrap", {
    InstanceMethod("getID", &VSWrap::getId),
    InstanceMethod("getADRESS", &VSWrap::getAdress),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("VSWrap", func);
  return exports;
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



