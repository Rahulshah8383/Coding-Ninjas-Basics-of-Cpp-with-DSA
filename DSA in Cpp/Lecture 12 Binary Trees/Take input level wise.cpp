#include<iostream>
#include<queue>
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

BinaryTreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data "<<endl;
    cin>>rootData;

    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<queue> *pendingNode;
    pendingNode.push(root);

    while(pendingNode.size()!=0){
        BinaryTreeNode<int> *front = pendingNode.front();
        pendingNode.pop();

        int leftChildData;
        cout<<"Enter left child of "<<front->data<<endl;
        cin>>leftChildData;

        if(leftChildData != -1){
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNode.push(child);
        }

        int rightChildData;
        cout<<"Enter right child of "<<front->data<<endl;
        cin>>rightChildData;

        if(rightChildData != -1){
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNode.push(child);
        } 
    } 
    return root;
}

int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    delete root;
}


// Enter root data 
// 1
// Enter left child of 1
// 2
// Enter right child of 1
// 3
// Enter left child of 2
// 4
// Enter right child of 2
// 5
// Enter left child of 3
// 6
// Enter right child of 3
// 7
// Enter left child of 4
// -1
// Enter right child of 4
// -1
// Enter left child of 5
// 8
// Enter right child of 5
// 9
// Enter left child of 6
// -1
// Enter right child of 6
// -1
// Enter left child of 7
// -1
// Enter right child of 7
// -1
// Enter left child of 8
// -1
// Enter right child of 8
// -1
// Enter left child of 9
// -1
// Enter right child of 9
// -1
// 1: L2R3
// 2: L4R5
// 4:
// 5: L8R9
// 8:
// 9:
// 3: L6R7
// 6:
// 7: