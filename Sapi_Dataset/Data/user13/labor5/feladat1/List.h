#pragma once
#ifndef LIST_H
#define LIST_H
#include <list>
class List {
public:
	
	List();		/* creates an empty list */
	~List();	/* destroys this list */
	bool exists(int d) const;	/* returns true if d is in the list							-complexity: O(n) */
	int size() const;	/* returns the size of the list										-complexity: O(1) */
	bool empty() const;		/* returns true if the list is empty							-complexity: O(1) */
	void insertFirst(int d);		/* inserts d into this list as the first element		-complexity: O(1) */
	void comp(list<int>);
	enum class
		DeleteFlag {
		LESS, EQUAL, GREATER, Ficsor
	};

	void remove(int d, DeleteFlag df = DeleteFlag::EQUAL);		/* removes the first element less than/equal to/greater than d,
																depending on the value of df. Does nothing if there is no value
																to remove. The enum values are accessed with List::DeleteFlag::LESS,
																..., outside the class */
	
	void print() const;		/* prints the contents of this list */
	List(const List&) = delete;		/* forbid copying of lists */
	List& operator = (const List&) = delete;
private:
	int nodeCounter{ 0 };		/* number of nodes in the list */
	/* a list node */
	struct Node {
		int value;		// the node value
		Node* next;		// pointer to the next node, nullptr in the last node
		Node(int v, Node* n) : value(v), next(n) {
		}
	};
	Node* first; // pointer to the first node
};
#endif /* LIST_H */