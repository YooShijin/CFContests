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

int dfsLongest(vector<vector<int>> &adj, int u, int parent)
{
    int maxDepth = 0;
    for (int v : adj[u])
    {
        if (v != parent)
        {
            maxDepth = max(maxDepth, 1 + dfsLongest(adj, v, u));
        }
    }
    return maxDepth;
}

vector<pair<int, int>> getNeighborPaths(vector<vector<int>> &adj, int node)
{
    vector<pair<int, int>> result;
    for (int neighbor : adj[node])
    {
        int longestPath = 1 + dfsLongest(adj, neighbor, node);
        result.push_back({neighbor, longestPath});
    }
    sort(result.begin(), result.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second > b.second; });

    return result;
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].size() > 2)
        {
            flag = false;
        }
    }
    if (flag)
    {
        cout << -1 << endl;
        return;
    }

    int md = 0;
    vector<int> nodes;

    for (int i = 1; i <= n; i++)
    {
        int d = a[i].size();
        if (d > md)
        {
            md = d;
            nodes.clear();
            nodes.push_back(i);
        }
        else if (d == md)
        {
            nodes.push_back(i);
        }
    }

    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < nodes.size(); i++)
    {
        vector<pair<int, int>> v = getNeighborPaths(a, nodes[i]);
        m[nodes[i]] = v;
    }
    int a1, b, c;
    int t = 0;
    for (auto &e : m)
    {
        int key = e.first;
        vector<pair<int, int>> &v = e.second;

        if (v.size() >= 3 && v[0].second > t)
        {
            b = key;
            a1 = v[1].first;
            c = v[2].first;
            t = v[0].second;
        }
    }

    cout << a1 << " " << b << " " << c << " " << endl;
    return;
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