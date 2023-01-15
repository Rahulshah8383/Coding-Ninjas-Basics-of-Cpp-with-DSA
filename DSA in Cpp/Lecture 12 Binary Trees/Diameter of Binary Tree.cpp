#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}


// O(N2)
/*
int height(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}

	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1, max(option2, option3));
}
*/

// O(N)
pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	pair<int, int> leftAns = heightDiameter(root->left);
	pair<int,int> rightAns = heightDiameter(root->right);
	int ld = leftAns.second;
	int lh = leftAns.first;
	int rd = rightAns.second;
	int rh = rightAns.first;

	int height = 1 + max(lh, rh);
	int diameter = max(lh + rh, max(ld, rd));
	pair<int, int> p;
	p.first = height;
	p.second = diameter;
	return p;
}

int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	cout << endl;
	pair<int, int> p = heightDiameter(root);
	cout << "Height: " << p.first << endl;
	cout << "Diameter: " << p.second << endl;
	delete root;
}

// Enter root data
// 1
// Enter left child of 1
// 2
// Enter right child ````of 1
// 3
// Enter left child of 2
// 4
// Enter right child of 2
// 5
// Enter left child of 3
// -1
// Enter right child of 3
// -1
// Enter left child of 4
// 6
// Enter right child of 4
// -1
// Enter left child of 5
// -1
// Enter right child of 5
// 7
// Enter left child of 6
// 8
// Enter right child of 6
// -1
// Enter left child of 7
// -1
// Enter right child of 7
// 9
// Enter left child of 8
// -1
// Enter right child of 8
// -1
// Enter left child of 9
// -1
// Enter right child of 9
// -1
// 1:L2R3
// 2:L4R5
// 4:L6
// 6:L8
// 8:
// 5:R7
// 7:R9
// 9:
// 3:

// Height: 5
// Diameter: 6