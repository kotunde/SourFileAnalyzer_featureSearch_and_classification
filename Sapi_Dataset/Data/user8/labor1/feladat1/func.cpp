#include "func.h"

/*
Készítsen függvényt, amely meghatározza egy pozitív egész szám egyes bitjeinek a számát.
int countBits(int number);
A main függvényben írassa ki 0-tól 127-ig az egész számok egyes bitjeinek számát. Milyen
szabályosságot lehet megfigyelni?
*/

int countBits(int number) {
    int darab;
    darab = 0;
    while(number!=0) {

        if((number & 1) == 1) {
            darab = darab + 1;
        }
        number = number >> 1;
    }
    return darab;
}

/*
Készítsen függvényt, amely beállítja egy egész szám adott sorszámú bitjét 1-re. A sorszám 0 és 31
közötti egész szám, a 0-ás a legkisebb helyértékű bitet jelenti, a 31-es a legnagyobbat. Amennyiben
a sorszám nem megfelelő, térítsen vissza 0-át, ellenkező esetben térítsen vissza 1-et.
int setBit(int& number, int order);
*/

int setBit(int& number, int order) {
    if(order > 31 || order < 0) {
        return 0;
    }
    number |= 1UL << order;
    return 1;
}

/*
Készítsen függvényt, amely meghatározza egy valós számokból álló tömb átlagát. Üres tömb
esetén térítse vissza a NAN-t (Not-A-Number, #include <cmath>).
Hívja meg a függvényt a main metódusból, ellenőrizze ennek helyességét.
double mean(double array[], int numElements);
*/

double mean(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }
    double mean = 0;
    for(int i=0; i<=numElements; i++) {
        mean += array[i];
    }
    double result;
    result = (mean/(double)(numElements+1));
    return result;
}

/*
Készítsen függvényt, amely meghatározza egy valós számokból álló tömb szórását (standard
deviation). Üres tömb esetén térítsen vissza NAN-t. Hívja meg a függvényt a main metódusból,
ellenőrizze ennek helyességét.
double stddev(double array[], int numElements)
*/

double stddev(double array[], int numElements) {
    double atlag;

    if (numElements == 0) {
        return NAN;
    }
    atlag = mean(array, numElements);
    double tav = 0;
    for (int i=0; i<=numElements; ++i) {
        double k = array[i]-atlag;
        tav+=k*k;
    }
    return sqrt(tav / (numElements+1));
}

/*
Készítsen függvényt, amely meghatározza egy valós számokból álló tömb két legnagyobb elemét.
Üres tömb esetén térítsen vissza egy olyan kételemű tömböt, amely mindkét eleme NAN (Not-ANumber).
Egyetlen elemet tartalmazó bemeneti tömb esetén térítsen vissza egy kételemű tömböt,
amelynek mindkét eleme azonos az egyetlen elemmel. A visszatérített kételemű tömb elemei
legyenek növekvő sorrendben.
Hívja meg a függvényt a main metódusból, ellenőrizze ennek helyességét.
double * max2(double array[], int numElements);
*/

double * max2(double array[], int numElements) {
    double max[] = {NAN, NAN};

    if (numElements == 0) {
        return max;
    }
    if (numElements == 1) {
        max[0] = array[0];
        max[1] = array[0];
        return max;
    } else {

        double maxi = array[0];
        double maxi2 = array[1];
        for (int i = 2; i < numElements; ++i) {
            if (array[i] > maxi) {
                maxi = array[i];
                if (maxi > maxi2) {
                    double x;
                    x = maxi2;
                    maxi2 = maxi;
                    maxi = x;

                }
            }
        }
        max[0] = maxi;
        max[1] = maxi2;

    }
    return max;
}

/*
Készítsen függvényt amely nagybetűsíti egy szöveg szavait (a szöveg első betűje, illetve szóköz
utáni első betű). A szó összes többi betűjét alakítsa kisbetűssé.
 string capitalizeWords(string text);
Olvasson be sorokat végjelig a standard bementről majd minden sorra hívja meg az előző függvényt
és írassa ki az eredményt a standard kimenetre.
*/


std::string capitalizeWords(std::string text) {
    bool check;
    check=true;
    for(signed int i=0; i<(signed)text.length(); i++) {
        if(text.at(i)==' ') {
            check= true;
            continue;
        }
        // ha szokoz

        if(check == true && (text.at(i)>='a' && text.at(i)<='z')) {
            text.at(i) = text.at(i) + ('A'-'a');
            check = false;
            continue;
            // nagybetusites, csak ha kis betuvel talalkozik
        }

        if(check == true && (text.at(i)>='A' && text.at(i)<='Z')) {
            // ha szokoz van, de a szoveg mar nagybetuvel rendelkezik
            check = false;
            continue;
        }

        if(!((text.at(i)>='a' && text.at(i)<='z') || (text.at(i)>='A' && text.at(i)<='Z')) ) {
            // ha barmi mas karakter
            check = false;
            continue;
        }

        if(text.at(i) >='A' && text.at(i)<='Z') {
            // kisbetusites
            text.at(i) = text.at(i)-('A'-'a');
            check = false;
        }

    }
    return text;
}

