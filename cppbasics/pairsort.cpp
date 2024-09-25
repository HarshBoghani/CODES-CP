#include<bits/stdc++.h>
using namespace std;
//increasing second element
//if second element is same according to first element but in descending order
bool comp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    //if they are same
    if(p1.first>p2.first) return true;
    return false;
}
int main(){
    pair<int,int> pairs[]={{1,2},{2,8},{5,1},{4,1},{5,1},{3,8}};
    int x = sizeof(pairs)/sizeof(pairs[0]);
    sort(pairs,pairs+x,comp);
    for (int i = 0; i < x; i++)
    {
        cout<<pairs[i].first<<","<<pairs[i].second<<endl;
    }
}