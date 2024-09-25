#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define int long long
#define endl '\n'
#define yes{cout<<"YES"<<endl;return;}
#define no{cout<<"NO"<<endl;return;}
const int MOD=1000000007;
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

#define MOD 1000000007

class fhstring {
private:
    vector<vector<long long>> dp;
    vector<vector<long long>> inv;
    long long n;
    vector<long long> bases;
    vector<long long> mods;

public:
    fhstring(const string& s, const vector<long long>& bases, const vector<long long>& mods)
        : bases(bases), mods(mods) {
        n = s.size();
        int num_bases = bases.size();
        dp.resize(num_bases, vector<long long>(n));
        inv.resize(num_bases, vector<long long>(n));

        vector<vector<long long>> p_pow(num_bases, vector<long long>(n, 1));

        for (int k = 0; k < num_bases; ++k) {
            inv[k][0] = 1;
            dp[k][0] = (s[0] - '0' + 1);
        }

        for (long long j = 1; j < n; ++j) {
            char c = s[j];
            for (int k = 0; k < num_bases; ++k) {
                p_pow[k][j] = (p_pow[k][j - 1] * bases[k]) % mods[k];
                inv[k][j] = binPow(p_pow[k][j], mods[k] - 2, mods[k]);
                dp[k][j] = (dp[k][j - 1] + (c - '0' + 1) * p_pow[k][j]) % mods[k];
            }
        }
    }

    static long long binPow(long long a, long long b, long long mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % mod;
            b >>= 1;
            a = (a * a) % mod;
        }
        return res;
    }

    vector<long long> substrhash(long long L, long long R) {
        if (R < L) return vector<long long>(bases.size(), 0);
        int num_bases = bases.size();
        vector<long long> res(num_bases);
        for (int k = 0; k < num_bases; ++k) {
            res[k] = dp[k][R];
            if (L > 0) {
                res[k] = (res[k] - dp[k][L - 1] + mods[k]) % mods[k];
                res[k] = (res[k] * inv[k][L]) % mods[k];
            }
        }
        return res;
    }
};

long long power(int a, int b, int m = MOD) {
    if (a == 0) return 0LL;
    if (b == 0) return 1LL;
    long long result;
    if (b % 2) {
        result = a * 1LL * power(a, b - 1, m);
    } else {
        int half = power(a, b / 2, m);
        result = half * 1LL * half;
    }
    return result % m;
}

vector<long long> b;
vector<long long> m;

void setRandomBases(int n) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<int> base_distribution(31, 100000);

    b.resize(n);
    for (int i = 0; i < n; ++i) {
        b[i] = base_distribution(rng);
    }
}

void solve() {
    setRandomBases(2);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int partitions = n / k;
    m = {MOD, MOD + 2};
    string s1(k, '0');
    string s2(k, '1');
    string res1, res2;
    for (int i = 0; i < n / k; i++) {
        if (i % 2) {
            res1 += s2;
        } else {
            res1 += s1;
        }
        if (i % 2) {
            res2 += s1;
        } else {
            res2 += s2;
        }
    }
    fhstring f1(s, b, m);
    reverse(s.begin(), s.end());
    fhstring f2(s, b, m);
    fhstring check1(res1, b, m);
    fhstring check2(res2, b, m);
    int ans = -1;
    for (int i = 0; i < n-1; i++) {
        vector<long long> left = f2.substrhash(n - 1 - i, n - 1);
        vector<long long> right = f1.substrhash(i + 1, n - 1);
        vector<long long> new_hash(b.size());
        for (int j = 0; j < b.size(); j++) {
            new_hash[j] = (right[j] + left[j] * power(b[j],n-i-1,m[j])) % m[j];
        }
        if (new_hash == check1.substrhash(0, n - 1) || new_hash == check2.substrhash(0, n - 1)) {
            ans = i + 1;
        }
    }
    cout << ans << endl;
}


int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}