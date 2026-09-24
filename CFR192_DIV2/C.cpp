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
    ll n, k;
    cin >> n >> k;
    vll a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vll num(n + 1, 0);
    int add = 1;
    num[a[0]]++;
    for (int i = 1; i < n; i++)
    {
        num[a[i]]++;
        if (a[i] > a[i - 1])
        {
            add++;
        }
    }
    sort(num.rbegin(), num.rend());
    for (int i = 0; i < num.size() - 1; i++)
    {
        num[i] = max(0LL, num[i] - num[i + 1]);
    }
    int j = num.size() - 1;
    int aage = 0;
    int peeche = 0;
    int single = 0;
    if (k >= n)
    {
        if ((k - n) % add == 0)
        {
            aage = 1;
        }
    }
    else
    {
        int i = num.size() - 1;
        while (!num[i])
        {
            i--;
        }

        while (add > 0 && n > 0)
        {
            if (num[i] && add == 1)
            {
                single = 1;
            }
            int l = num[i];
            if (!l)
            {
                add--;
                l--;
                continue;
            }
            for (int j = 1; j <= l; j++)
            {
                n = n - add;
                if ((k - n) % add == 0)
                {
                    aage = 1;
                }
                if (n == k)
                {
                    peeche = 1;
                }
            }
            add--;
            i--;
        }
    }
    if (k == 1)
    {
        if (single)
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << max(aage, peeche) + single << endl;
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