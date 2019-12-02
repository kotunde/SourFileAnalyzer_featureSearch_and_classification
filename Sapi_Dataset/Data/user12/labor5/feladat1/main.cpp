#include <iostream>
#include "List.h"

int main()
{
    List a;
    a.insertFirst(4);
    a.insertFirst(2);
    a.insertFirst(7);
    a.insertFirst(9);
    a.insertFirst(3);
    a.print();
    if(a.exists(3)){
        std::cout << "\nLetezik!\n";
    }
    else{
        std::cout << "\nNem letezik!\n";
    }
    return 0;
}
