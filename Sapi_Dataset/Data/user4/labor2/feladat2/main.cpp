#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char** argv)
{
    vector<string> v;
    cout<<"Irjon be karakterlancokat vegjelig (Unix: Ctrl D, Windows: Ctrl Z): "<<endl;
    copy(istream_iterator<string>(cin),istream_iterator<string>(), back_inserter(v));
    sort(v.begin(), v.end());
    cout<<"A kimenet:"<<endl;
    copy( v.begin(), v.end(), ostream_iterator<string>(cout,"\n"));
    return 0;
}
