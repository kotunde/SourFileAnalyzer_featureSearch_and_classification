#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include <vector>
#include <Alkalmazott.h>


using namespace std;

class Manager : public Alkalmazott
{
public:
    // Manager();
    Manager(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor):
        Alkalmazott(vezetekNev,keresztNev,szuletesiEv,munkakor)
    {

    }
    void addAlkalmazott (Alkalmazott *);
    void deleteAlkalmazott (Alkalmazott *);
    int beosztottakSzama () const;
    void print(ostream & os) const;

protected:
    vector <Alkalmazott *> v;
};

#endif // MANAGER_H
