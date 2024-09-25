#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for (int i = 10; i>=0; --i)
    {
        cout<<((num>>i)&1);
    }
    cout<<endl;
}
/*
00000111011
11111100000
00000011111
00000100000-1

*/ 
int main(){
    printBinary(59);
    int a = 59;
    int i = 4;
    int b = (a & (~((1<<(i+1))-1)));
    printBinary(b);
}