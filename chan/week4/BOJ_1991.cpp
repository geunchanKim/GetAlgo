#include <iostream>
#include <queue>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char data){
    Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* insertNode(Node* root, char parent, char lChild, char rChild){
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

        if(temp->data == parent){
            if(lChild != '.')
                temp->left = createNode(lChild);
            
			if(rChild != '.')
                temp->right = createNode(rChild);
		    return root;
        }else{
            if (temp->left != NULL)
			    q.push(temp->left);
            if (temp->right != NULL)
			    q.push(temp->right);
        }
	}
    return root;
}

void preorder(struct Node* node) {
	if (node == NULL) return ;
	cout << node->data;
	preorder(node->left);
	preorder(node->right);
}

void inorder(struct Node* node) {
	if (node == NULL) return ;
	inorder(node->left);
	cout << node->data;
	inorder(node->right);
}

void postorder(struct Node* node) {
	if (node == NULL) return ;
	postorder(node->left);
	postorder(node->right);
	cout << node->data;
}
 
int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    Node* root = createNode('A');
    for(int i = 0; i < N; i++){
        char parent, leftChild, rightChild;
        cin >> parent >> leftChild >> rightChild;
        root = insertNode(root, parent, leftChild, rightChild);
    }
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
}