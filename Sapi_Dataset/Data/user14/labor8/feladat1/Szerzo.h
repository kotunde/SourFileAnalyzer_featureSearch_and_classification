//
// Created by attila on 12.11.2018.
//

#ifndef SZERZO_SZERZO_H
#define SZERZO_SZERZO_H


#include <string>

using namespace std;

class Szerzo{
private:
    string vezeteknev;
    std::string keresztnev;
public:
    Szerzo(string vnev, string knev);
    string getVezeteknev() const;
    string getKeresztnev() const;
    friend ostream & operator<<(ostream& os, const Szerzo& sz);

};



#endif //SZERZO_SZERZO_H
