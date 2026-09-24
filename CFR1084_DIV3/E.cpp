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
ll primeChecker(ll n)
{
    ll p = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (p == 0)
                p = i;
            else
                return 0;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
    {
        if (p == 0)
            p = n;
        else
            return 0;
    }
    return p;
}

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    bool init = true;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            init = false;
            break;
        }
    }
    if (init)
    {
        cout << "Bob" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            continue;
        }
        ll p = primeChecker(a[i]);
        if (p == 0)
        {
            cout << "Alice" << endl;
            return;
        }
        else
        {
            a[i] = p;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            cout << "Alice" << endl;
            return;
        }
    }
    cout << "Bob";
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