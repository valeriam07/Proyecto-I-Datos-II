//#include "functionexample.h"
#include "VSPtr.h"
#include <iostream>
#include <fstream>


GarbageCollector::GarbageCollector(double value){
   this->value_ = value;
}

double GarbageCollector::getValue()
{
  return this->value_;
}

double GarbageCollector::add(double toAdd)
{
  this->value_ += toAdd;
  return this->value_;
}

/*
using namespace std;


//PARTE NUEVA -----------------------
thread GarbageCollector :: freeMemory(){
       std::cout<< "Entro a Free Memory" << std::endl;

    try{

        while(true){

            for(int i=0; i< (int)((sizeof(GarbageCollector::references))/(sizeof(GarbageCollector::references[0]))) && GarbageCollector::references[i] != 0; i++) {

                if ((GarbageCollector::references[i] = 0)) {
                    delete GarbageCollector::addess[i];
                    cout << "ELIMINADO" << addess[i] << endl;
                }

                sleep(10000);
            }

        }
        
    }catch(std::exception const&){
            cout << "Error en el thread" << endl;
            //return 0;
    }
}

void GarbageCollector :: saveAddress(int VSPtrCount, int* ptr){
    GarbageCollector::addess[VSPtrCount-1] = ptr;

    for(int i=0; i< (int)((sizeof(GarbageCollector::addess))/(sizeof(GarbageCollector::addess[0]))) && GarbageCollector::addess[i] != 0; i++){

        cout << "ADDRESS (" << i << ") " << GarbageCollector::addess[i] << endl;
    }
    
}


void GarbageCollector :: generateID(){

    string ID = "VSPTR_" + to_string(VSPtrCount);
    GarbageCollector::IDs[VSPtrCount-1] = ID;


    for(int i=0; i< (int)((sizeof(GarbageCollector::addess))/ int (sizeof(GarbageCollector::addess[0]))) && GarbageCollector::addess[i] != 0; i++){

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








*/