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
clear all MSBs upto 3rd bits
00000111011
00000001111
00000010000 -1
00000010000
*/
int main(){
    printBinary(59);
    int a = 59;
    int i = 3;
    int b = (a & (((1<<(i+1))-1)));
    printBinary(b);
}