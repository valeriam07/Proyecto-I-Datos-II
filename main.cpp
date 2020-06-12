
#include "./VSPointer/VSPtr.cpp"
#include <iostream>
#include <fstream>

int main(){
	cout << "hola" << endl;
    GarbageCollector *g = GarbageCollector::getInstance();
    //thread t(g->freeMemory);
    //t.join();
 
    VSPtr<int> ptr(new int());
    *ptr = 20;
    VSPtr<int> ptr2(new int());
    *ptr2 = 30;
    //ptr = ptr2;
    //g->sendData();
    
    return 0;


}