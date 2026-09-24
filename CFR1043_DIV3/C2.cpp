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

ll ipow(ll base, ll exp)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}
vll cost(19);
void pc()
{
    for (int i = 0; i < 19; i++)
    {
        cost[i] = ipow(3, i + 1) + (i > 0 ? i * ipow(3, i - 1) : 0);
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vll tr;
    ll ans = 0;
    ll i = 0;
    ll m = 0;
    while (n)
    {
        ll t = n % 3;
        n = n / 3;
        tr.push_back(t);
        m += t;
        ans = ans + t * cost[i];
        i++;
    }
    if (k < m)
    {
        cout << -1 << endl;
        return;
    }
    else if (k == m)
    {
        cout << ans << endl;
        return;
    }
    ll hue =  ans;

    for (int j = tr.size() - 1; j > 0; j--)
    {
        while (tr[j] > 0)
        {
            tr[j]--;
            tr[j - 1] += 3;
            m += 2;
            if(m>k){
                cout<<ans<<endl;
                return;
            }
            ans = ans - cost[j] + 3 * cost[j - 1];
            if(m == k)
            {
                cout << ans << endl;
                return;
            }
        }
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    pc();
    while (t--)
        solve();
    return 0;
}