#include<bits/stdc++.h>
using namespace std;

/*
------GCD------
4,12
4 =   2^2 * 3^0
12 =  2^2 * 3^1
GCD = 2^2 * 3^0  (take minimum power)
LCM = 2^2 * 3^1  (take maximum ower)

12,18
GCD = 2*3 = 6
LCM = 4*9 = 36

a * b = LCM * GCD

for 3 numbers 
gcd(a,gcd(b,c))


minimum fraction
12/18 = 2/3
(12/gcd(12,18))/18(gcd(12,18)) = 2/3
*/

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

/*-------INBUILT----------
     __gcd(n1,n2);
*/
int main(){
    cout<<gcd(18,12)<<endl;
    cout<<gcd(4,12)<<endl;
    cout<<gcd(12,18)<<endl;
    cout<<__gcd(4,12)<<endl;
    return 0;
}