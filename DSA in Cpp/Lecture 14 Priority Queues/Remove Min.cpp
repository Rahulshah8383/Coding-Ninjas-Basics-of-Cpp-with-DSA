/*
Code : Remove Min
Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }
        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if (isEmpty()) {
          return 0; //  we will check if Priority Queue is empty
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1]; // replace the main with the root node
        pq.pop_back();             // we will remove the element
        int parentIndex = 0;       // down heap
        int leftChildIndex = 2 * parentIndex + 1; // for leftchild
        int rightChildIndx = 2 * parentIndex + 2; // for rightchild

        while (leftChildIndex <
               pq.size()) { // to check so that the it should not overflow and
                            // leftchild will act as leaf child
          int minIndex = parentIndex; // minindex to check the minimum element
                                      // of three left, right and parent
          if (pq[minIndex] > pq[leftChildIndex]) {
            minIndex = leftChildIndex;
          }
          if (rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
            minIndex = rightChildIndx;
          }
          if (minIndex == parentIndex) { // it will not excute if left and right
                                         // have children
            break;
          }
          int temp = pq[minIndex]; // now we will do swapping
          pq[minIndex] = pq[parentIndex];
          pq[parentIndex] = temp;

          parentIndex = minIndex;
          leftChildIndex = 2 * parentIndex + 1;
          rightChildIndx = 2 * parentIndex + 2;
        }

        return ans;
    }
};

int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}