/*
Készítsen függvényt, amely kódolja egy szöveg karaktereit a következőképpen:
minden betű karaktert ábécé sorrendben a következő betűvel helyettesít ('a' → 'b', 'b' → 'c', …,'z' →
'a'). Ugyanezt a kódolást végzi kisbetűkre is. A nem betű karakterek változatlanul maradnak. A
függvény térítse vissza a kódolt szöveget.
string code(string text);Készítse el a dekódoló függvényt is, majd ellenőrizze
mindkettő helyességét
*/

std::string code(std::string text) {

    for(signed int i=0; i<(signed)text.length(); i++) {
        if(!((text.at(i)>='a' && text.at(i)<='z') || (text.at(i)>='A' && text.at(i)<='Z')) ) {
            // ha barmi mas karakter atlepi
            continue;
        }

        if(text.at(i)=='z') {
            text.at(i) = text.at(i) - ('z'-'a');
            continue;
            // visszaallitas
        }

        if(text.at(i) =='Z') {
            // visszaallitas
            text.at(i) = text.at(i)-('Z'-'A');
            continue;

        }

        if(text.at(i)>='a' && text.at(i)<'z') {
            text.at(i) = (char)(text.at(i) + 1);
            continue;
            // nagybetuk
        }


        if(text.at(i)>='A' && text.at(i)<'Z') {
            text.at(i) = text.at(i) + 1;
            continue;
        }

    }
    return text;
}

std::string decode(std::string text) {

    for(signed int i=0; i<(signed)text.length(); i++) {
        if(!((text.at(i)>='a' && text.at(i)<='z') || (text.at(i)>='A' && text.at(i)<='Z')) ) {
            // ha barmi mas karakter atlepi
            continue;
        }

        if(text.at(i)=='a') {
            text.at(i) = text.at(i) + ('z'-'a');
            continue;
            // visszaallitas
        }

        if(text.at(i) =='A') {
            // visszaallitas
            text.at(i) = text.at(i)+('Z'-'a');
            continue;

        }

        if(text.at(i)>'a' && text.at(i)<='z') {
            text.at(i) = (char)(text.at(i) - 1);
            continue;
            // nagybetuk
        }


        if(text.at(i)>'A' && text.at(i)<='Z') {
            text.at(i) = text.at(i) - 1;
            continue;
        }

    }
    return text;
}

/*
Készítsen daraboló függvényt, amely szavakra bont egy megadott szöveget. A szavak között a
következő elválasztó karakterek szerepelhetnek: szóköz, tabulátor, vessző, pont, kérdőjel és
felkiáltó jel. A szavakat írassa ki a standard kimenetre. A daraboló függvény térítse vissza a szavak
számát!
 int splitText(string text)
*/

int splitText(std::string text) {

    std::cout<<"A feldarabolt szavak: ";
    char *cstr = new char[text.length() + 1];
    strcpy(cstr, text.c_str());
    int i=0;
    char * pch;
    pch = strtok (cstr," ,.-!?    ");
    while (pch != NULL) {
        std::cout<<pch<<"\t";
        pch = strtok (NULL, " ,.-!?    ");
        i++;
    }

    delete [] cstr;
    std::cout<<std::endl;
    return i;
}

/*
Készítsen daraboló függvényt, amely egységekre bont egy vesszővel elválasztott szöveget (CSV
állomány sora). A függvény visszatéríti az egységek dinamikus tömbjét.
 vector<string> splitCSVLine(string text)
 */

// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}
// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}
// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}


std::vector<std::string> splitCSVLine(std::string text) {
    //std::string text = "Alma , Korte , Szilva , Eper";
    std::vector<std::string> words;
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    int counter = 0;
    unsigned int original = text.length();
    while (true) {
        if((pos = text.find(delimiter)) == std::string::npos) {
                // ha a szo vegen vagyunk
            if(text.length()==0) {
                //ha az utolso veletlenul vesszo lenne, ne keruljon a vektorba
                break;
            }
            text=trim(text);
            words.push_back(text);
            break;
        }
        if((pos == 0 && text.length()== original)){
            // ha az eleje vesszo
            text.erase(0, pos + delimiter.length());
            original = text.length();
        }
        if(pos > 0) {
            //normal esetben
            token = text.substr(0, pos);
            // szo levalasztasa
            token = trim(token);
            if(token!= ""){
                //ha space van a ket vesszo kozt, ne keruljon a vektorba
                words.push_back(token);
            }


            text.erase(0, pos + delimiter.length());
            original = text.length();
            //torles magat a szot + az elvalasztot
            counter++;
        }
    }
    return words;

}


