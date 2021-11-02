#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;


BinaryTree::BinaryTree() 
{
	root = nullptr;
}
BinaryTree::~BinaryTree() 
{
	deleteTree();
}

//delete a tree
void BinaryTree::deleteTree() 
{
	deleteTree(root);
}
//delete a tree (private method)
void BinaryTree::deleteTree(node* leaf) 
{
	if (leaf == nullptr) { return; }
	deleteTree(leaf->left);
	deleteTree(leaf->right);
	delete leaf;
}

//insert an element
void BinaryTree::insert(Transistor t) 
{
	if (root != nullptr) {
		insert(t, root);
	}
	else {
		root = new node;
		root->data = t;
		root->left = nullptr;
		root->right = nullptr;
	}
}

//insert an element 
void BinaryTree::insert(Transistor t, node* leaf) 
{
	if (t.maxI < leaf->data.maxI) {
		if (leaf->left != nullptr) {
			insert(t, leaf->left);
		}
		else {
			leaf->left = new node;
			leaf->left->data = t;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else if (t.maxI >= leaf->data.maxI) {
		if (leaf->right != nullptr) {
			insert(t, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->data = t;
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
		}
	}
}

//find an element by key
node* BinaryTree::search(int maxI) 
{
	return search(maxI, root);
}

//find an element by key (private method)
node* BinaryTree::search(int maxI, node* leaf) 
{
	if (leaf != nullptr) {
		if (maxI == leaf->data.maxI) {
			return leaf;
		}
		if (maxI < leaf->data.maxI) {
			search(maxI, leaf->left);
		}
		else {
			search(maxI, leaf->right);
		}
	}
	else return nullptr;
}


//Output overloading
void BinaryTree::output() {
	output(root);
}

void BinaryTree::output(node* leaf)
{
	if (leaf != nullptr) {
		output(leaf->left);
		cout << leaf->data.info() << endl;
		output(leaf->right);
	}
}

void BinaryTree::output(int maxI, int maxU) 
{
	output(maxI, maxU, root);
}

void BinaryTree::output(int maxI, int maxU, node* leaf) 
{
	if (leaf != nullptr) {
		output(maxI, maxU, leaf->left);
		if (maxI == leaf->data.maxI && maxU == leaf->data.maxU) {
			cout << leaf->data.info() << endl;
		}
		output(maxI, maxU, leaf->right);
	}
}

void BinaryTree::output(string type) 
{
	output(type, root);
}

void BinaryTree::output(string type, node* leaf) 
{
	if (leaf != nullptr) {
		output(type, leaf->left);
		if (type == leaf->data.type) {
			cout << leaf->data.info() << endl;
		}
		output(type, leaf->right);
	}
}



// delete a node
void BinaryTree::deleteElement(Transistor t) 
{
	root = deleteElement(root, t);
}

node* BinaryTree::deleteElement(node* leaf, Transistor t) 
{
	if (leaf == nullptr) return leaf;
	else if (t.maxI < leaf->data.maxI) {
		leaf->left = deleteElement(leaf->left, t);
	}
	else if (t.maxI > leaf->data.maxI) {
		leaf->right = deleteElement(leaf->right, t);
	}
	else if (t.info() == leaf->data.info()){
		if (leaf->left == nullptr && leaf->right == nullptr) {
			delete leaf;
			leaf = nullptr;
		}
		else if (leaf->left == nullptr) {
			node* temp = leaf;
			leaf = leaf->right;
			delete temp;
		} 
		else if (leaf->right == nullptr) {
			node* temp = leaf;
			leaf = leaf->left;
			delete temp;
		}
		else {
			node* temp = findMin(leaf->right);
			leaf->data = temp->data;
			leaf->right = deleteElement(leaf->right, temp->data);
		}
	}

	return leaf;
}

void BinaryTree::deleteWithType(string type) {
	deleteWithType(root, type);
}

void BinaryTree::deleteWithType(node* leaf, string type) {
	if (leaf != nullptr) {
		deleteWithType(leaf->right,type);
		if (type == leaf->data.type) {
			deleteElement(leaf->data);
		}
		deleteWithType(leaf->left, type);
	}
}

node* BinaryTree::findMin(node* leaf) {
	if (leaf->left == nullptr) {
		return leaf;
	}
	else {
		findMin(leaf->left);
	}
}


