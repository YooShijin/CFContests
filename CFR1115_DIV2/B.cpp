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
    string s;
    cin >> s;
    ll zero = 0;
    ll one = 0;
    for (auto i : s)
    {
        if (i == '1')
        {
            one++;
        }
        else
        {
            zero++;
        }
    }
    if (abs(zero - one) > 2)
    {
        cout << -1 << endl;
        return;
    }
    ll ans = INT_MAX;
    ll curr = '1';
    ll len = 0;
    ll numo = 0;
    ll numz = 0;
    ll endz = 1;
    ll endo = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == curr)
        {
            if (curr == '1')
            {
                numo++;
            }
            else
            {
                numz++;
            }
        }
        else
        {
            len++;
            curr = s[i];
        }
    }
    if (len > 1)
    {
        if (len & 1)
        {
            endz++;
        }
        else
        {
            endo++;
        }
    }

    if (abs(numo - numz) < 2)
    {
        ans = min(ans, numo + numz);
    }
    else
    {
        if (numo > numz)
        {
            if (numo <= numz + endz + 1)
            {
                ans = min(ans, numo + numo - 1);
            }
        }
        else
        {
            if (numo + endo >= numz - 1)
            {
                ans = min(ans, numz + numz - 1);
            }
        }
    }

    curr = '0';
    len = 0;
    numo = 0;
    numz = 0;
    endz = 0;
    endo = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == curr)
        {
            if (curr == '1')
            {
                numo++;
            }
            else
            {
                numz++;
            }
        }
        else
        {
            len++;
            curr = s[i];
        }
    }
    if (len > 1)
    {
        if (len & 1)
        {
            endo++;
        }
        else
        {
            endz++;
        }
    }

    if (abs(numo - numz) < 2)
    {
        ans = min(ans, numo + numz);
    }
    else
    {
        if (numo > numz)
        {
            if (numo <= numz + endz + 1)
            {
                ans = min(ans, numo + numo - 1);
            }
        }
        else
        {
            if (numo + endo >= numz - 1)
            {
                ans = min(ans, numz + numz - 1);
            }
        }
    }

    if (ans == INT_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans
         << endl;
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