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
vll spf(3e5+1);
void init(){
    for(int i = 1; i< spf.size(); i++){
        spf[i] = i;
    }

    for(int i  =2; i*i < spf.size(); i++){
        for(int j = i; j< spf.size(); j+= i){
            spf[j] = min(spf[j], i*1LL);
        }
    }
}
void solve()
{
    ll n, x;
    cin >> n >> x;

    vll a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    ll ans = 0;
    ll num = x;
    ll i = spf[num];
        while (i>1)
        {
            ll temp = 0;
            while (num % i == 0)
            {
                num = num / i;
            }
            for (auto ele : a)
            {
                if ((ele % i) == 0)
                {
                    temp += ele;
                }
                ans = max(ans, temp);
            }
            i = spf[num];
        }


    cout << ans << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int t = 1;
    cin >> t;

    while (t > 0)
    {
        solve();
        t -= 1;
    }

    return 0;
}