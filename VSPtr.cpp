#include "VSPtr.h"
#include <iostream>
#include <fstream>

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

void GarbageCollector :: saveAddress(int VSPtrCount, int* ptr){
    GarbageCollector::addess[VSPtrCount-1] = ptr;

    for(int i=0; i< (sizeof(GarbageCollector::addess))/(sizeof(GarbageCollector::addess[0])) && GarbageCollector::addess[i] != 0; i++){

        cout << "ADDRESS (" << i << ") " << GarbageCollector::addess[i] << endl;
    }
    
}

void GarbageCollector :: generateID(){

    string ID = "VSPTR_" + to_string(VSPtrCount);
    GarbageCollector::IDs[VSPtrCount-1] = ID;

    for(int i=0; i< (sizeof(GarbageCollector::addess))/(sizeof(GarbageCollector::addess[0])) && GarbageCollector::addess[i] != 0; i++){

        cout << "ID (" << i << ") " << GarbageCollector::IDs[i] << endl;
    }
    
    
}



int main(){
    //VSPtr<int> myPtr = VSPtr<int> ::New();
    VSPtr<int> ptr(new int());
    VSPtr<int> ptr2(new int());
    return 0;

}
