/*
Check if a Binary Tree is BST
Send Feedback
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
The first and only line of output contains either true or false.
Constraints :
Time Limit: 1 second
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false
*/

#include <iostream>
using namespace std;
#include<climits>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// method : 1, O(N*H)
/*
int maximum(BinaryTreeNode<int> *root){
	if(root == NULL){
		return INT_MIN;
	}

	return max(root->data, max(maximum(root->left), maximum(root->right))); 
}

int minimum(BinaryTreeNode<int> *root) {
  if (root == NULL) {
    return INT_MAX;
  }

  return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root) {
  if (root == NULL) {
    return true;
  }

  int leftmax = maximum(root->left);
  int rightmin = minimum(root->right);

  int output = (leftmax < root->data) && (rightmin >= root->data) &&
               isBST(root->left) && isBST(root->right);
}
*/

// method : 2, O(N)
/*
class IsBSTReturn {
public:
  bool isBST;
  int minimum;
  int maximum;
};

IsBSTReturn Helper(BinaryTreeNode<int> *root) {
	// Write your code here
        if (root == NULL) {
          IsBSTReturn output;
          output.isBST = true;
          output.minimum = INT_MAX;
          output.maximum = INT_MIN;
          return output;
        }
        IsBSTReturn leftOutput = Helper(root->left);
        IsBSTReturn rightOutput = Helper(root->right);
        int minimum =
            min(root->data, min(leftOutput.minimum, rightOutput.minimum));
        int maximum =
            max(root->data, max(leftOutput.maximum, rightOutput.maximum));
        bool isBSTFinal = (root->data > leftOutput.maximum) &&
                          (root->data <= rightOutput.minimum) &&
                          leftOutput.isBST && rightOutput.isBST;
        IsBSTReturn output;
        output.minimum = minimum;
        output.maximum = maximum;
        output.isBST = isBSTFinal;
        return output;
}

bool isBST(BinaryTreeNode<int> *root) { 
	return Helper(root).isBST; 
}*/

// method : 1, Top to bottom
bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data < min || root->data > max)
    {
        return false;
    }

    return isBST(root->left, min, root->data - 1) &&
           isBST(root->right, root->data, max);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}
