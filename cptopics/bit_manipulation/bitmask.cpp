#include<bits/stdc++.h>
using namespace std;

//when the arrays has less than 32 or 64 int value which are distinct for 1 array ,bit mask are used
//like... if there are multiple arrays and all have 
// A1=1,2,3    (0001110)
// A2=2,3,6    (1001100)
// A3=3,5      (0101000)
// in this case to find intersection we use bit masking
//to find intersection we can simply do AND and for union we can simply do OR

void printBinary(int n){
    for(int i=31;i>=0;i--){
        cout<<((n>>i)&1);
    }
    cout<<endl;
}

int main(){
    printBinary(50);
    return 0;
}