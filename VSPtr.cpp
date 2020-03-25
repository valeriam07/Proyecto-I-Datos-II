#include "VSPtr.h"
#include <iostream>

using namespace std;

int main(){
    //VSPtr<int> myPtr = VSPtr<int> ::New();
    VSPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr << endl;
    return 0;

}