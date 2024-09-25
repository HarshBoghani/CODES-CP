#include<bits/stdc++.h>
using namespace std;

// V - vertices
// E - Edges

const int N = 1e5 + 10;

vector<int> g[N];
vector<bool> vis(N,0);
/*-----------------template------------------*/

void dfs(int vertex){
    /*
        TAKE ACTION ON VERTEX AFTER ENTERING THE VERTEX
    */
    /*IE.*/ vis[vertex]=1;
    for(auto child : g[vertex]){
        /*
            TAKE ACTION ON CHILD BEFORE ENTERING THE CHILD NODE
        */
        /*IE.*/ if(vis[child]) continue;

        dfs(child);
        /*
            TAKE ACTION ON CHILD AFTER EXITING CHILD NODE
        */
    }
    /*
        TAKE ACTION ON VERTEX BEFORE EXITING THE VERTEX
    */
}//   O(V+E)

int main(){
    int V;
    int E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
}