// make matrix of v*v;(v==number of vertices)
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e3 + 10;
vector<int> graph[N];
//for weighted
vector<pair<int,int>> graph2[N];
// space complexity O(N+M)
// N can go upto 10^5,but M can not go above 10^7
int main(){
//N = number of vertices
//M = number of Edges
//M lines of connected pair
/*
    N=6 M=9
    1 3
    1 5
    3 5
    3 4
    3 6
    3 2
    2 6
    4 6
    5 6
*/
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        //if weights are given
        // cin>>w;
        graph[v1].pb(v2);//pb({v2,w})
        graph[v2].pb(v1);//pb({v1,w})
    }
    for(int i=1;i<n;i++){
        cout<< i <<" --> ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}