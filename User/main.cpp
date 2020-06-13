#include "./VSPointer/VSPtr.h"

int main(){
    VSPtr<int> ptr(new int());
    *ptr = 89;
    VSPtr<int> ptr2(new int());
    *ptr2 = 27;
    //thread t(g->freeMemory);
    //t.join();
    ptr.end();

}