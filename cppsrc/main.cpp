/* cppsrc/main.cpp */
#include <napi.h>
#include "Samples/VSPtrWrap.h"
Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  //return functionexample::Init(env, exports);
    VSPtr<int> ptr(new int());
    *ptr = 20;
    VSPtr<int> ptr2(new int());
    *ptr2 =30;
    ptr = ptr2;
  return VSWrap::Init(env, exports);
}

NODE_API_MODULE(testaddon, InitAll)

/*
int main(){
    //VSPtr<int> myPtr = VSPtr<int> ::New();
 
    VSPtr<int> ptr(new int());
    *ptr = 20;
    VSPtr<int> ptr2(new int());
    *ptr2 =30;
    ptr = ptr2;
    return 0;


}
*/