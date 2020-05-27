#include <napi.h>
#include "VSPtr.h"


class VSWrap : public Napi::ObjectWrap<VSWrap> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  VSWrap(const Napi::CallbackInfo& info);
  GarbageCollector* GetInternalInstance();

 private:
  static Napi::FunctionReference constructor;
  Napi::Value getId(const Napi::CallbackInfo& info);
  Napi::Value getAdress(const Napi::CallbackInfo& info);
  GarbageCollector *garbageCollector_;
};



/*
class VSWrap : public Napi::ObjectWrap<VSWrap>{

	public:
	static Napi::Object Init (Napi::Env env, Napi::Object exports); //inicio de la comunicacion
	VSWrap(const Napi::CallbackInfo& info); // inicializar constructor napi
	GarbageCollector* GetInternalInstance();


	private:
	static Napi::FunctionReference constructor;
	Napi:Value getID(const Napi::CallbackInfo& info); //getID envuelta
	Napi:Value getAdress(const Napi::CallbackInfo& info); //getAdress envuelta
	GarbageCollector *garbageCollector_;


	
};
*/