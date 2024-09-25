#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int a = 100000;
    int b = 100000;
    //outofrange
    int c1 = a*b;
    cout<<c1<<endl;
    //using long long(wrong method)
    ll c2 = a*b;
    cout<<c2<<endl;
    //right method
    ll c3 = a*1LL*b;
    cout<<c3<<endl;
    //why not double ?
    double x = 100000;
    double y = 100000;
    //1e10
    double z1 = x*y;
    cout<<z1<<endl;
    //get number (not in e10 form)
    cout<<fixed<<z1<<endl;
    //remove after decimals
    cout<<fixed<<setprecision(0)<<z1<<endl;
    
}
