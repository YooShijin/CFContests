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
    ll n, k, x;
    cin >> n >> k >> x;
    vll a(n);

    FOR(i, 0, n)
    {
        cin >> a[i];
    }

    sort(all(a));

    vector<pll> g;

    if (a[0] > 0)
    {
        g.pb({a[0], -1});
    }

    FOR(i, 0, n - 1)
    {
        if (a[i + 1] > a[i])
        {
            g.pb({a[i + 1] - a[i], i});
        }
    }

    if (a[n - 1] < x)
    {
        g.push_back({x - a[n - 1], n - 1});
    }

    sort(all(g), greater<pll>());

    vll teleports;

    FOR(i, 0, min((ll)g.size(), k))
    {
        ll gap_size = g[i].ff;
        ll idx = g[i].ss;

        ll left, right;
        if (idx == -1)
        {
            left = 0;
            right = a[0];
        }
        else if (idx == n - 1)
        {
            left = a[n - 1];
            right = x;
        }
        else
        {
            left = a[idx];
            right = a[idx + 1];
        }

        ll teleport_pos = (left + right) / 2;
        teleports.push_back(teleport_pos);
    }

    while (teleports.size() < k)
    {
        ll pos = 0;
        while (find(all(teleports), pos) != teleports.end() ||
               find(all(a), pos) != a.end())
        {
            pos++;
        }
        teleports.push_back(pos);
    }

    FOR(i, 0, k)
    {
        cout << teleports[i];
        if (i < k - 1)
            cout << " ";
    }
    cout << "\n";
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