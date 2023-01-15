#include<iostream>
using namespace std;

template<typename T>

class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

void printTree(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<": ";
    if(root->left != NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> *takeInput(){
    int rootData;
    cout<<"Enter data "<<endl;
    cin>>rootData;

    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    printTree(root);
    delete root;
}

// Enter data 
// 1
// Enter data
// 2
// Enter data
// -1
// Enter data
// -1
// Enter data
// 3
// Enter data
// -1
// Enter data
// -1
// 1: L2R3
// 2:
// 3:


// Enter data 
// 1
// Enter data
// 2
// Enter data
// 4
// Enter data
// -1
// Enter data
// -1
// Enter data
// 5
// Enter data
// 6
// Enter data
// -1
// Enter data
// -1
// Enter data
// 7
// Enter data
// -1
// Enter data
// -1
// Enter data
// 3
// Enter data
// 8
// Enter data
// -1
// Enter data
// -1
// Enter data
// -1
// 1: L2R3
// 2: L4R5
// 4:
// 5: L6R7
// 6:
// 7:
// 3: L8
// 8: