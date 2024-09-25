#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define li long int
#define ull unsigned long long
#define ld long double

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define fix fixed << setprecision(10)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#define f(i, l, r) for (ll i = l; i < r; i++)
#define rf(j, l, r) for (ll j = l; j >= r; j--)
#define all(v) v.begin(), v.end()
#define disp(v)            \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << ' ';           \
    cout << endl;
#define sum(v, a, b) accumulate(v + a, v + b, 0)

bool comp_pair(pair<ll, ll> p1, pair<ll, ll> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    if (p1.first > p2.first)
        return false;
    return true;
}
ll sub(ll a, ll b) { a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod; }
ll add(ll a, ll b) { return (a % mod + b % mod) % mod; }
ll mult(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
ll power(ll x, ll y) { ll ans = 1; while (y > 0) { if (y & 1) { ans = ans * x; ans %= mod; } y = y >> 1; x = x * x; x %= mod; } return ans % mod; }
ll modInv(ll n, ll p) { return power(n, p - 2); }
ll fact(ll n) { if (n == 0) return 1; return mult(n, fact(n - 1)); }
ll nCr(ll n, ll r) { if (r == 0) return 1; return (fact(n) * modInv(fact(r), mod) % mod * modInv(fact(n - r), mod) % mod) % mod; }

int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }
bool is_square(li n) { if (power((int)sqrtl(n), 2) == n) return true; return false; }
bool isint(double x) { if (ceil(x) == floor(x)) return true; return false; }

void printBinary(int num) { for (int i = 31; i >= 0; --i) { cout << ((num >> i) & 1); } cout << endl; }
string intToBitString(int n) { string s; const int curr = sizeof(n) * 8; for (int i = curr - 1; i >= 0; --i) { s += (n & (1 << i)) ? '1' : '0'; } return s; }

void __print(ll t) { cerr << t; }
void __print(int t) { cerr << t; }
void __print(string t) { cerr << t; }
void __print(char t) { cerr << t; }
void __print(double t) { cerr << t; }
void __print(ull t) { cerr << t; }

template <class T, class V> void __print(pair<T, V> p);
template <class T, class V, class M> void __print(tuple<T, V, M> t);
template <class T> void __print(vector<T> v);
template <class T> void __print(set<T> v);
template <class T, class V> void __print(map<T, V> v);

template <class T> void __print(multiset<T> v);
template <class T, class V> void __print(pair<T, V> p) { cerr << "{"; __print(p.first); cerr << ","; __print(p.second); cerr << "}"; }
template <class T, class V, class M> void __print(tuple<T, V, M> t) { cerr << "{"; __print(get<0>(t)); cerr << ","; __print(get<1>(t)); cerr << ","; __print(get<2>(t)); cerr << "}"; }
template <class T> void __print(vector<T> v) { cerr << "[ "; for (T i : v) { __print(i); cerr << " "; } cerr << "]"; }
template <class T> void __print(set<T> v) { cerr << "[ "; for (T i : v) { __print(i); cerr << " "; } cerr << "]"; }
template <class T> void __print(multiset<T> v) { cerr << "[ "; for (T i : v) { __print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void __print(map<T, V> v) { cerr << "[ "; for (auto i : v) { __print(i); cerr << " "; } cerr << "]"; }

pair<int,int> dfs(int node,int parent,int sum,vector<vector<int>>& adj){
    int maxinode=node;
    int maxidist=sum;
    for(auto it : adj[node]){
        if(it==parent) continue;
        pair<int,int> tp = dfs(it,node,sum+1,adj);
        if(tp.ss>maxidist){
            maxidist=tp.ss;
            maxinode=tp.ff;
        }
    }
    return {maxinode,maxidist};
}


vector<int> shortestPath(vector<vector<int>>& adj, int N, int src){
    vector<int> minDist(N+1,INT_MAX);
    minDist[src]=0;
    queue<vector<int>> q;
    q.push({src,0});
    while(!q.empty()){
        vector<int> tp = q.front();
        q.pop();
        for(auto it : adj[tp[0]]){
            if(tp[1]+1<minDist[it]){
                minDist[it]=tp[1]+1;
                q.push({it,tp[1]+1});
            }
        }
    }
    
    for(int i=0;i<N;i++){
        if(minDist[i]==INT_MAX) minDist[i]=-1;
    }
    return minDist;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        ll k,c;
        cin>>k>>c;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        pair<int,int> point1 = dfs(1,-1,0,adj);
        int x = point1.ff;
        pair<int,int> point2 = dfs(x,-1,0,adj);
        int y = point2.ff;


        vector<int> distx = shortestPath(adj,n,x);
        vector<int> disty = shortestPath(adj,n,y);
        
    }
    return 0;
}
