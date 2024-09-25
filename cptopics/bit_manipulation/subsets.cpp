#include<bits/stdc++.h>
using namespace std;

/*

Assume a[3]={2,4,5}
There are total 2^n possible subsets
[]  000
[2] 001
[4] 010
[2,4] 011
[5] 100
.
.
.
v
[2,4,5] 111

*/

//O(n*2^n) recursion is better for this problem
vector<vector<int>> subsets(vector<int> &n){
    int p = n.size();
    int subsets_cnt = (1<<p)/*2^n*/;
    vector<vector<int>> ans;
    for(int mask=0; mask<subsets_cnt; mask++){
        vector<int> subset;
        for(int i=0;i<p;i++){
            if((mask&(1<<i))!=0){
                subset.push_back(n[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n ; i++){
        cin >> v[i];
    }
    auto ans = subsets(v);

    for(auto x : ans){
        for(int el : x){
            cout<< el << " ";
        }
        cout<<endl;
    }
    return 0;
}
