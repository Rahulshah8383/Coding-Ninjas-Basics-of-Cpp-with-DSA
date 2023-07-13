/*
Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 0 to V-1) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 
*/

#include <iostream>
using namespace std;

void Helper(int **edges, int sv, int n, bool *visited){
    visited[sv] = true;

    for(int i=0;i<n;i++){
        if(edges[sv][i] && !visited[i]){
            Helper(edges, i, n, visited);
        }
    }
}

int CountIslands(int **edges, int n) {
  bool *visited = new bool[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  
  int count = 0;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            Helper(edges, i, n, visited);
        }
    }
    delete []visited;

    return count;
}

int main() {
    int V, E;
    cin>>V>>E;

    int **edges = new int*[V];
    for(int i=0;i<V;i++){
        edges[i] = new int[V];
        for(int j =0;j<V;j++){
            edges[i][j]  = 0;
        }
    }

    for(int i=0;i<E;i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout<<CountIslands(edges, V)<<endl;

    for(int i=0;i<V;i++){
        delete []edges[i];
    }
    delete []edges;
}