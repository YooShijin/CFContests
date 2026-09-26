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
#define RFOR(i, a, b) for (ll i = a; i > b; i -= 1)

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

const int MX = 300001;
ll tot[MX], sum[MX], dp[MX];
bool has[MX];

vll divisor(int x)
{
    vll div;

    for (int d = 1; 1LL * d * d <= x; d++)
    {
        if (x % d == 0)
        {
            div.push_back(d);

            if (d * d != x)
            {
                div.push_back(x / d);
            }
        }
    }

    sort(div.begin(), div.end());

    return div;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    vi a(n);

    vll div = divisor(x);

    for (int d : div)
    {
        tot[d] = 0;
        sum[d] = 0;
        dp[d] = 0;
        has[d] = false;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int h = gcd(a[i], x);
        tot[h] += a[i];
        has[h] = true;
    }

    vi hs;
    for (int d : div)
    {
        if (has[d])
            hs.pb(d);
    }

    for (int d : div)
    {
        for (int h : hs)
        {
            if (h % d == 0)
                sum[d] += tot[h];
        }
    }

    for (int d : div)
    {
        if (d == 1)
        {
            dp[d] = 0;
            continue;
        }

        dp[d] = sum[d];

        for (int h : hs)
        {
            int g = gcd(h, d);

            if (g > 1 && g < d)
            {
                dp[d] = max(dp[d], dp[g]);
            }
        }
    }

    cout << dp[x] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t > 0)
    {
        solve();
        t -= 1;
    }

    return 0;
}