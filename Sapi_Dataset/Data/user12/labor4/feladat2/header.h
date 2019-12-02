#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

template <typename T>
class Tree
{
private:
	class Node : public Tree<T>
	{
	public:
		Node() {}
		Node(T val) : mValue(val) {}

		void SetValue(T val) { mValue = val; }
		T GetValue() const { return mValue; }

	private:
		T mValue;
	};

public:
	Tree() {}
	Tree(T value) { mNodes.push_back(Node(value)); }

	const Node& operator[](unsigned int pos) const { return mNodes[pos]; }
	unsigned int size() const { return mNodes.size(); }

	void insert(T NewTree, unsigned int pos) { mNodes.insert(pos, Node(NewTree)); }
	void push_back(T NewTree) { mNodes.push_back(NewTree); }
	void erase(unsigned int pos) { mNodes.erase(pos); }

private:

	std::vector<Node> mNodes;
};
#endif // HEADER_H_INCLUDED
