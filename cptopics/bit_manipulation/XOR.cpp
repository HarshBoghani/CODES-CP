#include<bits/stdc++.h>
using namespace std;

/*
    n^0=n
    n^n=0
    (a^b)^c = b^c^a = a^c^b
    normally used for odd/even count and all
*/

// 0^1^2^3...^n
int computeXOR(int n) 
{ 
  if ((n+1) % 4 == 0) 
    return 0; 
 
  if (n % 4 == 0) 
    return n; 
 
  if (n%4 == 1) 
    return 1; 
 
  if(n%4==2)
    return n+1;
} 

void swapbyXOR(int a, int b){
    a = a^b;
    b = b^a;
    // b = b^(a^b) =>   b = a
    a = a^b;   
    //a = (a^b)^(a) => a = b
}

int main(){
    return 0;
}