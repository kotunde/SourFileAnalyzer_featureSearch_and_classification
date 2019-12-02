#include "employee.h"

Alkalmazott::Alkalmazott(string vn, string kn, int birth, string jobs): Szemely(vn, kn, birth), munkakor(jobs){}

void Alkalmazott::print(ostream& os) const
{
    os<<vezetekNev<<" "<<keresztNev<<", "<<szuletesiEv<<", "<<munkakor;
}


