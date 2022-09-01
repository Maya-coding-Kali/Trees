// Trees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
struct Node
{
	int data;
	Node* left;
	Node* right;
	int height;
};
Node* root = new Node();

void AddNode(int value);
bool LookUp(int value);
void InOrderTraversal(Node* node);
void PreOrderTraversal(Node* node);
void PostOrderTraversal(Node* node);
Node* deleteNode(Node* current, int value);
Node* GetSmallest(Node* Current);
int height(Node* n);
bool checkHeightBalance(Node* Current, int* height);
Node* AddNodeWithRecursionAndBalance(Node* current, int value);
Node* DeleteNodeWithRotation(Node* T, int x);
Node* RightRotate(Node* y);
Node* leftRotate(Node* x);
int GetBalanceFactor(Node* n);
int main()
{
	int height = 0;
	int value = 15;
	

	root =AddNodeWithRecursionAndBalance(root, 100);
	root = AddNodeWithRecursionAndBalance(root, 1);
	root = AddNodeWithRecursionAndBalance(root, 7);
	root= AddNodeWithRecursionAndBalance(root, 70);
	root = AddNodeWithRecursionAndBalance(root, 90);
	root = AddNodeWithRecursionAndBalance(root, 45);
	root = AddNodeWithRecursionAndBalance(root, 85);
	root = AddNodeWithRecursionAndBalance(root, 11);
	root = AddNodeWithRecursionAndBalance(root, 156);
	root = AddNodeWithRecursionAndBalance(root, 987);
	root = AddNodeWithRecursionAndBalance(root, 2);
	root = AddNodeWithRecursionAndBalance(root, 600);
	
	LookUp(987);
	std::cout << "\nIn Order\n";
	InOrderTraversal(root);
	std::cout << "\nPre Order\n";
	PreOrderTraversal(root);
	std::cout << "\nPost Order\n";
	PostOrderTraversal(root);
	std::cout << "\n";
	DeleteNodeWithRotation(root, 45);
	InOrderTraversal(root);
	if (checkHeightBalance(root, &height))
	{
		std::cout << "Balanced" << std::endl;
	}
	else
	{
		std::cout << "Not Balanced" << std::endl;
	}
}
// Function to delete a node from a BST
// Check height balance
bool checkHeightBalance(Node* root, int* height) {
	// Check for emptiness
	int leftHeight = 0, rightHeight = 0;

	int l = 0, r = 0;

	if (root == NULL) {
		*height = 0;
		return 1;
	}

	l = checkHeightBalance(root->left, &leftHeight);
	r = checkHeightBalance(root->right, &rightHeight);

	*height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

	if (std::abs(leftHeight - rightHeight >= 2))
		return 0;

	else
		return l && r;
}
Node* DeleteNodeWithRotation(Node* T, int x)
{
	Node* p;

	if (T == NULL)
	{
		return NULL;
	}
	else
		if (x > T->data)
		{
			T->right = DeleteNodeWithRotation(T->right, x);
			if (GetBalanceFactor(T) == 2)
				if (GetBalanceFactor(T->left) >= 0)
					T = leftRotate(T);
				else
					T = RightRotate(T);
		}
		else
			if (x < T->data)
			{
				T->left = DeleteNodeWithRotation(T->left, x);
				if (GetBalanceFactor(T) == -2)
					if (GetBalanceFactor(T->right) <= 0)
						T = leftRotate(T);
					else
						T = RightRotate(T);
			}
			else
			{
				if (T->right != NULL)
				{
					p = T->right;

					while (p->left != NULL)
						p = p->left;

					T->data = p->data;
					T->right = DeleteNodeWithRotation(T->right, p->data);

					if (GetBalanceFactor(T) == 2)
						if (GetBalanceFactor(T->left) >= 0)
							T = leftRotate(T);
						else
							T = RightRotate(T); \
				}
				else
					return(T->left);
			}
	T->height = height(T);
	return(T);
}
Node* deleteNode( Node* current, int value)
{
	if (!LookUp(value))
	{
		return root;
	}

	if (root == NULL)
	{
		return current;
	}
	if (value < current->data)
	{
		current->left = deleteNode(current->left, value);
	}
	else if(value > current->data)
	{
		current->right = deleteNode(current->right, value);
	}
	else
	{
		if (current->left == NULL && current->right == NULL)
		{
			return NULL;
		}
		else if(current->left == NULL)
		{
			Node* temp = current->right;
			delete current;
			return temp;
		}
		else if (current->right == NULL)
		{
			Node* temp = current->left;
			delete current;
			return temp;
		}
		Node* temp = GetSmallest(current->right);
		current->data = temp->data;
		current->right = deleteNode(current->right, temp->data);
	}
	return current;
}
int max(int a, int b) {
	return (a > b) ? a : b;
}
Node* GetLargest(Node* Current)
{
	while (Current->right != nullptr) {
		Current = Current->right;
	}
	return Current;
}
Node* GetSmallest(Node* Current)
{
	while (Current->left != nullptr) {
		Current = Current->left;
	}
	return Current;
}
void InOrderTraversal(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	InOrderTraversal(node->left);
	std::cout << node->data << "\n";
	InOrderTraversal(node->right);

}
void PostOrderTraversal(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	std::cout << node->data << "\n";
	InOrderTraversal(node->left);
	InOrderTraversal(node->right);

}
void PreOrderTraversal(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	InOrderTraversal(node->left);
	InOrderTraversal(node->right);
	std::cout << node->data << "\n";
}
bool LookUp(int value)
{
	Node* current = root;
	bool found = true;
	while (current->data != value)
	{
		if (current->data > value)
		{
			if (current->left == NULL)
			{
				found = false;
				break;
			}
			current = current->left;
		}
		else if (current->data < value)
		{
			if (current->right == NULL)
			{
				found = false;
				break;
			}
			current = current->right;
		}
		else if (current->data == value)
		{
			found = true;
		}
	}
	if (found)
	{
		std::cout << "found the data: " << current->data << "\n";

	}
	else
	{
		std::cout << "could not find the data \n";

	}
	return found;
}
void AddNode(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	if (root == NULL)
	{
		root = newNode;
		root->left = NULL;
		root->right = NULL;

		return;
	}
	Node* current = new Node();
	current = root;
	while (current != NULL)
	{
		if (current->data < newNode->data)
		{
			if (current->right == NULL)
			{
				

				current->right = newNode;
				newNode->right = NULL;
				newNode->left = NULL;
				break;
			}
			current = current->right;
		}
		else if (current->data > newNode->data)
		{
			if (current->left == NULL)
			{
				
				current->left = newNode;
				newNode->right = NULL;
				newNode->left = NULL;
				break;
			}
			current = current->left;
		}
		/*if (current->left == NULL || current->right == NULL)
		{
			break;
		}*/
	}
}
Node* RightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}
Node* leftRotate(Node* x) 
{
	Node* y = x->right;
	Node* T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) +	1;
	return y;
}
int GetBalanceFactor(Node* n)
{
	if (n == NULL)
	{
		return 0;
	}
	return height(n->left) - height(n->right);
}
Node* newNode(int key) {
	Node* node = new Node();
	node->data = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}
Node* AddNodeWithRecursionAndBalance(Node* current, int value)
{
	if (current == NULL)
	{
		
		return newNode(value);
	}
	if (value < current->data)
	{
		current->left = AddNodeWithRecursionAndBalance(current->left, value);
	}
	else if (value > current->data)
	{
		current->right = AddNodeWithRecursionAndBalance(current->right, value);
	}
	else
	{
		return current;
	}

	current->height = 1 + max(height(current->left), height(current->right));
	int balanceFactor = GetBalanceFactor(current);
	if (balanceFactor > 1)
	{
		if (value < current->left->data)
		{
			return RightRotate(current);
		}
		else
		{
			current->left = leftRotate(current->left);
			return RightRotate(current);
		}
	}
	if (balanceFactor < -1) {
		if (GetBalanceFactor(current->right) <= 0) {
			return leftRotate(current);
		}
		else {
			current->right = RightRotate(current->right);
			return leftRotate(current);
		}
	}
	return current;
}
int height(Node* n)
{
	if (n == NULL)
	{
		return 0;
	}
	return n->height;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
