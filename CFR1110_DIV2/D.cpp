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
    ll m, n;
    cin >> n >> m;
    map<ll, int> ma;
    vector<pair<ll, pair<ll, ll>>> quer;

    for (int i = 0; i < m; i++)
    {
        ll a, x, y;
        cin >> a >> x >> y;
        quer.push_back({a, {x, y}});
    }

    for (int i = 0; i < m; i++)
    {
        ll a = quer[i].first;
        ll x = quer[i].second.first;
        ll y = quer[i].second.second;

        if (a == 1)
        {
            if (x != y)
            {
                ma[x]++;
                ma[y]++;
            }
            else
            {
                ma[x]++;
            }
        }
        else
        {
            if (x != y)
            {
                ma[x]--;
                ma[y]--;
            }
            else
            {
                ma[x]--;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        ll a = quer[i].first;
        ll x = quer[i].second.first;
        ll y = quer[i].second.second;

        if (a == 1)
        {
            if (x != y)
            {
                if (ma[x] + ma[y] < 0)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            else
            {
                if (ma[x] < 0)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        else
        {
            if (x != y)
            {
                if (ma[x] + ma[y] >= 0)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            else
            {
                if (ma[x] >= 0)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    for (ll i = 0; i < n; i++)
    {
        cout << ma[i + 1] << " ";
    }
    cout << endl;
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