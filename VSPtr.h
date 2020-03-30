#ifndef VSPOINTER_LIBRARY_H
#define VSPOINTER_LIBRARY_H
#include <cstddef>
#include <iostream>
#include <unistd.h>

using namespace std;

template <class T>

class VSPtr{
    T *ptr;
public: 
    //constructor
    explicit VSPtr(T *p = NULL) {
        ptr = p;
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

class GarbageCollector{

    public:
    static GarbageCollector& getInstance(){
        static GarbageCollector instance;
        return instance;
    }

    private: 
    GarbageCollector(){}
    GarbageCollector(GarbageCollector const&);
    void operator = (GarbageCollector const&);
    void thread();

    public:
    GarbageCollector(GarbageCollector const&) = delete;
    void operator = (GarbageCollector const&) = delete;


};

#endif //VSPOINTER_LIBRARY_H
