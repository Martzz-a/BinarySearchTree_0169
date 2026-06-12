#include <iostream>
using namespace std;

//membuat class node
class Node {

// memberikan akses modifier serta mendeklarasikan variable dan object node
public:
    string info;
    Node* leftChild;
    Node* rightChild;

    //membuat constructor untuk node
    Node(string i, Node* l, Node* r) {
        //memberi nilai parameter ke variable
        info = i;
        leftChild = l;
        rightChild = r;
    }
};

//membuat class binary tree
class BinaryTree {

// memberi akses modifier dan deklaraso object
public:
    Node* ROOT;

    //membuat constructor dan memberikan nilai awal untuk ROOT
    BinaryTree() {
        ROOT = nullptr;
    }
};
