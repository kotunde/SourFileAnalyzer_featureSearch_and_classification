#include <iostream>
#include "List.h"

using namespace std;

int main(){
    List list;
    for(int i=0; i<10; ++i){
        list.insertFirst( i );
    }
    cout<<"List [ ";
    for(List::iterator it = list.begin(); it != list.end(); ++it){
        cout<<*it<<", ";
    }
    cout<<"] "<<endl;

    {
        List roka;
        cout << "A kicsi roka feje kezdetben " << (roka.empty()?"empty":"something") << endl;
        cout << "Tanul a roka: ";
        for(int i=0; i<5; ++i)
            roka.insertFirst(i+1);
        roka.print();
        cout << "\nButul a roka: ";
        int tmp;
        string mod;
        while(roka.size())
        {
            cin >> tmp >> mod;
            if(mod == "E") roka.remove(tmp,List::DeleteFlag::EQUAL);
            if(mod == "L") roka.remove(tmp,List::DeleteFlag::LESS);
            if(mod == "G") roka.remove(tmp,List::DeleteFlag::GREATER);
            roka.print();
        }
        roka.print();
        cout << "\nVan-e a rokaban 1... " << (roka.exists(1) ?"ha persze hogy igen!":"dehogy is!") << endl;
        cout << "A roka nagyon nagy, egeszen: " << roka.size() << endl;
        cout << "A roka elpusztul :( " << endl;
    }

    return 0;
}
