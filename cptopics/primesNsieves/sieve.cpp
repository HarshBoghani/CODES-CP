#include<bits/stdc++.h>
using namespace std;

const int N = 1e9+8;
//TestCases < 10^7 , N < 10^7 
vector<bool> isPrime(N,1);
//O(n*(log(log(n))))
int main(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2 ; i < N ; i++){
        if(isPrime[i]==true){
            for(int j = 2*i ; j<N ; j+=i){
                isPrime[j] = false;
            }
        }
    }
    int t;
    t=1;
    while(t-->0){
        vector<int> p;
        for(int i=2;i<=1e9+7;i++){
            if(isPrime[i])p.push_back(i);
        }

        for(auto it : p){
            cout<<it<<" ,";
        }
        cout<<endl;
    }
    return 0;
}