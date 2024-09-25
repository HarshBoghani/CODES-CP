#include<bits/stdc++.h>
using namespace std;
//O(sqrt(n))
void print_count_sum_alldivisors(int n){
    int cnt=0;
    int sum=0;
    for(int i=1; i*i <= n; i++){
        if(n%i==0){
            cout<<i<<" "<<n/i<<endl;
            cnt++;
            sum+=i;
            if((n/i)!=i){
                sum+=(n/i);
                cnt++;
            }
        }
    }
    cout<< cnt << " " << sum << endl;
}
/*----------count-----------
 x = p1^n1 * p2^n2 * p3^n3 * ....
 cnt = (n1+1)(n2+1)(n3+1)....
 36 = 2^2 * 3^2
 cnt = (2+1)*(2+1) = 9
*/
/*---------sum--------------
(1 + p1 + p1^2 + p1^3 + ....)*
(1 + p2 + p2^2 + p2^3 + ....)*
(1 + p3 + p3^2 + p3^3 + ....)*
.
.
V
sum for 36 = (1+2+4)(1+3+9) = 91
use GP formula in code...

*/


int main(){
    
    print_count_sum_alldivisors(36);
    return 0;
}