#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

vector<int> primefactors(int n){
    vector<int> pf;
    for(int i=2; i*i<=n;i++){
        while(n%i==0){
            pf.push_back(i);
            n/=i;
        }
    }
    if(n>1){
        pf.push_back(n);
    }
    return pf;
}


int main(){
    cout<<isPrime(1080)<<endl;
    return 0;
}