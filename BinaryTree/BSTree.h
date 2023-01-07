#pragma once
#include "BSIter.h"
#include <iostream>

template <typename Value>
class BSTree
{
	struct Node
	{
		Node(Value val) : m_val(val) {}
		Node* left = nullptr;
		Node* right = nullptr;
		Value m_val;
	};


	Node* root = nullptr;

	void clear(Node*);
	void insert(Value, Node*);
	void printTree(Node*);

public:
	void clear();
	void insert(Value);
	void printTree();
	//void remove(Value);

//	Iterator getIterator();

	BSTree(Value val);
	BSTree() : root(new Node{0}) {};
	~BSTree() 
	{
		clear();
	}
};


template <typename Value>
BSTree<Value>::BSTree(Value val)
{
	root = new Node{ val };
}

template <typename Value>
void BSTree<Value>::insert(Value val)
{
	insert(val, root);
}

template <typename Value>
void BSTree<Value>::insert(Value val, Node* node)
{
	if (node->right == nullptr && val > node->m_val)
		node-> right = new Node{ val };

	else if (node->left == nullptr && val < node->m_val)
		node->left = new Node{ val };

	else if (val > node->m_val)
		insert(val, node->right);
	else if (val < node->m_val)
		insert(val, node->left);
}

template <typename Value>
void BSTree<Value>::printTree()
{
	printTree(root);
}

template <typename Value>
void BSTree<Value>::printTree(Node* root)
{
	if (root == nullptr)
		return;

	std::cout << root->m_val;
	printTree(root->left);
	printTree(root->right);
}

template <typename Value>
void BSTree<Value>::clear(Node* node)
{
	if (node == nullptr)
		return;

	else if (node->left == nullptr && node->right == nullptr)
	{
		delete node;
		node = nullptr;
	}

	else if (node->left == nullptr)
	{
		clear(node->right);
	}
	else if (node->right == nullptr)
	{
		clear(node->left);
	}

	else if (node->left == nullptr && node->right == nullptr)
	{
		clear(node->left);
		clear(node->right);
	}
}

template <typename Value>
void BSTree<Value>::clear()
{
	clear(root);
}

