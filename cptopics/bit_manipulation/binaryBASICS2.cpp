#include<bits/stdc++.h>
using namespace std;

/*
binary numbers are read from right to left
right most is LSB(0th bit)
left most is MSB(nth bit)
    MSB---->110101110<-----LSB

    indexing is from left, means LSB is 0th, bit after that is 1st,then 2nd....nth
*/

void printBinary(int num){
    for (int i = 10; i>=0; --i)
    {
        cout<<((num>>i)&1);
    }
    cout<<endl;
}
/*
SET=1
UNSET=0
*/
bool checkIF_ith_bit_is_SETorNOT(int n,int i){    
   int x = 1<<i;
   if((n&x)!=0) {return true;}
   return false;
}

bool make_ith_bit_SET(int &n,int i){
   int x = 1<<i;
   n=n|x;
}

bool make_ith_bit_UNSET(int &n,int i){
   int x = ~(1<<i);
   n=n&x; 
}

//toggle: make 0-->1 and make 1-->0
bool toggle_the_ith_bit_of_binary(int &n,int i){
    n=n^(1<<i);
}

bool count_set_bits(int n){
    int count=0;
    for(int i=31; i>=0; --i){
        if(checkIF_ith_bit_is_SETorNOT(n,i)==true){
            count++;
        }
    }
    printBinary(n);
    cout<<count<<endl;
    //----INBUILT------
    //for integer
    cout<<__builtin_popcount(n)<<endl;
    //for longlong
    long long p=4000000000000;
    cout<<__builtin_popcountll(p)<<endl;
}
int main(){
    int a=9;
    printBinary(a);
    cout<<checkIF_ith_bit_is_SETorNOT(a,0)<<endl;
    printBinary(a);
    make_ith_bit_SET(a,6);
    printBinary(a);
    make_ith_bit_UNSET(a,6);
    printBinary(a);
    toggle_the_ith_bit_of_binary(a,6);
    toggle_the_ith_bit_of_binary(a,0);
    printBinary(a);
    count_set_bits(a);
    return 0;
}