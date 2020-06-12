#ifndef VSPOINTER_LIBRARY_H
#define VSPOINTER_LIBRARY_H
#include <cstddef>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <fstream>
#include <sstream>
#include "/home/valeria/Downloads/json-develop/single_include/nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

static int VSPtrCount;

// ___________________________GARBAGE COLLECTOR_____________________________

/**
 * @brief esta clase se encarga de liberar la memoria y almacenar la informacion de los VSPtr
 * 
 */
class GarbageCollector
{

public:
    static GarbageCollector *getInstance();     //retorna el numero de instancias de un VSPtr
    void saveAddress(int VSPtrCount, int *ptr); // guardado del puntero
    static int *addess[];                     //lista de direcciones
    string IDs[100];                             //lista de ID
    static int values[];
    static int references[];
    void generateID();
    string getID(int key);
    int *getAdress(int key);
    static void freeMemory();
    int* getAddressList(){
        return *addess;
    }

    /**
     * @brief asigna y guarda los valores de cada VSPtr en un array
     * 
     */
    void setValues(){

        for(int j = 0; j < VSPtrCount ; j++){
                GarbageCollector::values[j] = *(GarbageCollector::addess[j]);
            }
    }

    /**
     * @brief envia la informacion de los VSPtr creados por el usuario a un archivo .json
     * 
     */
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

/**
 * @brief singleton de la clase Garbage Collector
 * 
 * @return GarbageCollector* ::getInstance 
 */
GarbageCollector *GarbageCollector ::getInstance()
{
    if (instance == 0)
    {
        instance = new GarbageCollector();
    }

    return instance;
}

GarbageCollector::GarbageCollector() 
{
    
};

int GarbageCollector::references[100];
int* GarbageCollector::addess[100];
int GarbageCollector::values[100];

//________________________________VSPOINTER__________________________________

template <class T>

/**
 * @brief esta clase se encarga de operar los VSPtr
 * 
 */
class VSPtr
{
    T *ptr;

public:
    int key;
    int VSPReference;

    /**
     * @brief Construye nuevos objetos de tipo VSPtr
     * 
     * @param p 
     */
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
    /**
     * @brief destruye el objeto VSPtr
     * 
     */
    ~VSPtr()
    {
        delete (ptr);
    }

    string ID;

    /**
     * @brief sobrecarga del operador *
     * 
     * @return T&, el valor reservado por el objeto VSPtr
     */
    T &operator*()
    {
        this->VSPReference++;
        return *ptr;
    }

    /**
     * @brief sobrecarga del operador ->
     * 
     * @return T*, direccion en la memoria del VSPtr 
     */
    T *operator->()
    {
        this->VSPReference++;
        return ptr;
    }

    /**
     * @brief sobrecarga del operador =
     * 
     * @param ptr VSPtr al cual se iguala otro VSPtr
     * @return VSPtr con los respectivos cambios realizados
     */
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
        return this;
    }
};

#endif //VSPOINTER_LIBRARY_H
