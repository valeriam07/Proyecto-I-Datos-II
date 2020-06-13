#include "./VSPointer/VSPtr.h"
#include "VSPointer/clientsocket.h"

int main(){
    VSPtr<int> ptr(new int());
    *ptr = 60;
    VSPtr<int> ptr2(new int());
    *ptr2 = 30;
    end();


}