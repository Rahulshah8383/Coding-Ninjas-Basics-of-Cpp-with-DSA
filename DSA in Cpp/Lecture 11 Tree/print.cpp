#include <iostream>
#include<vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

// void print1(TreeNode<int>* root){
//     cout<<root->data<<endl;
//     for(int i=0;i<root->children.size();i++){
//         print1(root->children[i]);
//     }
// }

// print
/*
1
2
3
*/
//we don't have any idea how tree look like

void print2(TreeNode<int>* root){
    //edge case
    if (root == NULL) {
		return;
	}

	cout << root->data << ": ";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		print2(root->children[i]);
	}
}
// 1: 2,3,
// 2: 
// 3:

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    // print1(root);
    print2(root);
}