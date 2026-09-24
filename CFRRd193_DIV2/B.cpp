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

void solve()
{
    ll n;
    cin >> n;
    vll a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    ll temp = 1;
    vector<pair<ll, ll>> pre;
    pre.push_back({0, 1});
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            temp++;
        }
        else
        {
            pre.push_back({a[i - 1], temp});
            ans += (temp - 1);
            temp = 1;
        }
    }
    pre.push_back({a[n - 1], temp});
    ans += (temp - 1);
    pre.push_back({0, 1});

    ll rem = 0;
    for (int i = 2; i < pre.size() - 1; i++)
    {
        ll temp = 0;
        if (pre[i].second > 1 && pre[i - 1].second > 1)
        {
            temp = 2;
        }
        else if (pre[i].second > 1 && pre[i].first != pre[i - 2].first)
        {
            temp = 1;
        }
        else if (pre[i - 1].second > 1 && pre[i - 1].first != pre[i + 1].first)
        {
            temp = 1;
        }

        rem = max(temp, rem);
    }
    // cout << ans << "-a--r--" << rem << " ";
    cout << n - (ans - rem) << endl;
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