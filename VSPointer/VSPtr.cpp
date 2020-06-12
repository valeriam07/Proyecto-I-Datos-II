#include "VSPtr.h"
#include <iostream>
#include <fstream>
#include "clientsocket.h"

using namespace std;

/**
 * @brief metodo principal del Garbage Collector.
 * Libera la memoria de los VSPointer que no tienen ninguna referencia mediante un thead.
 * 
 */
void GarbageCollector :: freeMemory(){

    try{

        while(true){

            for(int i=0; i< VSPtrCount && GarbageCollector::references[i] != 0; i++) {

                if ((GarbageCollector::references[i] = 0)) {
                    delete GarbageCollector::addess[i];
                    cout << "ELIMINADO" << addess[i] << endl;
                }

                sleep(1000);
            }

        }
    }catch(std::exception const&){
            cout << "Error en el thread" << endl;
    }

}

/**
 * @brief Guarda las direcciones de los VSPtr en un array.
 * 
 * @param VSPtrCount numero de VSPtr actuales
 * @param ptr direccion del VSPtr por guardar
 */
void GarbageCollector :: saveAddress(int VSPtrCount, int* ptr){

    GarbageCollector::addess[VSPtrCount-1] = ptr;

    for(int i=0; i< VSPtrCount && GarbageCollector::addess[i] != 0; i++){

        cout << "ADDRESS (" << i << ") " << GarbageCollector::addess[i] << endl;
    }
    

    
}


/**
 * @brief Genera y guarda una identificacion para cada VSPtr creado
 * 
 */
void GarbageCollector :: generateID(){

    string ID = "VSPTR_" + to_string(VSPtrCount);
    GarbageCollector::IDs[VSPtrCount-1] = ID;

    for(int i=0; i< VSPtrCount && GarbageCollector::addess[i] != 0; i++){

        cout << "ID (" << i << ") " << GarbageCollector::IDs[i] << endl;
    }
    
    cout << "_________________________________"<< endl;

}

/**
 * @brief retorna la identificacion de un VSPtr mediante el uso de su respectiva llave
 * 
 * @param key llave del VSPtr
 * @return string 
 */
string GarbageCollector::getID(int key){
    return GarbageCollector::IDs[key];
}

/**
 * @brief retorna la direccion de memoria de un VSPtr mediante su respectiva llave
 * 
 * @param key llave del VSPtr
 * @return int* 
 */
int* GarbageCollector::getAdress(int key){
    return GarbageCollector::addess[key];
}
