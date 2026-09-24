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

vector<vector<int>> adj;
vector<int> parent, subtree;

void dfs(int u, int p)
{
    parent[u] = p;
    subtree[u] = 1;

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == p)
            continue;

        dfs(v, u);
        subtree[u] += subtree[v];
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    adj.clear();
    adj.resize(n + 1);

    parent.clear();
    parent.resize(n + 1);

    subtree.clear();
    subtree.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    ll ans = 0;

    for (int u = 1; u <= n; u++)
    {
        int r = sqrt(a[u]);
        if (1LL * r * r != a[u])
            continue;

        if (adj[u].size() <= 1)
            continue;

        vector<ll> comp;

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];

            if (v == parent[u])
                comp.push_back(n - subtree[u]);
            else
                comp.push_back(subtree[v]);
        }

        if (comp.size() == 2)
        {
            ans += comp[0] * comp[1];
        }
        else
        {
            ll temp = 0;

            for (int i = 0; i < comp.size(); i++)
            {
                ll x = comp[i];

                if (x == 1)
                    continue;

                temp += x * (n - x - 1);
            }

            ans += temp;
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