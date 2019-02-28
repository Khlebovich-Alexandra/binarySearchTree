#include <iostream>
#include <vector>
#include <algorithm>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
	BinarySearchTree bst;
	vector<int> keys = { 1, 2, 3, 0, -1 };
//	vector<int> keys = { 50, 10, 100, 1, 30, 20, 40, 31, 45, 32, 33, 34, 21 };
	for (int item : keys)
	{
		bst.addKey(item);
	}
	cout << "Root: " << bst.getRoot() << endl;
	cout << "Min: " << bst.getMinKey() << endl;
	cout << "Max: " << bst.getMaxKey() << endl;
	cout << "Left inOrder: " << endl;
	cout << bst.getLeftInOrder() << endl;
	cout << "Count: " << bst.getCount() << endl;
	bst.deleteKeyRight(20);
	cout << "Left inOrder: " << endl;
	cout << bst.getLeftInOrder() << endl;
	cout << "Internal inOrder: " << endl;
	cout << bst.getInternalInOrder() << endl;
	cout << "Count: " << bst.getCount() << endl;
	cout << "Medium: " << bst.getMedium() << endl;

	system("pause");

	return 0;
}