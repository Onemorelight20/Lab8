#pragma once
#include <iostream>
#include <string>
using namespace std;



struct Transistor
{
	string type;
	string model;
	int maxI;
	int maxU;

	string info() {
		return "Transistor type: " + type + ", model " + model + ", Imax = " + to_string(maxI) + ", Umax = " + to_string(maxU) + ".";
	}
} typedef Transistor;

struct node
{
	Transistor data;
	struct node* left;
	struct node* right;
} typedef node;

class BinaryTree {


public:
	BinaryTree();
	~BinaryTree();

	void insert(Transistor t);
	node* search(int maxI);
	void deleteTree();
	node* findMin(node* leaf);
	void deleteWithType(string type);
	

	void deleteElement(Transistor t);
	void output();
	void output(int maxI, int maxU);
	void output(string type);

private:
	void insert(Transistor t, node* leaf);
	node* search(int maxI, node* leaf);
	void deleteTree(node* leaf);
	node* deleteElement(node* leaf, Transistor t);
	void deleteWithType(node* leaf, string type);

	void output(node* leaf);
	void output(int maxI, int maxU, node* leaf);
	void output(string type, node* leaf);

	node* root;
};