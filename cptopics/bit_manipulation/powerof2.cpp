#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 15;
    if(n & (n-1)){
        cout<<"not power of 2"<<endl;
    }
    else{
        cout<<"power of 2"<<endl;
    }
    return 0;
}