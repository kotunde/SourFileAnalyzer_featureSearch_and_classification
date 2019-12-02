#ifndef LIST_H_own
#define LIST_H_own
#include <iostream>

///Nem kell megijedni, csak ugyesen! A jatekszabalyok ugyan azok mint a tanarnonel (a felugyeletet a lelkiismeretetek latja el ;) ).

template<class Tc> class Container{/// a tarolo osztaly, a Manyi fele egyszeres listaban a Nodenak felel meg
private:
    Tc* value;///figyelj a memoria szivargasra
public:
    static Container<Tc>* CLOSING;///de nem engedi a kocsog annyat hogy ezt contra rakjam b+ (mert akkor borul a rendszer/elkepzeles...) ...miota nem lehet valaminek egy konstans erteket adni? WTF??
    Container<Tc>* pre;
    Container<Tc>* next;
    Container(){
        ///PELDA
        pre = Container::CLOSING;
        next = Container::CLOSING;
        value = new Tc();
    };
    Container(Tc&);///kerdeses hogy kelljen
    Container(const Container<Tc>*,const Tc&);
    Container(const Tc&, const Container<Tc>*);
    Container(const Container<Tc>*, const Tc&, const Container<Tc>*);
    Container(const Container&) = delete;
    Container(const Container&&) = delete;
    Container& operator=(const Container&) = delete;
    Container& operator=(const Container&&) = delete;
    ~Container();
    void Set(const Tc&);
    Tc& Get() const;
};
template<class Tc> Container<Tc>* Container<Tc>::CLOSING = new Container<Tc>();
template<class Tc> Container<Tc>::Container(Tc& data){
    ///MODOSITSD
};
template<class Tc> Container<Tc>::Container(const Container<Tc>* pre, const Tc& data){
    ///MODOSITSD
};
template<class Tc> Container<Tc>::Container(const Tc& data, const Container<Tc>* next){
    ///MODOSITSD
};
template<class Tc> Container<Tc>::Container(const Container<Tc>* pre, const Tc& data, const Container<Tc>* next){
    ///MODOSITSD
};
template<class Tc> Container<Tc>::~Container(){
    ///MODOSITSD
};
template<class Tc> void Container<Tc>::Set(const Tc& newdata){
    ///MODOSITSD
};
template<class Tc> Tc& Container<Tc>::Get() const{
    ///MODOSITSD
};

///elore-hatra lancolt lista, de nem korbekotott. Az eleje es a vege mutasson a CLOSING (*kohoges* basszameg...) "constansra"

template<class T> class List{
private:
    Container<T>* First = Container<T>::CLOSING;
    Container<T>* Last = Container<T>::CLOSING;
    unsigned Size;
public:
    List();
    List(const List<T>&);
    List(const List<T>&&);
    List(const unsigned, const T*);///tombbol epiti fel a listat
    ~List();
    List<T>& operator=(const List<T>&);
    List<T>& operator=(const List<T>&&);
    const bool operator==(const List<T>&) const;
    const bool operator!=(const List<T>&) const;
    T& operator[](const unsigned);///kezeld, dobj kivetelt!
    const T& operator[](const unsigned) const;///kezeld, dobj kivetelt!
    const unsigned size() const;
    const bool empty() const;
    const bool exists(const T&) const;
    void push_front(T&);
    void push_back(T&);
    void pop_front();///kezeld, dobj kivetelt!
    void pop_back();///kezeld, dobj kivetelt!
    T& front();///kezeld, dobj kivetelt!
    T& back();///kezeld, dobj kivetelt!
    List<T>& operator+=(const List<T>&);///hozzafuzi a bal oldalhoz jobbrol a job oldalt
    List<T>& operator+=(const List<T>&&);/// pelda: a = b + c;
    template<class _T> friend List<_T> operator+(const List<_T>&, const List<_T>&);
    template<class _T> friend List<_T> operator+(const List<_T>&, const List<_T>&&);
    template<class _T> friend List<_T> operator+(const List<_T>&&, const List<_T>&);
    template<class _T> friend List<_T> operator+(const List<_T>&&, const List<_T>&&);
    template<class _T> friend std::istream& operator>>(std::istream&, List<_T>&);
    template<class _T> friend std::ostream& operator<<(std::ostream&, const List<_T>&);
};

template<class T> List<T>::List(){
    ///MODOSITSD
}
template<class T> List<T>::List(const List<T>& other){
    ///MODOSITSD
};
template<class T> List<T>::List(const List<T>&& source){
    ///MODOSITSD
};
template<class T> List<T>::List(const unsigned n, const T* datas){
    ///MODOSITSD
};
template<class T> List<T>::~List(){
    ///MODOSITSD
};
template<class T> List<T>& List<T>::operator=(const List<T>& other){
    ///MODOSITSD
};
template<class T> List<T>& List<T>::operator=(const List<T>&& source){
    ///MODOSITSD
};
template<class T> const bool List<T>::operator==(const List<T>& other) const{
    ///MODOSITSD
};
template<class T> const bool List<T>::operator!=(const List<T>& other) const{
    ///MODOSITSD
};
template<class T> T& List<T>::operator[](const unsigned idx){
    ///MODOSITSD
};
template<class T> const T& List<T>::operator[](const unsigned idx) const{
    ///MODOSITSD
};
template<class T> const unsigned List<T>::size() const{
    ///MODOSITSD
};
template<class T> const bool List<T>::empty() const{
    ///MODOSITSD
};
template<class T> const bool List<T>::exists(const T& data) const{
    ///MODOSITSD
};
template<class T> void List<T>::push_front(T& data){
    ///MODOSITSD
};
template<class T> void List<T>::push_back(T& data){
    ///MODOSITSD
};
template<class T> void List<T>::pop_front(){
    ///MODOSITSD
};
template<class T> void List<T>::pop_back(){
    ///MODOSITSD
};
template<class T> T& List<T>::front(){
    ///MODOSITSD
};
template<class T> T& List<T>::back(){
    ///MODOSITSD
};
template<class T> List<T>& List<T>::operator+=(const List<T>& other){
    ///MODOSITSD
};
template<class T> List<T>& List<T>::operator+=(const List<T>&& source){
    ///MODOSITSD
};
template<class T> List<T> operator+(const List<T>& x, const List<T>& y){
    ///MODOSITSD
};
template<class T> List<T> operator+(const List<T>& x, const List<T>&& tmp){
    ///MODOSITSD
};
template<class T> List<T> operator+(const List<T>&& tmp, const List<T>& y){
    ///MODOSITSD
};
template<class T> List<T> operator+(const List<T>&& tmp_x, const List<T>&& tmp_y){
    ///MODOSITSD
};
template<class T> std::istream& operator>>(std::istream& is, List<T>& list){
    ///MODOSITSD
};
template<class T> std::ostream& operator<<(std::ostream& os, const List<T>& list){
    ///MODOSITSD
};


#endif // LIST_H_own
