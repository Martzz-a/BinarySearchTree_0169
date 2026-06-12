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

    void search(string element, Node*& parent, Node*& currentNode)
    {
        currentNode = ROOT;
        parent = nullptr;

        while((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftChild;
            else
                currentNode = currentNode->rightChild;
        }
    } 

    void inorder(Node* ptr)
    {
        if (ROOT == nullptr)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != nullptr)
        {
            inorder(ptr->leftChild);
            cout << ptr->info << " ";
            inorder(ptr->rightChild);
        }
    }

    void preorder(Node* ptr)
    {
        if (ROOT == nullptr)
        {
            cout <<"Tree is empty" <<  endl;
            return;
        }

        if (ptr != nullptr)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftChild);
            preorder(ptr->rightChild);
        }
    }

    void postorder(Node* ptr)
    {
        // perfoms the postorder traveersal of the tree
        if (ROOT == nullptr)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != nullptr)
        {
            postorder(ptr->leftChild);
            postorder(ptr->rightChild);
            cout << ptr->info << " ";
        }
    }

};

int main()
{
    BinaryTree obj;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. implement insert operation" << endl;
        cout << "2. perform inorder traversal" << endl;
        cout << "3. perform preorder traversal" << endl;
        cout << "4. perform postorder traversal" << endl;
        cout << "5. exit" << endl;
        cout << "\nEnter your choice (1-5): ";
        char ch;
        cin >> ch;
        cout << endl;
        switch (ch)
        {
            case '1':
            {
                cout << "Enter a word: ";
                string word;
                cin >> word;
                obj.insert(word);
                break;
            }
            case '2':
            {
                obj.inorder(obj.ROOT);
                break;
            }
            case '3':
            {
                obj.preorder(obj.ROOT);
                break;
            }
            
            case '4':
            {
                obj.postorder(obj.ROOT);
                break;
            }
            case '5':
                return 0;
            
            default:
            {
                cout << "Invalid option" << endl;
                break;
            }
        }
    }
    return 0;
}
