#include <napi.h>
#include <cstddef>
#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;



class GarbageCollector {
 public:
  GarbageCollector(double value);
   double getValue();
  double add(double toAdd);
 private:
  double value_;
};




/*
static int VSPtrCount;

// ___________________________GARBAGE COLLECTOR_____________________________

class GarbageCollector{
    
public:
    static GarbageCollector* getInstance();     //retorna el numero de instancias de un VSPtr
    void saveAddress(int VSPtrCount, int* ptr);     // guardado del puntero
    int *addess[10];        //lista de direcciones
    string IDs[10];         //lista de ID
    int references[10];
    void generateID();
    string getID(int key);
    int* getAdress(int key);
    thread freeMemory();

    
    
    

private: 
    static GarbageCollector* instance;
    GarbageCollector();
    
    
};



GarbageCollector* GarbageCollector:: instance = 0;
GarbageCollector* GarbageCollector :: getInstance(){
     if(instance == 0){
            instance = new GarbageCollector();
        }

        return instance;
    
}

GarbageCollector::GarbageCollector(){}

//________________________________VSPOINTER__________________________________

template <class T>

class VSPtr{
    T *ptr;

public: 
    int key;
    int VSPReference;

    //constructor
    explicit VSPtr(T *p = NULL) {          
        ptr = p;  //ptr is the address 
        GarbageCollector* g = GarbageCollector::getInstance();
        VSPtrCount++;
        cout << "VSPTR COUNT: " << VSPtrCount << endl;
        key = VSPtrCount-1;
        g->saveAddress(VSPtrCount, ptr);
        g->generateID();
        g->references[key] = VSPReference;
        //thread t(g->freeMemory);          //ARREGLAR
        
    }

    ~VSPtr(){
        delete(ptr);
    }

    string ID;

    //Overloading deferencing operator 
    T & operator * (){
      this->VSPReference ++;
      return *ptr;
    }

    //Overloading arrow operator, members of T can be accessed like a 
    //pointer
    T * operator -> (){
      this->VSPReference ++;
      return ptr;
    }


    VSPtr operator = (VSPtr ptr){  
      //this->references ++;      //ARREGLAR A QUIEN SE LE SUMA LA REFERENCIA?
      ptr.VSPReference ++;

      GarbageCollector* g = GarbageCollector::getInstance();

      cout << "------ USING = OPERAND ------" << endl;
      cout << "ACTUAL ID: " << g->getID(this->key) << endl;
      cout << "ACTUAL ADDRESS: " << g->getAdress(this->key) << "\n" << endl;

      g->IDs[this->key] = g->getID(ptr.key); //reemplaza el id del elemento izquierdo por una copia del id del elemento derecho
      g->addess[this->key] = g->getAdress(ptr.key); //reemplaza el address del elemento izquierdo por una copia del address del elemento derecho

      cout << "NEW ID: " << g->getID(this->key) << endl;
      cout << "NEW ADDRESS: " << g->getAdress(this->key) << endl;


    }

};




#endif //VSPOINTER_LIBRARY_H

*/



