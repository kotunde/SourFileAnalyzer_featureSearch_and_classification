#ifndef LIST_H
#define LIST_H

class List{
private:
    struct Node{
        int value;
        Node* next;
        Node(int v, Node* n) : value(v), next(n){}
    };
public:
    List();
    List(const List&) = delete;
    List& operator=(const List&) = delete;
    ~List();

    bool exists(int d) const;
    int size() const;
    bool empty() const;
    void insertFirst(int d);
    enum class DeleteFlag {LESS, EQUAL, GREATER};
    void remove(int d, DeleteFlag df = DeleteFlag::EQUAL);
    void print() const;

    class iterator{
    private:
        List::Node* data_ptr;
    public:
        iterator(){ data_ptr = nullptr; };
        iterator(Node* ini) { data_ptr = ini; };
        iterator(const iterator& it){ data_ptr = it.data_ptr; };
        bool operator==(const iterator& other){ return data_ptr == other.data_ptr; };
        bool operator!=(const iterator& other){ return data_ptr != other.data_ptr; };
        void operator++(){ data_ptr = data_ptr->next; };
        void operator++(int){ data_ptr = data_ptr->next; };
        int& operator*(){ return data_ptr->value; };
    };

    List::iterator begin(){ return List::iterator(first); };
    List::iterator end(){ return List::iterator(nullptr); };

private:
    int nodeCounter{0};
    Node* first;
};
#endif /* LIST_H */
