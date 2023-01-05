/*
Return Permutations - String
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba

*/

#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input.empty())
    {
        output[0]="";
        return 1;
    }
    int k=0;
    for(int i=0;i<input.size();i++)
    {
        string temp[1000]; // it stores the o/p whcih output gives
        int size = returnPermutations(input.substr(0,i) + input.substr(i+1) , temp );
 // bc and cb - 2                           // " "     +     bc              // " "
                 //
        for(int j=0;j<size;j++)
        {
            output[k]=input[i]+temp[j];
                     // a     +    bc
                     // a     +    cb
            k++;
        }
    }
    return k;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}