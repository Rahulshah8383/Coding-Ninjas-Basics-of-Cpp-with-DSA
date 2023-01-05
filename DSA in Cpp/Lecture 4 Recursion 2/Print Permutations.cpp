/*
Print Permutations
Given an input string (STR), print all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.
Input Format:
The only input line contains a string (STR) of alphabets in lower case
Output Format:
Print each permutations in a new line
Constraint:
1<=length of STR<=8
Time Limit: 1sec
Sample Input 1:
cba
Sample Output 1:
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

void returnPer(string input, string output)
{
   	if(input.length() == 0) // B.C is very simple ie. if length is 0 then we have hit the end and so just print whatever outputs you have
    {
        cout << output << endl;
        return;
    }

    //returnPer(input.substr(1), output);
   	for(int i = 0; i < input.length(); i++)
    {
        returnPer(input.substr(0,i)+input.substr(i+1) , input[i]+output );
                     //  " "       +     //bc       ,      // a +  " "  - for the first iteration ie. i = 0.
                    // a           +    // c        ,     // b  +  " "  - for the second iteration ie. i = 1.
                   // ab           +   // " "       ,     // c  +   " " - for the third iteration ie. i = 2.
    }
}
void printPermutations(string input){

     string output = "";
  returnPer( input, output);
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}