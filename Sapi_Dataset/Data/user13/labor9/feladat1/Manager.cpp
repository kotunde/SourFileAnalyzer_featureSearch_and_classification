#include "Manager.h"

Manager::Manager(string first, string last, int bDate, string job):Worker(first,last,bDate,job)
{
}

void Manager::addSubaltern(Worker * who)
{
	this->subaltern.push_back(who);
}

void Manager::deleteSubaltern(Worker * who)
{
	for (int i = 0; i < subaltern.size(); ++i) {
		if (this->subaltern[i] = who) {
			this->subaltern.pop_back();
		}
		else { throw out_of_range("no such worker"); }
	}
}

int Manager::nrOfSubalterns() const
{
	return subaltern.size();
}

void Manager::print(ostream & out)
{
	for (int i = 0; i < subaltern.size(); ++i) {
		out << subaltern[i];
	}
}
