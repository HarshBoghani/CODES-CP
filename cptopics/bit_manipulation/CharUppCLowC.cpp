#include<bits/stdc++.h>
using namespace std;

//in lower case 5th bit is always set and in upper case 5th is always unset 

void printBinary(int num){
    for (int i = 10; i>=0; --i)
    {
        cout<<((num>>i)&1);
    }
    cout<<endl;
}

int main(){
    for(char c='A'; c<='D'; c++){
        cout<<c<<endl;
        printBinary(int(c));
    }
    for(char c='a'; c<='d'; c++){
        cout<<c<<endl;
        printBinary(int(c));
    }

    char temp1 = 'A';
    
    //A---->a
    char temp2 = temp1 | (1<<5)/*binary of space*/;
    cout<<temp2<<endl;
    temp2 = (temp1 | ' ');
    cout<<temp2<<endl; 

    //a---->A
    char temp3 = temp2 & (~(1<<5))/*binary of underscore*/;
    cout<<temp3<<endl;
    temp3 = (temp2 & '_');
    cout<<temp3<<endl;
    return 0;

}