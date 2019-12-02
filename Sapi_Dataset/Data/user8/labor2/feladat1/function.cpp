#include "Function.h"

double distance(const Pont& p1, const Pont& p2) {
    double a,b;
    a = p1.getX() - p2.getX();
    b = p1.getY() - p2.getY();
    return sqrt(a*a + b*b);
}

bool isSquare (const Pont& a, const Pont& b, const Pont&c, const Pont& d) {
    if(distance(a,c)!=distance(b,d)) {
        return false;
    }
    if(distance(a,b)!=distance(c,d)) {
        return false;
    }
    if(distance(a,d)!=distance(b,c)) {
        return false;
    }
    if(distance(a,d)) {
        // ha NEM nulla az oldal hossza
        return true;
    } else {
        return false;
    }

}

bool matrix[2001][2001];

void initiate() {
    matrix[N][N] = false;
}

void generate_set() {

    initiate();
    std::vector<Pont> pontok;
    int i=0, x, y;
    srand(time(0));
    while (i<N) {
        x = rand() % (2000 - 0 +1);
        y = rand() % (2000 - 0 +1);
        //cout<<x<<"-x y-"<<y;
        if ( !matrix[x][y] ) {
            pontok.push_back(Pont(x,y));
            matrix[x][y] = true;
            ++i;
            //if(i%1000==1)cout<<" i:"<<i<<" ";
        }
    }
    cout<<"\nA generalt pontok:"<<endl;
    print(pontok);
    cout<<endl;
    cout<<"A rendezett pontok X szerint:"<<endl;
    sortByX(pontok);

    cout<<endl;
//
//    Pont* a = &pontok[0];
//    int n = pontok.size();
//    cout<<"A legkisebb  "<< closest(a, n);

    cout<<"Origohoz a legtavolabbi 10 pont:\n";
    furthestOrigin(pontok);
    cout<<endl;
    cout<<"A legtavolabbi es legkozelebbi pontpar:"<<endl;
    minMaxDistance(pontok);
    cout<<endl;
}

void print(vector<Pont> pontok) {
    for (auto& x : pontok) {
        cout<<"("<<x.getX()<<", "<<x.getY()<<")"<<endl;
    }
}

void sortByX(vector<Pont> pontok) {
    sort(pontok.begin(),pontok.end(),EntityComp(1));
    // 1 X szerint, 2 Y szerint
    print(pontok);
}

//////////// origohoz a 10 legtavolabbi pont //////////
void furthestOrigin(vector<Pont> pontok) {
    // javithato rendezett mappes beszurassal - key szerinti
    map<double, Pont, greater<double>> top10;
    vector<double> dist;
    Pont Origin{0,0};// = new Pont(0,0);
    double d;
    for(int i=0; i<pontok.size(); i++) {
        d = distance(Origin, pontok[i]);
        dist.push_back(d);
        top10.insert(pair<double, Pont>(d, pontok[i]));
    }
    int j=0;
//    for (std::map<double, Pont>::iterator i = top10.begin(); i != top10.end() && j<10 ; i++, j++) {
//
//        cout<<"("<<i->second.getX()<<", "<<i->second.getY()<<")"<<endl;
//    }
    /// rendezett mappel...

    for (std::map<double, Pont>::iterator i = top10.begin(); i != top10.end() && j<10 ; i++, j++)
    cout<<"("<<i->second.getX()<<", "<<i->second.getY()<<")"<<endl;


//    sort(dist.begin(),dist.end());
//    double key = 0;
//    for(int j = dist.size(); j>dist.size()-10; j--) {
//        key = dist[j];
//        cout<<"("<<(top10.find(key))->second.getX()<<", "<<(top10.find(key))->second.getY()<<")"<<endl;
//    }
}

/////// legtavolabbi es legkozelebbi pontpar /////

void minMaxDistance(vector<Pont> pontok) {
    vector<double> dist;
    double d;
    double minim = distance(pontok[0], pontok[1]);
    double maxim = 0;
    Pont maxp1, maxp2, minp1, minp2;
    for(int i=0; i<pontok.size()-1; i++) {
        for(int j =i+1; j<pontok.size(); j++) {
            d = distance(pontok[i], pontok[j]);
            if(d<minim) {
                minp1 = pontok[i];
                minp2 = pontok[j];
                minim = d;
            } else if(d>maxim) {
                maxp1 = pontok[i];
                maxp2 = pontok[j];
                maxim = d;
            }
        }

    }

    cout<<"\tMax tavolsagra, "<<maxim<<" vannak a pontok: "<<maxp1.getX()<<", "<<maxp1.getY()<< " es "<<maxp2.getX()<<", "<<maxp2.getY()<<endl;
    cout<<"\tMin tavolsagra, "<<minim<<" vannak a pontok: "<<minp1.getX()<<", "<<minp1.getY()<< " es "<<minp2.getX()<<", "<<minp2.getY()<<endl;
}

/////////////////////////////

int compareX(const void* a, const void* b) {
    Pont *p1 = (Pont *)a,  *p2 = (Pont *)b;
    return (p1->getX() - p2->getX());
}
// Needed to sort array of Ponts according to Y coordinate
int compareY(const void* a, const void* b) {
    Pont *p1 = (Pont *)a,   *p2 = (Pont *)b;
    return (p1->getY() - p2->getY());
}


// A Brute Force method to return the smallest distance between two Ponts
// in P[] of size n
float bruteForce(Pont P[], int n) {
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (distance(P[i], P[j]) < min)
                min = distance(P[i], P[j]);
    return min;
}

// A utility function to find minimum of two float values
float min(float x, float y) {
    return (x < y)? x : y;
}


// A utility function to find the distance beween the closest Ponts of
// strip of given size. All Ponts in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(Pont strip[], int size, float d) {
    float min = d; // Initialize the minimum distance as d

    qsort(strip, size, sizeof(Pont), compareY);

    // Pick all Ponts one by one and try the next Ponts till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].getY() - strip[i].getY()) < min; ++j)
            if (distance(strip[i],strip[j]) < min)
                min = distance(strip[i], strip[j]);

    return min;
}

// A recursive function to find the smallest distance. The array P contains
// all Ponts sorted according to x coordinate
float closestUtil(Pont P[], int n) {
    // If there are 2 or 3 Ponts, then use brute force
    if (n <= 3)
        return bruteForce(P, n);

    // Find the middle Pont
    int mid = n/2;
    Pont midPont = P[mid];

    // Consider the vertical line passing through the middle Pont
    // calculate the smallest distance dl on left of middle Pont and
    // dr on right side
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n-mid);

    // Find the smaller of two distances
    float d = min(dl, dr);

    // Build an array strip[] that contains Ponts close (closer than d)
    // to the line passing through the middle Pont
    Pont strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].getX() - midPont.getX()) < d)
            strip[j] = P[i], j++;

    // Find the closest Ponts in strip. Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}

// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
float closest(Pont P[], int n) {

    qsort(P, n, sizeof(Pont), compareX);

    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(P, n);
}



