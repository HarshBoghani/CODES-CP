#include<bits/stdc++.h>
using namespace std;

void print(){
    cout<<"HARSH"<<endl;
}
void printname(string name){
    cout<<name<<endl;
}
void sum(int n1,int n2){
    int n3=n1+n2;
    cout<<n3<<endl;
}
int totalsum(int n1,int n2){
    int n3=n1+n2;
    return n3;
}
int main(){
    //by value , void
    print();
    string name="harsh";
    printname(name);
    sum(5,6);
    int result = totalsum(5,6);
    cout<<result<<endl;
    return 0;
}