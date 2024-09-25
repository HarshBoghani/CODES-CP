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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl

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

set<char> st = {'n', 'a', 'r', 'e', 'k'};

ll solve(int i, int j, int flag, vector<string>& s, vector<vector<vector<ll>>>& dp, string& tg) {
    if (i == s.size()) {
        return -flag;
    }
    int m = s[0].size();
    if (dp[i][j][flag] != -1) return dp[i][j][flag];
    ll ans = -1e18;
    if(j==0){
        ans=max(ans,solve(i+1,0,flag,s,dp,tg));
    }
    if (j < m - 1 && s[i][j] == tg[flag]) {
        if (flag == 4) {
            ans = max(ans, solve(i, j + 1, 0, s, dp, tg) + 1);
        } else {
            ans = max(ans, solve(i, j + 1, flag + 1, s, dp, tg) + 1);
        }
    }else if(j<m-1){
        ans = max(ans, solve(i, j + 1, flag, s, dp, tg) - (st.find(s[i][j]) != st.end()));
    }
    else if (j == m - 1  && s[i][j] == tg[flag]) {
        if (flag == 4) {
            ans = max(ans, solve(i + 1, 0, 0, s, dp, tg) + 1);
        } else {
            ans = max(ans, solve(i + 1, 0, flag + 1, s, dp, tg) + 1);
        }
    } else {
        ans = max(ans, solve(i + 1, 0, flag, s, dp, tg) - (st.find(s[i][j]) != st.end()));
    }
    return dp[i][j][flag] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<string> s(n);
        string tg = "narek";
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(5, -1)));
        cout << solve(0, 0, 0, s, dp, tg) << endl;
    }
    return 0;
}
