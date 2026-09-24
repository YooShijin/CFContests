#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define vi vector<ll>
#define vll vector<ll>
#define pii pair<ll, ll>
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

const ll N = 6005;
ll par[N], s[N];
void make(ll n)
{
    for (ll i = 0; i < n + 5; i++)
    {
        par[i] = i;
        s[i] = 1;
    }
}


ll get(ll x)
{
    if (x == par[x])
        return x;
    return par[x] = get(par[x]);
}

bool join(ll x, ll y)
{
    x = get(x);
    y = get(y);
    if (x == y)
        return false;
    if (s[x] < s[y])
        swap(x, y);
    par[y] = x;
    s[x] += s[y];
    return true;
}

bool check(ll u, ll v, vector<vi> &g)
{
    vector<ll> vis(N, 0);
    queue<pii> q;
    q.push({u, -1});
    while (!q.empty())
    {
        auto [cur, p] = q.front();
        q.pop();
        vis[cur] = 1;
        if (cur == v)
            return true;
        for (ll nb : g[cur])
        {
            if (nb == p)
                continue;
            if (!vis[nb])
                q.push({nb, cur});
        }
    }
    return false;
}

void solve()
{
    ll n;
    cin >> n;
    vector<pii> seg(n);
    for (ll i = 0; i < n; i++)
        cin >> seg[i].ff >> seg[i].ss;

    make(2 * n);

    vector<vi> g(2 * n + 5);
    vi res;

    for (ll i = 0; i < n; i++)
    {
        ll u = seg[i].ff, v = seg[i].ss;
        if (check(u, v, g))
            continue;
        if (join(u, v))
        {
            g[u].pb(v);
            g[v].pb(u);
            res.pb(i + 1);
        }
    }

    cout << res.size() << endl;
    for (ll x : res)
        cout << x << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
