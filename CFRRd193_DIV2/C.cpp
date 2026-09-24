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
    ll m, n, x, y;
    cin >> m >> n >> x >> y;
    vll a(x, 0);
    vll b(y, 0);
    vector<pair<ll, ll>> v;

    for (int i = 0; i < x; i++)
    {

        cin >> a[i];
        v.push_back({a[i], 1});
    }
    for (int i = 0; i < y; i++)
    {
        cin >> b[i];
        v.push_back({b[i], 2});
    }

    sort(v.rbegin(), v.rend());
    v.erase(unique(v.begin(), v.end()), v.end());

    int i = 0;
    ll suma = 0;
    ll lasta = 0;
    int j = 0;
    ll sumb = 0;
    ll lastb = 0;
    map<ll, ll> mp;

    for (auto ele : v)
    {
        ll val = ele.first;
        ll arr = ele.second;
        if (!mp[val])
        {   
            
            suma+=val;
            
        }
    }
    if (i < m || j < n)
    {
        cout << suma + sumb << endl;
        return;
    }
    else
    {
        if (lasta > lastb)
        {
            cout << suma + sumb - lastb << endl;
            return;
        }
        else
        {
            cout << suma + sumb - lasta << endl;
            return;
        }
    }
    return;
    // cout << endl;
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