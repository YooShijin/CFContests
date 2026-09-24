#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define push_back push_back
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

vi primes;
bool done = false;

void sieve()
{
    if (done)
        return;
    int lim = 200050;
    vector<bool> ok(lim + 1, true);
    ok[0] = ok[1] = false;
    for (int i = 2; i * i <= lim; i++)
    {
        if (ok[i])
        {
            for (int j = i * i; j <= lim; j += i)
                ok[j] = false;
        }
    }
    for (int i = 2; i <= lim; i++)
    {
        if (ok[i])
            primes.push_back(i);
    }
    done = true;
}

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    vll b(n);
    FOR(i, 0, n)
    {
        cin >> a[i];
    }
    FOR(i, 0, n)
    {
        cin >> b[i];
    }

    if (!done)
        sieve();

    ll ans = 1e9;

    for (auto p : primes)
    {
        vll c;
        FOR(i, 0, n)
        {
            ll r = a[i] % p;
            ll temp;
            if (r == 0)
            {
                temp = 0;
            }
            else
            {
                temp = p - r;
            }
            c.push_back(temp);
        }
        sort(all(c));
        ll sum = c[0] + c[1];
        ans = min(ans, sum);
        if (ans == 0)
            break;
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