#include<bits/stdc++.h>
using namespace std;


void printBinary(int num){
    for (int i = 10; i>=0; --i)
    {
        cout<<((num>>i)&1);
    }
    cout<<endl;
}

//faster than using modulo
bool is_num_ODD_or_NOT(int n){
    if(n&1) return true;
    return false;
}

//multiply and divide by 2
void multiply_divide_by_2(int n){
    //multiply
    cout<<(n<1)<<endl;
    //divide
    cout<<(n>>1)<<endl;
    /*
    101 ---> (2^2*1 +  2^1*0   +  2^0*1)*2
    1010 --> (2^3*1 +  2^2*0   +  2^1*1  +  2^0*0)
    10 ----> (2^1*1 +  2^0*0)
    */
}
int main(){
    int a = 5;
    multiply_divide_by_2(5);

    
    return 0;
}