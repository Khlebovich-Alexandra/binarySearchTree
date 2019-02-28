#include "BinarySearchTree.h"



std::string BinarySearchTree::getKey(Node * node) const
{
	if (node) {
		return std::to_string(node->key) + '\n';
	}
	return "Empty";
}

bool BinarySearchTree::addKey(int key, Node* node)
{
	bool isUnique = true;
	if (isEmpty())
	{
		root = new Node(key, 0, 0);
	}
	else
	{
		if (key > node->key) {
			if (node->right == 0)
			{
				node->right = new Node(key, 0, 0);
			}
			else
			{
				addKey(key, node->right);
			}
		}
		else if (key < node->key) {
			if (node->left == 0)
			{
				node->left = new Node(key, 0, 0);
			}
			else
			{
				addKey(key, node->left);
			}
		}
		else {
			isUnique = false;
		}
	}
	return isUnique;
}

std::string BinarySearchTree::getLeftInOrder(Node * node) const
{
	std::string s;
	if (node != 0)
	{
		s += getKey(node);
		s += getLeftInOrder(node->left);
		s += getLeftInOrder(node->right);
	}
	return s;
}

std::string BinarySearchTree::getInternalInOrder(Node * node) const
{
	std::string s;
	if (node != 0)
	{
		s += getInternalInOrder(node->left);
		s += getKey(node);
		s += getInternalInOrder(node->right);
	}
	return s;
}

void BinarySearchTree::deleteKeyRight(int key)
{
	if (isEmpty())
	{
		return;
	}
	if (key == root->key)
	{
		deleteKeyRight(root, 0, 0);
	}
	else
	{
		Node* father = findFatherOfKey(key, root);
		if (father == 0)
		{
			return;
		}
		if (key > father->key)
		{
			deleteKeyRight(father->right, father, 0);
		}
		else
		{
			deleteKeyRight(father->left, father, 1);
		}
	}
	count--;
}

Node * BinarySearchTree::findFatherOfKey(int key, Node * node)const
{
	if (key < node->key && node->left != 0)
	{
		if (node->left->key == key)
		{
			return node;
		}
		return findFatherOfKey(key, node->left);
	}
	if (key > node->key && node->right != 0)
	{
		if (node->right->key == key)
		{
			return node;
		}
		return findFatherOfKey(key, node->right);
	}
	return 0;
}

void BinarySearchTree::deleteKeyRight(Node * root, Node * father, bool isLeft)
{
	if (root->left == 0 && root->right == 0)
	{
		delete root;
		if (father != 0)
		{
			if (isLeft) father->left = 0;
			else father->right = 0;
		}
		else
		{
			this->root = 0;
		}
		return;
	}
	if (root->left == 0)
	{
		deleteIfOnlyRightSubtree(root, father, isLeft);
		return;
	}
	else if (root->right == 0)
	{
		deleteIfOnlyLeftSubtree(root, father, isLeft);
		return;
	}
	Node* node = root->right;
	if (node->left == 0)
	{
		root->key = node->key;
		root->right = node->right;
		return;
	}
	while (node->left->left != 0)
	{
		node = node->left;
	}
	root->key = node->left->key;
	Node* tmp = node->left;
	node->left = node->left->right;
	delete tmp;
}

void BinarySearchTree::deleteIfOnlyLeftSubtree(Node * root, Node * father, bool isLeft)
{
	if (father == 0)
	{
		this->root = root->left;
	}
	else if (isLeft)
	{
		father->left = root->left;
	}
	else
	{
		father->right = root->left;
	}
	delete root;
}

void BinarySearchTree::deleteIfOnlyRightSubtree(Node * root, Node * father, bool isLeft)
{
	if (father == 0)
	{
		this->root = root->right;
	}
	else if (isLeft)
	{
		father->left = root->right;
	}
	else
	{
		father->right = root->right;
	}
	delete root;
}

int BinarySearchTree::getCount(Node * node) const
{
	int result = 0;
	if (node != 0)
	{
		result += getCount(node->left);
		result += getCount(node->right);
		result++;
	}
	return result;;
}

int BinarySearchTree::getMedium(Node * node, int& count) const
{
	if (node != 0)
	{
		int result = getMedium(node->left, count);
		if (count == 1)
		{
			count--;
			return node->key;
		}
		else if (count == 0)
		{
			return result;
		}
		else 
		{
			count--;
		}
		result = getMedium(node->right, count);
	}
}

void BinarySearchTree::addKey(int key)
{
	count += addKey(key, root);
}

int BinarySearchTree::getHeight() const
{
	if (isEmpty())
	{
		return -1;
	}

	return 0;
}

int BinarySearchTree::getCount() const
{
	return getCount(root);
}

std::string BinarySearchTree::getMedium() const
{
	int count = getCount();
	if (count % 2 == 0)
	{
		return "ERROR";
	}
	count = (count + 1) / 2;
	return std::to_string(getMedium(root, count));
}

std::string BinarySearchTree::getMinKey() const
{
	if (isEmpty())
	{
		return "Empty";
	}
	Node* node = root;
	while (node->left != 0)
	{
		node = node->left;
	}
	return std::to_string(node->key);
}

std::string BinarySearchTree::getMaxKey() const
{
	if (isEmpty())
	{
		return "Empty";
	}
	Node* node = root;
	while (node->right != 0)
	{
		node = node->right;
	}
	return std::to_string(node->key);
}

std::string BinarySearchTree::getRoot() const
{
	return getKey(root);
}

std::string BinarySearchTree::getLeftInOrder() const
{
	return getLeftInOrder(root);
}

std::string BinarySearchTree::getInternalInOrder() const
{
	return getInternalInOrder(root);
}

std::string BinarySearchTree::getSortedListOfElements() const
{
	return getInternalInOrder();
}

std::vector<int> BinarySearchTree::getSortedVector() const
{
	return std::vector<int>();
}



BinarySearchTree::~BinarySearchTree()
{
	while (!isEmpty())
		deleteKeyRight(root->key);
}
