#include <napi.h>
#include "VSPtr.h"

class VsptrWrap : public Napi::ObjectWrap<VsptrWrap> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  VsptrWrap(const Napi::CallbackInfo& info);
  GarbageCollector* GetInternalInstance();

 private:
  static Napi::FunctionReference constructor;
  Napi::Value GetID(const Napi::CallbackInfo& info);
  GarbageCollector *garbageCollector_;
};
