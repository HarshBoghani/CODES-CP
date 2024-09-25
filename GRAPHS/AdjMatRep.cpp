// make matrix of v*v;(v==number of vertices)
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int graph[N][N];

// space complexity O(N^2)
//if N is too big then matrix can not be made(10^5/10^6 are invalid)
int main(){
//N = number of vertices
//M = number of Edges
//M lines of connected pair
/*
    --> IF IT IS TOLD THAT GRAPH IS UNDIRECTED THEN WE NEED TO 
    --> CONSIDER BOTH DIRECTION ELSE WE CAN CONSIDER ONLY ONE
    --> WE CAN PUT WEIGHT OF GRAPH IN THE MATRIX INSTEAD OF PUTTING 1
    N=6 M=9     weights(if given)
    1 3           1
    1 5           2
    3 5           5
    3 4           .
    3 6           .
    3 2           .
    2 6
    4 6
    5 6
*/
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        //if weights of edges are given
        // cin>>w
        graph[v1][v2]=1; //w
        graph[v2][v1]=1; //w
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}