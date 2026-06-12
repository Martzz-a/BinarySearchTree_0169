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
