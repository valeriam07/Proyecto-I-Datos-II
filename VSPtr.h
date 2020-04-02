#ifndef VSPOINTER_LIBRARY_H
#define VSPOINTER_LIBRARY_H
#include <cstddef>
#include <iostream>
#include <unistd.h>

using namespace std;

static int VSPtrCount;

class GarbageCollector{

public:
    static GarbageCollector* getInstance();
    void saveAddress(int VSPtrCount, int* ptr);
    int *addess[10];
    string IDs[10];
    void generateID();

private: 
    static GarbageCollector* instance;
    GarbageCollector();
    void thread();
    
    


};

GarbageCollector* GarbageCollector:: instance = 0;
GarbageCollector* GarbageCollector :: getInstance(){
     if(instance == 0){
            instance = new GarbageCollector();
        }

        return instance;
    
}

GarbageCollector::GarbageCollector(){}

template <class T>

class VSPtr{
    T *ptr;

public: 

    //constructor
    explicit VSPtr(T *p = NULL) {           //New()
        ptr = p;  //ptr is the address 
        GarbageCollector* g = GarbageCollector::getInstance();
        VSPtrCount++;
        cout << "VSPTR COUNT: " << VSPtrCount << endl;
        g->saveAddress(VSPtrCount, ptr);
        g->generateID();
        
    }

    ~VSPtr(){
        delete(ptr);
    }

    //Overloading deferencing operator 
    T & operator * (){
        return *ptr;
    }

    //Overloading arrow operator, members of T can be accessed like a 
    //pointer
    T * operator -> (){
        return ptr;
    }

    VSPtr operator = (VSPtr const c1){              //ARREGLAR
        if (typeid(VSPtr) == typeid(c1)){
                cout << "Son de tipo VSPtr" << endl;
        }
    }


};




#endif //VSPOINTER_LIBRARY_H
