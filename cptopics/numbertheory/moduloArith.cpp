#include<bits/stdc++.h>
using namespace std;

//modulo arithmatic formulas
void moduloarith(int A, int B, int M , int Binv){
   //(A+B)%M = ((A%M)+(B%M))%M;
   //(A*B)%M = ((A%M)*(B%M))%M;
   //(A-B)%M = ((A%M)-(B%M)+M)%M;
   //(A/B)%M = ((A%M)*((Binv)%M))%M;
}
int main(){
    int n;
    cin>>n;
    int M=47;
    long long fact = 1;
    for(int i=2;i<=n;i++){
        fact=(fact*i)%M;
    }
    cout<<fact;
    //even in long long fact can be stored only upto 20, fact of 21 can not be stored and it will give negative garbage value
    //in question the answer after doing modulo M is asked
    //using formulas we can use modulo according to need

    /*
        EG. (1x2x3x4x5)%47
        using formula
        ((1x2x3x4)%47  x  5%47)%47
        (((1x2x3)%47 x 4%47)%47  x 5%47)%47
        ((((1x2)%47  x 3%47)%47 x 4%47)%47  x 5%47)%47
        .
        .
        .
    */
    /*
        this can be used in sum too if we are adding ever time in loop so we can use the same in addition too
    */
    return 0;
}