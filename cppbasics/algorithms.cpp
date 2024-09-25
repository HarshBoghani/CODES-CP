#include<bits/stdc++.h>
using namespace std;

//sorting
void sorting(){
    int a[];
    int n;
    vector<int> v;
    sort(a,a+n); //sorts from pointer a to pointer a+n-1
    sort(v.begin(),v.end());
    sort(a+2,a+4);
    sort(a,a+n,greater<int>); // sorts in descending
}

//built in pop count
void builtinpopcount(){
    //returns number of set bits of given number
    int n = 7;
    int cntof1 = __builtin_popcount(n);
    
    long long x = 769821392130283013;
    int cntof1 = __builtin_popcount(x);
}

//nextpermutation
void permutations(){
    string s = "harsh";
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
}

//max,min element in an array
void maxminelement(){
    int maxi = *max_element(a,a+n);
    int mini = *min_element(a,a+n);
}

int main(){
   return 0;
}