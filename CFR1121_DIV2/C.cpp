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
#define debug(x)         \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(ld x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(bool x) { cerr << (x ? "true" : "false"); }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);

template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ", ";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

ll M = 998244353;
ll binpow(ll a, ll b, ll M = 998244353)
{
    ll ans = 1;
    ll r = a;

    while (b)
    {
        if (b & 1)
        {
            ans = (ans * r) % M;
        }

        b >>= 1;
        r = (r * r) % M;
    }

    return ans;
}
ll fact(ll n, ll M = 998244353)
{
    ll ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans = (ans * i) % M;
    }
    return ans;
}
void solve()
{
    ll ans = 0;
    ll n;
    cin >> n;

    vll a(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    vll pref(n, 0);
    pref[0] = a[0] % M;

    for (int i = 1; i < n; i++)
    {
        pref[i] = (pref[i - 1] + a[i]) % M;
    }

    ll nmin1 = fact(n - 1);

    for (int i = 1; i < n; i++)
    {
        ll cnt = i;

        ll temp = (pref[i - 1] - (cnt * a[i]) % M + M) % M;

        ll num = nmin1 * binpow(cnt, M - 2) % M;
        num = num * temp % M;

        ans = (ans + num) % M;
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}