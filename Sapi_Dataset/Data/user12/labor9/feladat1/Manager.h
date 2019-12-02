#include "Alkalmazott.h"
#include <vector>
#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
class Manager:Alkalmazott{
private:
    vector<Alkalmazott*> beosztottak;
public:
  Manager(string, string, int, string);
  void addAlkalmazott(Alkalmazott *);
  void deleteAlkalmazott(Alkalmazott *);
  int beosztottakSzama();
  void print(ostream&);
};


#endif // MANAGER_H_INCLUDED
