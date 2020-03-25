#ifndef VSPOINTER_LIBRARY_H
#define VSPOINTER_LIBRARY_H
#include <cstddef>

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


};

#endif //VSPOINTER_LIBRARY_H
