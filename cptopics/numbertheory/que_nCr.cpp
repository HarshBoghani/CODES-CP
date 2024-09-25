// ther are N children and K toffees(K<N)
//count the number of ways to distribute tofee
//among N students such that each students get 
//1 toffee only --> nCk
// N < 1e6 , K < N < 1e6 , % M ,  M = 1e9 + 7
// nCr = n! / (n-r)!*(r)!
// TestCases< 10^5
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int M = 1e9 + 7;
int fact[N];

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
    fact[0]=1;
    for(int i = 1 ; i< N ; i++){
        fact[i] = (fact[i-1] * 1LL * i)%M;
    }

    int t;
    cin>>t;
    while(t-- > 0){
        int n,k;
        cin>>n>>k;
        int ans = fact[n];
        int den = (fact[n-k] *  1LL * fact[k])%M;
        int inv = modulocodeIter(den,M-2,M);
        ans = (ans * 1LL *inv)%M;
        cout<<ans;
    }
    return 0;
}