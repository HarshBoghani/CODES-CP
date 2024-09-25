#include<bits/stdc++.h>
using namespace std;
int M = 1e9+7;



//inbuilt pow() returns answer in double which is not always accurate for bigggger numbers
//by recursion(not recommended)
int binExpRecur(int a, int b){
    if(b==0) return 1;
    int res = binExpRecur(a,b/2);
    if(b&1){  //odd
        return a * res * 1LL * res;
    }else{
        return res*res;
    }
}

int modulocodeRec(int a, int b){
    if(b==0) return 1;
    int res = modulocodeRec(a,b/2,M);
    if(b&1){  //odd
        return (a * (res * 1LL * res)%M)%M;
    }else{
        return (res* 1LL *res)%M;
    }
}





//iterative code(recommended)
/*
3^13 = 3^(1101) = 3^8 * 3^4 * 3^0 * 3^1
*/
int binExpIter(int a, int b){
    int ans=1;
    while(b/*b>0*/){
        if(b&1/*if 0th bit set*/){
            ans = ans* 1LL *a;
        }
        a = a *1LL* a;
        b=b>>1;
    }
    return ans;
}

int modulocodeIter(int a, int b){
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


/*----------all about constrains----------*/

//      A IS BIG
//( a^b % M ) = ((a%M)^b)%M
//a<=10^18 , 2^1024
int modulocodeIter(int a, int b){
    // keep only one at a time

    //a<=10^18
    a=a%M;

    // a<=2^1024
    a = modulocodeIter(2,1024);

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



//      M IS BIG(<=10^18)
long long modulocodeIter(long long a, long long b){
    int ans=1;
    while(b/*b>0*/){
        if(b&1/*if 0th bit set*/){
            ans = binMultiply(ans,a);
        }
        a = binMultiply(a,a);
        b=b>>1;
    }
    return ans;
}
long long binMultiply(long long a, long long b){
    int ans=0;
    while(b>0){
        if(b&1){
            ans = (ans + a) % M ;
        }
        a = (a+a)%M;
        b=b>>1;
    }
    return ans;
}

//if b is big <=10^18 still we can do it easily by just changing int into long long in parameters only
int modulocodeIter(int a, long long b){
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
//but if the very very very big value is given like... (50)^(64^32) then long long will not be enough
//we can do it by Euler...

int main(){
    double d = 1e24;
    cout<<d<<endl;
    cout<< fixed << setprecision(30) << d <<endl;

    int a=2,b=13;
    int ans = binExpRecur(a,b);
    cout<<ans<<endl;

    a=2,b=13;
    ans = binExpIter(a,b);
    cout<<ans<<endl;
    return 0;
}