#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    // way- 2: delete tree Nodes by destructor
    ~TreeNode(){
        for (int i = 0; i < children.size(); i++){
            delete children[i];
        }
    }
};

// way-1: delete tree Nodes by function 
void deleteTree(TreeNode<int>* root){
   for (int i = 0; i < root->children.size(); i++){
        deleteTree(root->children[i]);
    } 
    delete root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    deleteTree(root);
}

