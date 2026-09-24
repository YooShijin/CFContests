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
    vector<vector<ll>> v(n - 1, vector<ll>(4));
    for (ll i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < 4; j++)
            cin >> v[i][j];
    }

    sort(v.begin(), v.end(), [](const vector<ll> &x, const vector<ll> &y)
         { return max(x[2], x[3]) > max(y[2], y[3]); });

    vll ans(n, 0);
    ll mi = 1;
    ll ma = n;
    for (long long i = 0; i < n - 1; i++)
    {
        ll u, vv, x, y;
        if (v[i][2] > v[i][3])
        {
            x = v[i][2];
            y = v[i][3];
            u = v[i][0];
            vv = v[i][1];
        }
        else
        {
            x = v[i][3];
            y = v[i][2];
            u = v[i][1];
            vv = v[i][0];
        }

        if (ans[u - 1] > ans[vv - 1] && ans[u - 1] && ans[vv - 1])
            continue;

        if (ans[vv - 1] > ma)
        {
            ans[u - 1] = ans[vv - 1];
            ans[vv - 1] = ma;
            ma--;
        }
        else
        {
            ans[u - 1] = ma;
            ma--;
        }
        if (ans[vv - 1] < mi && ans[vv - 1])
        {
            continue;
        }
        else
        {
            ans[vv - 1] = mi;
            mi++;
        }
        if(mi> ma ) break;
    }
    for (ll i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
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