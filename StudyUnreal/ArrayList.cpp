#include "ArrayList.h"

void BinaryTree::AddNode(int data)
{
	if (rootNode->data == NULL) rootNode->data = data;
	else InsertNode(rootNode, CreateNode(data));
}

void BinaryTree::RemoveNode(int data)
{
}

void BinaryTree::PrintAll()
{
	InOrder(rootNode);
}

/* ============================================================== */

Node* BinaryTree::CreateNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void BinaryTree::InsertNode(Node* tree, Node* newNode)
{
	if (newNode->data > tree->data) {
		if (tree->right != NULL) {
			InsertNode(tree->right, newNode);
		} else tree->right = newNode;
	} else if (newNode->data > tree->data) {
		if (tree->left != NULL) {
			InsertNode(tree->left, newNode);
		} else tree->left = newNode;
	}
}

//Node* BinaryTree::DeleteNode(Node* tree, int data)
//{
//	if (data > tree->data) {
//		if (tree->right != NULL) {
//			InsertNode(tree->right, newNode);
//		} else return NULL;
//	} else if (data > tree->data) {
//		if (tree->left != NULL) {
//			InsertNode(tree->left, newNode);
//		} else return NULL;
//	} else 
//	return nullptr;
//}

Node* BinaryTree::FindMin(Node* root)
{
	Node* node = root;
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node;
}

Node* BinaryTree::FindMax(Node* root)
{
	Node* node = root;
	while (node->right != NULL)
	{
		node = node->right;
	}
	return node;
}

void BinaryTree::InOrder(Node* root)
{
	if (root == NULL) return;
	InOrder(root->left);
	cout << root->data << endl;
	InOrder(root->right);
}

BinaryTree::BinaryTree()
{
	Node* node = new Node();
	node->data = NULL;
	node->left = NULL;
	node->right = NULL;
	rootNode = node;
}

BinaryTree::~BinaryTree()
{
}
