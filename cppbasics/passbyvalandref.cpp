#include<bits/stdc++.h>
using namespace std;
//pass by value
void dosomething(int n){
    n+=10;
}
//pass by reference(easy)
void wecandosomething(int &n){
    n+=10;
}
//pass by reference(not recommended)
void wecandoitbutwedont(int* n){
    *n+=10;
}
//in array its always ref. there is no val..
void arraycanalwaysdoit(int arr[]){
    arr[1]=2;
}
int main(){
    int n=5;

    dosomething(n);
    cout<<n<<endl;

    wecandosomething(n);
    cout<<n<<endl;

    wecandoitbutwedont(&n);
    cout<<n<<endl;
    
    int arr[3]={0,0,0};
    arraycanalwaysdoit(arr);
    cout<<arr[0]<<endl<<arr[1]<<endl<<arr[2]<<endl;
}

