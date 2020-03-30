#include "VSPtr.h"
#include <iostream>

using namespace std;

void GarbageCollector :: thread(){
    try{
            while(true){
                //garbage collector func
                sleep(10000);
            }
        }catch(std::exception const&){
            cout << "Error en el thread" << endl;
        }
}

int main(){
    //VSPtr<int> myPtr = VSPtr<int> ::New();
    VSPtr<int> ptr(new int());
    VSPtr<int> ptr2(new int());
    return 0;

}