
#include <iostream>
#include <string>
	using namespace std;
typedef string Info;
struct Node
{
	Node* left,
		* right;
	Info info;
};
void PrintTree(Node* root, int level);
Node* BinarySearchInsert(Node*& root, Info value, bool& found);
int main()
{
	Node* root = NULL;
	int N;
	cout << "Nodes count: "; cin >> N;
	Info value;
	bool found = false;
	for (int i = 0; i < N; i++)
	{
		cout << "value: "; cin >> value;
		BinarySearchInsert(root, value, found);
	}
	PrintTree(root, 0);
	return 0;
}
void PrintTree(Node* root, int level)
{
	if (root != NULL)
	{
		PrintTree(root->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << " ";
			cout << root->info << endl;
		PrintTree(root->left, level + 1);
	}
}
Node* BinarySearchInsert(Node*& root, Info value, bool& found)
{
	if (root == NULL)
	{
		root = new Node;
		root->info = value;
		root->left = NULL;
		root->right = NULL;
		found = false;
		return root;
	}
	else
		if (value == root->info)
		{
			found = true;
			return root;
		}
		else
			if (value < root->info)
				return BinarySearchInsert(root->left, value, found);
			else
				return BinarySearchInsert(root->right, value, found);
}