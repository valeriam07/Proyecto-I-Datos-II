#include "VSPtr.h"
#include <iostream>
#include <fstream>


using namespace std;

thread GarbageCollector :: freeMemory(){
    try{
            
                //garbage collector func
                for(int i=0; i< (sizeof(GarbageCollector::references))/(sizeof(GarbageCollector::references[0])) && GarbageCollector::references[i] != 0; i++){

                    if(GarbageCollector::references[i] = 0){
                        delete GarbageCollector::addess[i];
                        cout << "ELIMINADO" << addess[i] << endl;
                    }

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
    
    cout << "_________________________________"<< endl;

}

string GarbageCollector::getID(int key){
    return GarbageCollector::IDs[key];
}

int* GarbageCollector::getAdress(int key){
    return GarbageCollector::addess[key];
}


int main(){
    //VSPtr<int> myPtr = VSPtr<int> ::New();
 
    VSPtr<int> ptr(new int());
    *ptr = 20;
    VSPtr<int> ptr2(new int());
    *ptr2 =30;
    ptr = ptr2;
    return 0;


}
