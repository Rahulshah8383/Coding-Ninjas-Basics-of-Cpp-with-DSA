/*
Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/

#include <iostream>
#include<vector>

using namespace std;

vector<int>* Helper(int **edges, int V, int sv, int ev, bool *visited){
    if(sv == ev){
        vector<int> *smallAns = new vector<int>();
        smallAns->push_back(ev);
        return smallAns;
    }
    visited[sv] = true;

    for(int i=0;i<V;i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i]==1 && !visited[i]){
          vector<int> *smallOutput = Helper(edges, V, i, ev, visited);
          if (smallOutput != NULL) {
                smallOutput->push_back(sv);
                return smallOutput;
            }
        }
    }
    return NULL;
}

vector<int> *GetPathDFS(int **edges, int V, int v1, int v2) {
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++) {
    visited[i] = false;
 }

 vector<int>* ans = Helper(edges, V, v1, v2, visited);

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
        cin>>a>>b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    int v1, v2;
    cin>>v1>>v2;

    vector<int>* ans = GetPathDFS(edges, V, v1, v2);

    if(ans != NULL){
        for(int i=0;i<ans->size();i++){
            cout<<ans->at(i)<<" ";
        }
    }

    for(int i=0;i<V;i++){
        delete []edges[i];
    }
    delete []edges;

    return 0;
}