#include<iostream>
#include<climits>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(){
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    // Return the number of element present in Stack
    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        // if(nextIndex == 0){
        //     return true;
        // }
        // else{
        //     return false
        // }

        return nextIndex==0;
    }

    void push(int element){
        if(nextIndex  == capacity){
            int *newData = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newData[i] = data[i]; 
            }
            capacity *=2;
            delete []data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};

int main(){
    StackUsingArray s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);


	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.size() << endl;

	cout << s.isEmpty() << endl;
}
