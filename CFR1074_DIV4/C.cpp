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
        _print(i), cerr << " ";
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
        _print(i), cerr << " ";
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
        _print(i), cerr << " ";
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
        _print(i), cerr << " ";
    cerr << "]";
}

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    FOR(i, 0, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 1;

    // FOR(i, 0, n)
    // {
    //     ll t = -a[i];
    //     vll s(n + 2, 0);

    //     FOR(j, 0, n)
    //     {
    //         ll temp = a[j] + t;
    //         if (0 <= temp && temp <= n + 1)
    //         {
    //             s[temp] = 1;
    //         }
    //     }

    //     ll mx = 0;
    //     while (mx <= n + 1 && s[mx])
    //     {
    //         mx++;
    //     }

    //     ans = max(ans, mx);
    // }
    ll temp = 1;
    FOR(i, 1, n)
    {
        if (a[i] == a[i - 1])
        {
            continue;
        }
        if (a[i] == a[i - 1] + 1)
        {
            temp++;
            ans = max(ans, temp);
        }
        else
        {
            temp = 1;
        }
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
