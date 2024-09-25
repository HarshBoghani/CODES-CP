#include<bits/stdc++.h>
using namespace std;

void build(int ind, int low, int high , vector<int>&v , vector<int>& seg){
    if(low==high) {
        seg[ind]=v[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid,v,seg);
    build(2*ind+2,mid+1,high,v,seg);
    seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
}

int query(int ind,int low,int high,int l, int r, vector<int>& seg){
    //no overlap
    if(r<low || high<l) return INT_MAX;

    //complete overlap
    if(low>=l && high<=r) return seg[ind];

    //partial
    int mid = (low+high)>>1;
    int left = query(2*ind+1,low,mid,l,r,seg);
    int right = query(2*ind+2,mid+1,high,l,r,seg);
    return min(left,right);
    
}

int main(){
    int n ;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> seg(4*n);
    build(0,0,n-1,v,seg);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r,seg)<<endl;
    }
}