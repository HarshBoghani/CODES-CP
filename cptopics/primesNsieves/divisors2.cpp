#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> divisors[N];
int sum[N];

int main(){
    divisors[1].push_back(1);
    for(int i=2; i<N; i++){
        for(int j=i ; j<N ; j+=i){
            divisors[j].push_back(i);
            sum[j]+=i;
        }
    }
    for(int i = 1; i < 10 ; i++){
        for(int div : divisors[i]){
            cout<< div << " ";
        }
        cout<<endl;
    }
    //divisors[x].count;
    //sum[j]
}