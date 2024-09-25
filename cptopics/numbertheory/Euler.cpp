#include<bits/stdc++.h>
using namespace std;
/*
    ETF
    ETF(M) = M * productofallprimefactors(1-(1/n))
    for 6 => 6*(1-(1/2))*(1-(1/3)) => 2


    for any M
    a^b % M  =  (a^(b%ETF(M)))%M
    if M is prime
    a^b % M  =  (a^(b%(M-1)))%M
*/
int modulocodeIter(int a, long long b,int M){
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
    //50^(64^32)
    int M = 1e9 + 7; //prime
    cout << modulocodeIter(50,modulocodeIter(64,32,M-1),M);
    int M = 1337; //not prime , find ETF then pass..
    return 0;
}