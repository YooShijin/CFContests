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
    string s, t;
    cin >> s >> t;
    string l = s;
    string m = t;
    sort(l.begin(), l.end());
    sort(m.begin(), m.end());
    if (l != m)
    {
        cout << -1 << endl;
        return;
    }
    string a = "";
    string b = "";
    string t1 = "";
    t1.push_back(s[0]);
    a.push_back(s[0]);
    string t2 = "";
    t2.push_back(t[0]);
    b.push_back(t[0]);
    for (int i = 1; i < s.size(); i++)
    {
        int m = t1.size();
        if (t1[m - 1] == s[i])
        {
            t1.pop_back();
        }
        else
        {
            a.push_back(s[i]);
            t1.push_back(s[i]);
        }
    }
    for (int i = 1; i < t.size(); i++)
    {
        int m = t2.size();
        if (t2[m - 1] == t[i])
        {

            t2.pop_back();
        }
        else
        {
            b.push_back(t[i]);
            t2.push_back(t[i]);
        }
    }
    ll ans = 0;
    if (t1 == t2)
    {
        cout << a << "-a" << endl;
        cout << b << "-b" << endl;
        for (int i = 0; i < a.size(); i++)
        {

            if (a[i] != b[i])
            {
                ans++;
            }
        }
        cout << ans << endl;
        return;
    }

    cout << -1 << endl;
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