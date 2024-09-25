#include<bits/stdc++.h>
using namespace std;

//for even last bit will be always 0 and in odd it will be always 1
//AND-&,OR-|,XOR-^,NOT-!

/*
-----left shift,right shift-----

3<<1 ---->    11---->110
3<<2 ---->    11---->1100
3>>1 ---->    11---->1
6>>1 ---->    110--->11
*/

/*  ----- all about power of 2-----

in integer maximum number can be stored is 2^31 - 1
it should be 32 but its 31 because its always signed data type so it will always need 1 bit to store sign
if we use unsigned int then it will store 2^32 - 1


----to get any number which is power of 2----

1<<0 = 1
1<<1 = 10 =2
1<<2 = 100 =4
1<<n = 100...0 = 2^n

*/
int main(){
    cout<<INT_MAX<<endl;
    int a = (1LL<<31)-1;
    cout<<a<<endl;
    unsigned int b = (1LL<<32)-1;
    cout<<b<<endl;
    return 0;
}