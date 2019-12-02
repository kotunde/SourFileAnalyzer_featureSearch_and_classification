#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List l; l.insertFirst(5); l.insertFirst(10); l.insertFirst(20);
    l.print(); cout << "A lista merete: " << l.size() << endl;

    if (l.empty() == true){cout << "A lista ures!" << endl;}
    else {cout << "A lista nem ures!" << endl;}

    int x = 5;
    if (l.exists(x) == true){cout << "Az x = " << x << " eleme a listanak!" << endl;}
    else {cout << "Az x = " << x << " nem eleme a listanak!" << endl;}

    l.remove(10,List::DeleteFlag::GREATER);
    cout << "Torles utan: "; l.print();
    return 0;
}
