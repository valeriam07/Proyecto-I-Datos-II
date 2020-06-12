#ifndef VSPOINTER_LIBRARY_H
#define VSPOINTER_LIBRARY_H
#include <cstddef>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <fstream>
#include <sstream>
#include "../json.hpp"
#include "./clientsocket.h"

using json = nlohmann::json;
using namespace std;

static int VSPtrCount;

// ___________________________GARBAGE COLLECTOR_____________________________

class GarbageCollector
{

public:
    static GarbageCollector *getInstance();     //retorna el numero de instancias de un VSPtr
    void saveAddress(int VSPtrCount, int *ptr); // guardado del puntero
    static int *addess[10];                     //lista de direcciones
    string IDs[10];                             //lista de ID
    static int values[10];
    static int references[10];
    void generateID();
    string getID(int key);
    int *getAdress(int key);
    static void freeMemory();
    int* getAddressList(){
        return *addess;
    }
    void setValues(){

        for(int j = 0; j < VSPtrCount ; j++){
                GarbageCollector::values[j] = *(GarbageCollector::addess[j]);
            }
    }
    void sendData(){
        ifstream ifs("data.json");
        json datos;
        ifs >> datos;

        GarbageCollector::setValues();

        for(int i = 0; i< VSPtrCount; i++){
            const void * address = static_cast<const void*>(GarbageCollector::addess[0]);
            std::stringstream ss;
            ss << address;  
            std::string ptr = ss.str(); 
            
            datos["info"][i]["address"] = ptr;
            datos["info"][i]["ID"] = GarbageCollector::IDs[i];
            datos["info"][i]["value"] = GarbageCollector::values[i];
        }

        cout<< "JSON FILE: " << datos << endl;


    }

private:
    static GarbageCollector *instance;
    GarbageCollector();
};

GarbageCollector *GarbageCollector::instance = 0;
GarbageCollector *GarbageCollector ::getInstance()
{
    if (instance == 0)
    {
        instance = new GarbageCollector();
        if(getIfServer() == true){
            init_server();
        }
        
    }

    return instance;
}

GarbageCollector::GarbageCollector() 
{
    
};

int GarbageCollector::references[10];
int* GarbageCollector::addess[10];
int GarbageCollector::values[10];

//________________________________VSPOINTER__________________________________

template <class T>

class VSPtr
{
    T *ptr;

public:
    int key;
    int VSPReference;

    //constructor
    explicit VSPtr(T *p = NULL)
    {
        ptr = p; //ptr is the address
        GarbageCollector *g = GarbageCollector::getInstance();
        VSPtrCount++;
        cout << "VSPTR COUNT: " << VSPtrCount << endl;
        key = VSPtrCount - 1;
        g->saveAddress(VSPtrCount, ptr);
        g->generateID();
        g->references[key] = VSPReference;
        g->sendData();
    }

    ~VSPtr()
    {
        delete (ptr);
    }

    string ID;

    //Overloading deferencing operator
    T &operator*()
    {
        this->VSPReference++;
        return *ptr;
    }

    //Overloading arrow operator, members of T can be accessed like a
    //pointer
    T *operator->()
    {
        this->VSPReference++;
        return ptr;
    }

    VSPtr operator=(VSPtr ptr)
    {
        GarbageCollector *g = GarbageCollector::getInstance();
        g->setValues();

        for(int j = 0; j < VSPtrCount ; j++){
                cout <<"DATA (" << j << ") " << GarbageCollector::values[j] << endl;
            }
            
        ptr.VSPReference++;


        cout << "------ USING = OPERAND ------" << endl;
        cout << "ACTUAL ID: " << g->getID(this->key) << endl;
        cout << "ACTUAL DATA: " << GarbageCollector::values[this->key] << endl;

        g->IDs[this->key] = g->getID(ptr.key);        //reemplaza el id del elemento izquierdo por una copia del id del elemento derecho
        **this = *ptr;
        g->setValues();

        cout << "NEW ID: " << g->getID(this->key) << endl;
        cout << "NEW DATA: " << g->values[this->key] << endl;
    }
};

#endif //VSPOINTER_LIBRARY_H