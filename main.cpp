#include "./VSPointer/VSPtr.h"

int main(){
    VSPtr<int> ptr(new int());
    *ptr = 20;
    VSPtr<int> ptr2(new int());
    *ptr2 = 30;


}