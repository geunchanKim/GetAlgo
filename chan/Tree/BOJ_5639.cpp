#include <iostream>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

struct Node {
    int data;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
};

class binarySearchTree {
    private:
        Node* root;
    public:
        binarySearchTree(){
            root = nullptr;
        }
        void insert(int elem);
        void postOrder(Node* node);
        Node* getRoot();
};

void binarySearchTree::insert(int elem){
    Node* addNode = new Node;
    if(root == nullptr){
        addNode->data = elem;
        addNode->parent = nullptr;
		addNode->leftChild = nullptr;
		addNode->rightChild = nullptr;
        root = addNode;
        return;
    }

    Node* curNode = root;
    while(1){
        while(curNode->data > elem){
            if(curNode->leftChild == nullptr){
                addNode->data = elem;
                addNode->parent = curNode;
                addNode->leftChild = nullptr;
                addNode->rightChild = nullptr;
                curNode->leftChild = addNode;
                return;
            }else
                curNode = curNode->leftChild;
        }
        while(curNode->data <= elem){
            if(curNode->rightChild == nullptr){
                addNode->data = elem;
                addNode->parent = curNode;
                addNode->leftChild = nullptr;
                addNode->rightChild = nullptr;
                curNode->rightChild = addNode;
                return;
            }else
                curNode = curNode->rightChild;
        }
    }
};

Node* binarySearchTree::getRoot() {
	return root;
}

void binarySearchTree::postOrder(Node* root){
    if(root == nullptr) return;
    postOrder(root->leftChild);
    postOrder(root->rightChild);
    cout << root->data << '\n';
}

int main(){
    binarySearchTree* bst = new binarySearchTree();
    int elem;
    while(cin >> elem){
        bst->insert(elem);
    }
    bst->postOrder(bst->getRoot());
}