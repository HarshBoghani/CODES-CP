#include<bits/stdc++.h>
using namespace std;

class SGTree{
    vector<int> seg;
public: 
    SGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind, int low, int high , vector<int>&v){
        if(low==high) {
            seg[ind]=v[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1,low,mid,v);
        build(2*ind+2,mid+1,high,v);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }

    int query(int ind,int low,int high,int l, int r){
        //no overlap
        if(r<low || high<l) return INT_MAX;

        //complete overlap
        if(low>=l && high<=r) return seg[ind];
        
        //partial
        int mid = (low+high)>>1;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
        
    }

    void update(int ind,int low,int high, int i, int val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid = (low+high)>>1;
        if(i<=mid) update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);

    }
};

int main(){
    // to solve problem in which multiple SEGtrees needed
    int n1,n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i=0;i<n1;i++){
        cin>>v1[i];
    }
    for(int i=0;i<n2;i++){
        cin>>v2[i];
    }
    SGTree sg1(n1);
    sg1.build(0,0,n1-1,v1);
    SGTree sg2(n2);
    sg1.build(0,0,n2-1,v2);

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l1,l2,r1,r2;
            cin>>l1>>r1>>l2>>r2;
            int min1 = sg1.query(0,0,n1-1,l1,r1);
            int min2 = sg2.query(0,0,n2-1,l2,r2);
            cout<<min(min1,min2)<<endl;
        }else{
            int arrNo,i,val;
            cin>>arrNo>>i>>val;
            if(arrNo==1){
                sg1.update(0,0,n1-1,i,val);
                v1[i]=val;
            }else{
                sg2.update(0,0,n2-1,i,val);
                v2[i]=val;
            }
        }
    }
}