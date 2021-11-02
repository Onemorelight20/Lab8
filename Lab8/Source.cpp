#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;



int main() {

	BinaryTree tree;
	//insert tree elements
	tree.insert({ "n-p-n", "NG22", 6, 29 });
	tree.insert({ "p-n-p", "K903", 7, 9});
	tree.insert({ "n-p-n", "M111", 4, 29});
	tree.insert({ "p-n-p", "F555", 3, 29 });
	tree.insert({ "n-p-n", "F230", 23, 2});
	tree.insert({ "p-n-p", "B322", 3, 29 });
	cout << "My binary tree:\n";
	tree.output();

	int keyI = 4;
	node* searchTest = tree.search(keyI);
	cout << "\nSearch by key: " << keyI << "\t" << (searchTest == nullptr ? "The element wasn`t found" : searchTest->data.info()) << "\n";


	cout << "\nTest output with of all elements with set Imax and Umax\n";
	tree.output(3,29);

	cout << "\nTest output with specific type of transistor\n";
	tree.output("n-p-n");

	cout << "\nTest deletion of element\n";
	tree.deleteElement({ "n-p-n", "F230", 23, 2 });
	tree.output();


	return 0;
}


//бінарне дерево - занесення вузла в дерево,	+
//  пошук вузла по ключу,						+      
//	вивід даних вузла,							+
//	видалення вузла,							+
//	обхід дерева,								+
//	вивід всіх вузлів,							+
//	знищення дерева.							+

//Бінарне дерево
//Транзистор :
//тип(p - n - p, n - p - n),
//марка(КТ369А тощо),
//Ik max,
//Uke max
//вставка вузла за значенням Ikmax;						+
//вилучення всіх вузлів із заданим типом;				+
//вивід всіх вузлів із заданими Ikmax  та Ukemax;		+
//обхід дерева «знизу вверх»							+

