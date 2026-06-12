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

    // membuat prosedur insert
    void insert(string element) {
        
        //memberi nilai untuk setiap object yang berada di dalam prosedur insert
        Node* newNode = new Node(element, nullptr, nullptr);
        newNode->info = element;
        newNode->leftChild = nullptr;
        newNode->rightChild = nullptr;

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode);

        //membuat conditional statement
        if (parent == nullptr) {
            ROOT = newNode;
            return;
        }

        if (element < parent->info) {
            parent->leftChild = newNode;
        } else {
            parent->rightChild = newNode;
        }
    }
};