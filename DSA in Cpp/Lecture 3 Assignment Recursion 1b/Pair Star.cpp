/*
Pair Star
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

Input format :
String S
Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello
Sample Output 1:
hel*lo

Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a

*/

#include <iostream>
using namespace std;
#include<cstring>

// void pairStarHelper(char input[], int start){
//     if(input[start]=='\0'){
//         return;
//     }

//     pairStarHelper(input,start+1);

//     if(input[start]==input[start+1]){
//         for(int i=strlen(input);i>start+1;i--){
//                 input[i+1]=input[i];
//         }
//         input[start+1]='*';
//         input[start+2]=input[start];
//     }
// }

// void pairStar(char input[]) {
//     // Write your code here
//     pairStarHelper(input,0);
// }

void pairStar( char input[])
{
    int len = strlen( input );
    if( len == 0 || len == 1 )
    {
        return;
    }
    pairStar( input + 1 );
    if( input[0] == input[1] )
    {
        int len = strlen( input );
        for( int i = len - 1; i > 0; i-- )
        {
             input[i + 1] = input[i];
        }
        input[len + 1 ] = '\0';
        input[1] = '*';
        return;
    }
    else
        return;
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}