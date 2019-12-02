#ifndef LIST_H
#define LIST_H
#include <iostream>

class Container{/// a tarolo osztaly, a Manyi fele egyszeres listaban a Nodenak felel meg
private:
    long value;///figyelj a memoria szivargasra
public:
    static Container* CLOSING;///de nem engedi a kocsog annyat hogy ezt contra rakjam b+ (mert akkor borul a rendszer/elkepzeles...) ...miota nem lehet valaminek egy konstans erteket adni? WTF??
    Container* pre;
    Container* next;
    Container(){
        pre = Container::CLOSING;
        next = Container::CLOSING;
        value = 0;
    };
    Container(long);///kerdeses hogy kelljen
    Container(const Container*,const long);
    Container(const long, const Container*);
    Container(const Container*, const long, const Container*);
    Container(const Container&) = delete;
    Container(const Container&&) = delete;
    Container& operator=(const Container&) = delete;
    Container& operator=(const Container&&) = delete;
    ~Container();
    void Set(const long);
    long Get() const;
};
Container* Container::CLOSING = new Container();

///elore-hatra lancolt lista, de nem korbekotott. Az eleje es a vege mutasson a CLOSING (*kohoges* basszameg...) "constansra"

class List{
private:
    Container* First = Container::CLOSING;
    Container* Last = Container::CLOSING;
    unsigned Size;
public:
    List();
    List(const List&);
    List(const List&&);
    List(const unsigned, const long*);///tombbol epiti fel a listat
    ~List();
    List& operator=(const List&);
    List& operator=(const List&&);
    const bool operator==(const List&) const;
    const bool operator!=(const List&) const;
    long& operator[](const unsigned);///kezeld, dobj kivetelt!
    long operator[](const unsigned) const;///kezeld, dobj kivetelt!
    const unsigned size() const;
    const bool empty() const;
    const bool exists(const long) const;
    void remove(long);///kitorli az osszes eggyezest
    void push_front(long);
    void push_back(long);
    void pop_front();///kezeld, dobj kivetelt!
    void pop_back();///kezeld, dobj kivetelt!
    long front();///kezeld, dobj kivetelt!
    long back();///kezeld, dobj kivetelt!
    List& operator+=(const List&);///hozzafuzi a bal oldalhoz jobbrol a job oldalt
    List& operator+=(const List&&);/// pelda: a = b + c;
    friend List operator+(const List&, const List&);
    friend List operator+(const List&, const List&&);
    friend List operator+(const List&&, const List&);
    friend List operator+(const List&&, const List&&);
    friend std::istream& operator>>(std::istream&, List&);
    friend std::ostream& operator<<(std::ostream&, const List&);
};


#endif // LIST_H
