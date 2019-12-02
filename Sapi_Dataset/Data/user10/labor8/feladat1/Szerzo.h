#ifndef SZERZO_H
#define SZERZO_H

#include <string>
#include <ostream>

class Szerzo{
private:
    std::string vezeteknev;
    std::string keresztnev;
public:
    Szerzo(std::string,std::string);
    std::string vezeteknev_get() const;
    std::string keresztnev_get() const;
    friend std::ostream& operator<<(std::ostream&, const Szerzo&);
};

#endif // SZERZO_H_INCLUDED
