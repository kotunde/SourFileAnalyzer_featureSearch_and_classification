#include "Alkalmazott.h"

void Alkalmazott::print(ostream & os) const
{
	os << this->vezetekNev << " " << this->keresztNev << ", " << this->szuletesiEv << ", " << this->munkakor;
}
