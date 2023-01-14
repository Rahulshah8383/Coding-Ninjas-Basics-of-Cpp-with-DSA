#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data=data;
    }
};

TreeNode<int>* takeInputLevelWise(){
    int rootdata;
    cout<<"Enter the root data : ";
    cin>>rootdata;
    TreeNode<int>* root=new TreeNode<int>(rootdata);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter num of children "<<front->data<<endl;
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
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

int main(){
    TreeNode<int>* root=takeInputLevelWise();
    printTree(root);
    return 0;
}

/*
Enter the root data : 1
Enter num of children 1
3
Enter 0th child of 1
2
Enter 1th child of 1
3
Enter 2th child of 1
4
Enter num of children 2
2
Enter 0th child of 2
5
Enter 1th child of 2
6
Enter num of children 3
1
Enter 0th child of 3
7
Enter num of children 4
1
Enter 0th child of 4
8
Enter num of children 5
0
Enter num of children 6
0
Enter num of children 7
0
Enter num of children 8
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