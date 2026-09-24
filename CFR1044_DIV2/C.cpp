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
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(ld x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(bool x) { cerr << (x ? "true" : "false"); }
template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
cerr << "{"; _print(p.ff); cerr << ", "; _print(p.ss); cerr << "}";
}
template <class T> void _print(vector<T> v) {
cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T> void _print(set<T> v) {
cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T> void _print(multiset<T> v) {
cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]";
}
    void solve() {
        ll n;
        cin >> n;
        
        vll dp(n+1);
        ll m = 0, s = 1;
        
        for(ll i = 1; i <= n; i++) {
            cout << "? " << i << " " << n;
            for(ll j = 1; j <= n; j++) cout << " " << j;
            cout << endl;
            cout.flush();
            
            cin >> dp[i];
            if (dp[i] == -1) exit(0);
            
            if (dp[i] > m) {
                m = dp[i];
                s = i;
            }
        }
        
        vll p;
        p.pb(s);
        ll c = s;
        
        while ((ll)p.size() < m) {
            vll a;
            for(ll i = 1; i <= n; i++) {
                bool u = false;
                for (ll x : p) {
                    if (x == i) {
                        u = true;
                        break;
                    }
                }
                if (!u) a.pb(i);
            }
            
            sort(all(a), [&](ll x, ll y) {
                return dp[x] > dp[y];
            });
            
            ll t = -1;
            for (ll x : a) {
                cout << "? " << c << " 2 " << c << " " << x << endl;
                cout.flush();
                
                ll r;
                cin >> r;
                if (r == -1) exit(0);
                
                if (r == 2) {
                    t = x;
                    break;
                }
            }
            
            if (t == -1) break;
            p.pb(t);
            c = t;
        }
        
        cout << "! " << (ll)p.size();
        for (ll x : p) cout << " " << x;
        cout << endl;
        cout.flush();
    }
     
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int t = 1;
        cin >> t;
        while (t--) solve();
        return 0;
    }

