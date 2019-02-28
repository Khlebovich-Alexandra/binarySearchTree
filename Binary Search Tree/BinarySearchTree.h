#pragma once
#include <iostream>
#include <string>
#include <vector>
struct Node
{
	int  key;		
	Node*  left;	
	Node*  right;	
	Node(int key1, Node* rightEl, Node* leftEl) : key(key1), right(rightEl), left(leftEl) {}
};

class BinarySearchTree
{
private:
	Node* root;
	int count;
protected:
	std::string getKey(Node* node)const;
	bool addKey(int key, Node* node);
	std::string getLeftInOrder(Node* node)const;
	std::string getInternalInOrder(Node* node)const;
	Node* findFatherOfKey(int key, Node* node)const;
	void deleteKeyRight(Node* root, Node* father, bool isLeft);
	void deleteIfOnlyLeftSubtree(Node* root, Node* father, bool isLeft);
	void deleteIfOnlyRightSubtree(Node* root, Node* father, bool isLeft);
	int getCount(Node* node)const;
	int getMedium(Node* node, int& count)const;
public:
	BinarySearchTree() : count(0), root(0) {};
	void deleteKeyRight(int key);
	bool isEmpty()const	{ return root == 0; }
	void addKey(int key);
	int getHeight()const;
	int getCount()const;
	std::string getMedium()const;

	std::string getMinKey()const;
	std::string getMaxKey()const;
	std::string getRoot()const;
	std::string getLeftInOrder()const;
	std::string getInternalInOrder()const;
	std::string getSortedListOfElements()const;
	std::vector<int> getSortedVector()const;

	~BinarySearchTree();
};

