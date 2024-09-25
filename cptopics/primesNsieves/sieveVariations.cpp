#include<bits/stdc++.h>
using namespace std;

//lowest and highest prime
// 10 = 2*5 ---> 2=lowest , 5=highest
const int N = 1e7 + 10;
vector<bool> isPrime(N,1);
vector<int> lp(N,0) , hp(N,0);
int main(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2 ; i < N ; i++){
        if(isPrime[i]==true){
            lp[i]=hp[i]=i;
            for(int j = 2*i ; j<N ; j+=i){
                isPrime[j] = false;
                hp[j]=i;
                if(lp[j]==0){
                    lp[j]=i;
                }
            }
        }
    }
    for(int i=1 ; i<100; i++){
        cout<<lp[i]<<" "<<hp[i]<<endl;
    }

    //prime factorization using it
    int num;
    cin>>num;
    //stored in vector
    vector<int> prime_factors;
    //stored in map we can use either
    unordered_map<int,int> pfs;
    while(num>1){
        int prime_factor = hp[num];
        while(num % prime_factor==0){
            num/=prime_factor;
            prime_factors.push_back(prime_factor);
            pfs[prime_factor]++;
        }
    }
    //for vector
    for(int factor: prime_factors){
        cout<<factor<<" ";
    }
    cout<<endl;
    //for map
    for(auto factor : pfs){
        cout<< factor.first << " " << factor.second << endl;
    }
    return 0;
}