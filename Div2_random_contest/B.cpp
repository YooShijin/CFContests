#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define RFOR(i, a, b) for (ll i = a; i > b; i--)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(ld x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(bool x) { cerr << (x ? "true" : "false"); }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);

template <class T, class V> void _print(pair<T, V> p) {
    cerr << "{"; _print(p.ff); cerr << ", "; _print(p.ss); cerr << "}";
}
template <class T> void _print(vector<T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T> void _print(set<T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T> void _print(multiset<T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]";
}

ll tw(ll r) {
    if (r == 0) return 2;
    if (__builtin_popcountll(r) >= 2) return r;
    int z = 0;
    while ((r >> z) & 1) z++;
    return r + 2 * (1LL << z);
}

ll check(int k, ll n, ll x) {
    int bit = (n - k) & 1;
    ll r = x ^ bit;
    if (k == 1) return r > 0 ? r : -1;
    if (k == 2) return tw(r);
    if (k == 3 && r == 0) return 6;
    return __builtin_popcountll(r) >= k ? r : -1;
}

void solve() {
    ll n, x;
    cin >> n >> x;
    if (n == 1) {
        cout << (x > 0 ? x : -1) << '\n';
        return;
    }
    ll ans = LLONG_MAX;
    int lim = min(n, 30LL);
    FOR(k, 1, lim + 1) {
        ll val = check(k, n, x);
        if (val >= 0) {
            ll cur = (n - k) + val;
            ans = min(ans, cur);
        }
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)solve();
    return 0;
}
