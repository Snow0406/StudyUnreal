#include "BinaryTree.h"

void BinaryTree::AddNode(int data)
{
	Node* newNode = CreateNode(data);
	if (rootNode == NULL) rootNode = newNode;
	else InsertNode(rootNode, newNode);
}

void BinaryTree::RemoveNode(int data)
{
	if (rootNode == nullptr)
	{
		cout << "자료가 없습니다." << endl;
	} else
	{
		DeleteNode(rootNode, data);
	}
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
	} else if (newNode->data < tree->data) {
		if (tree->left != NULL) {
			InsertNode(tree->left, newNode);
		} else tree->left = newNode;
	}
}

Node* BinaryTree::DeleteNode(Node* tree, int data)
{
	if (tree == NULL) {
		return NULL;
	} else if (data < tree->data) {
		tree->left = DeleteNode(tree->left, data);
	} else if (data > tree->data) {
		tree->right = DeleteNode(tree->right, data);
	} else {
		if (tree->left == NULL && tree->right == NULL) {
			delete tree;
			tree = NULL;
		} else if (tree->left == NULL) {
			Node* del = tree;
			tree = tree->right;
			delete del;
		} else if (tree->right == NULL) {
			Node* del = tree;
			tree = tree->left;
			delete del;
		} else {
			Node* closedNode = FindMin(tree->right);
			tree->data = closedNode->data;
			tree->right = DeleteNode(tree->right, closedNode->data);
		}

	}
	return tree;
}

Node* BinaryTree::FindMin(Node* root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
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
	rootNode = NULL;
}

BinaryTree::~BinaryTree()
{
}
