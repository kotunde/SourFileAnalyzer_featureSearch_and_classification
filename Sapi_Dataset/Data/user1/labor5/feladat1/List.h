#ifndef LIST_H
#define LIST_H
class List {
public:
     List();
    ~List();
     bool exists(int d) const;
     int size() const;
     bool empty() const;
     void insertFirst(int d);
     /* removes the first element less than/equal to/greater than d,
     depending on the value of df. Does nothing if there is no value
     to remove. The enum values are accessed with List::DeleteFlag::LESS,
     ..., outside the class */

     enum class DeleteFlag {
     LESS, EQUAL, GREATER
     };
     void remove(int d, DeleteFlag df = DeleteFlag::EQUAL);

     void print() const;

     List(const List&) = delete;
     List& operator=(const List&) = delete;
private:
     int nodeCounter{0};
     struct Node {
         int value;
         Node* next;
         Node(int v, Node* n) : value(v), next(n) {}
     };
     Node* first;
};
#endif /* LIST_H */
