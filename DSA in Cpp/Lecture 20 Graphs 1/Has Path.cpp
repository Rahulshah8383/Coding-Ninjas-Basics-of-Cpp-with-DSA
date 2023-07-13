/*
Code : Has Path
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= V - 1
0 <= v2 <= V - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/

#include <iostream>
#include<queue>
using namespace std;

/*
bool BFSHelper(int **edges, int V, int sv, int ev, bool *visited) {
  if (sv == ev) {
    return true;
  }

  visited[sv] = true;


  queue<int> pendingVertices;
  pendingVertices.push(sv);
  visited[sv] = true;

  while (!pendingVertices.empty()) {
    int currentVertices = pendingVertices.front();
    pendingVertices.pop();
    for (int i = 0; i < V; i++) {
      if (i == currentVertices) {
        continue;
      }

      if (edges[currentVertices][i] == 1 && !visited[i]) {
        if (BFSHelper(edges, V, i, ev, visited)) {
          return true;
        }
      }
    }
  }
}
*/

bool DFSHelper(int **edges, int V, int sv, int ev, bool *visited){
    if(sv == ev){
        return true;
    }

    visited[sv] = true;

    for(int i=0;i<V;i++){
        if(sv == i){
            continue;
        }
        if(edges[sv][i]==1 && !visited[i]){
          if (DFSHelper(edges, V, i, ev, visited)) {
            return true;
          }
        }
    }
    return false;
}

bool HasPath(int **edges,int V,int v1,int v2){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }

    // bool ans = BSFHelper(edges, V, v1, v2, visited);
    bool ans = DFSHelper(edges, V, v1, v2, visited);

    delete []visited;    
    return ans;
}

int main() {
    int V, E;
    cin>>V>>E;

    int **edges = new int*[V];
    for(int i=0;i<V;i++){
        edges[i] = new int[V];
        for(int j=0;j<V;j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<E;i++){
        int a, b;
        cin >> a >> b;

        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    
    int v1, v2;
    cin>>v1>>v2;

    if(HasPath(edges, V, v1, v2)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

    for(int i=0;i<V;i++){
        delete []edges[i];
    }
    delete []edges;

    return 0;
}