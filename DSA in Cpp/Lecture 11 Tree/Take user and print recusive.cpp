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
        this->data=data;
    }
};

TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}

int main() {
	TreeNode<int>* root = takeInput();
	printTree(root);
	// TODO delete the tree
}

/*
Enter data
1
Enter num of children of 1
3
Enter data
2
Enter num of children of 2
2
Enter data
5
Enter num of children of 5
0
Enter data
6 
Enter num of children of 6
0
Enter data
3
Enter num of children of 3
1
Enter data
7
Enter num of children of 7
0
Enter data
4
Enter num of children of 4
1
Enter data
8
Enter num of children of 8
0
1:2,3,4,
2:5,6,
5:
6:
3:7,
7:
4:8,
8:
*/