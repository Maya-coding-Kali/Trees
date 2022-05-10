// Trees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* parent;
};
Node* root;
void AddNode(int value);
void LookUp(int value);
void InOrderTraversal(Node* node);
void inOrderIteration();
void deleteNode(int value);

int main()
{
	int value = 15;
	AddNode(15);
	AddNode(32);
	AddNode(7);
	AddNode( 8);
	AddNode(16);
	AddNode(33);
	AddNode(9);
	AddNode(100);
	AddNode(6);
	AddNode(3);
	LookUp(33);
	InOrderTraversal(root);
	deleteNode(15);
	InOrderTraversal(root);


}
void deleteNode(int value)
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
		if (current == root)
		{
			return;

		}
		else if (current->right == NULL && current->left == NULL && current->data < current->parent->data)
		{
			
			current->parent->left = NULL;
			delete current;
		}
		else if (current->right == NULL && current->left == NULL && current->data > current->parent->data)
		{
			current->parent->right = NULL;
			delete current;
		}
		else if(current->left != NULL)
		{
			current->parent->left = current->left;
			delete current;
		}
		else if (current->right != NULL)
		{
			current->parent->right = current->right;
			delete current;
		}
	}
	else
	{
		std::cout << "could not find the data \n";

	}
}
void inOrderIteration()
{
	Node* current = root;
	std::stack<int> MyStack;
	while (current != NULL)
	{
		if (current->left ==NULL)
		{
			std::cout << current->data<<"\n";
			current = current->parent;
			if (current->right != NULL)
			{
				current = current->right;
			}
			continue;
		}
		current = current->left;
	}
}
void InOrderTraversal(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	InOrderTraversal(node->left);
	std::cout << node->data<<"\n";
	InOrderTraversal(node->right);

}
void LookUp(int value)
{
	Node* current = root;
	bool found = true;
	while (current-> data != value)
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
		else if(current->data == value)
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
	while (current != NULL )
	{
		if (current->data < newNode->data)
		{
			if (current->right == NULL)
			{
				newNode->parent = current;

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
				newNode->parent = current;
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
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
