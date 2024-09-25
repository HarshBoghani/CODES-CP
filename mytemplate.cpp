#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using oredered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order , order_of_key
#define ll long long int
#define ld long double
#define k_square                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define f(i, l, r) for (ll i = l; i < r; i++)
#define rf(j, l, r) for (ll j = l; j >= r; j--)
#define mod1 1000000007
#define mod2 998244353
#define pb push_back
#define eb emplace_back
#define em emplace
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define c1(x) cout << x << endl;
#define PI 3.141592653589793238462
#define ppb pop_back
#define in(n) \
    ll n;     \
    cin >> n;
#define inarr(arr, n)          \
    vector<ll> arr(n);         \
    for (ll i = 0; i < n; i++) \
        cin >> arr[i];
#define p0 cout << 0 << endl;
#define instr(n) \
    string n;    \
    cin >> n;

void init()
{
}

void solve()
{
    in(n);
    in(k);
    inarr(a, n);
    deque<ll> d;
    f(i, 0, n)
    {
        d.emplace_back(a[i]);
    }
    if (k >= n)
    {
        cout << *max_element(all(a)) << endl;
        return;
    }
    ll maxii = *max_element(all(a));
    map<ll, ll> m;
    while (1)
    {
        ll x = d.front();
        d.pop_front();
        ll y = d.front();
        d.pop_front();
        ll maxi = max(x, y);
        ll mini = min(x, y);
        m[maxi]++;
        if (m[maxi] == k)
        {
            return maxi;
        }
        if (maxi == maxii)
        {
            return maxii;
        }
        d.push_front(maxi);
        d.push_back(mini);
    }
}

int main()
{
    k_square;
    ll t = 1;
    cin >> t;
    init();
    while (t--)
    {
        solve();
    }
    return 0;
}