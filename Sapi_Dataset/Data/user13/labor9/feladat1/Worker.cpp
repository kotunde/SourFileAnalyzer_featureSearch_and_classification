#include "Worker.h"

Worker::Worker(string first, string last, int bDate, string job):Person(first,last,bDate)
{
	this->job = job;
}

void Worker::print(ostream & out)
{
	 out << "(" << firstName << " " << lastName << ", " << birthDate << ", "<< job << ")" << endl;
}
