#include<bits/stdc++.h>
using namespace std;

//modular multiplicative inverse
//  (A/B)%M = ((A * (B^-1))% M
//          = (((A% M) * ((B^-1)% M))% M
//          = (((A% M) * (MMI))% M
const int M = 1e9 + 7;
int modulocodeIter(int a, int b,int M){
    int ans=1;
    while(b/*b>0*/){
        if(b&1/*if 0th bit set*/){
            ans = (ans* 1LL *a)%M;
        }
        a = (a *1LL* a)%M;
        b=b>>1;
    }
    return ans;
}


int main(){
    int a;
    //INVERSE OF A
    modulocodeIter(a,M-2,M);

    return 0;
}

