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

vi g[200005];

void solve() {
    int n;
    cin >> n;
    
    FOR(i, 1, n + 1) {
        g[i].clear();
    }
    
    FOR(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    if (n <= 2) {
        cout << 0 << endl;
        return;
    }
    
    int leafCnt = 0;
    FOR(i, 1, n + 1) {
        if (g[i].size() == 1) {
            leafCnt++;
        }
    }
    
    int bestCenter = 0;
    FOR(node, 1, n + 1) {
        int adjLeaves = 0;
        
        for (int nei : g[node]) {
            if (g[nei].size() == 1) {
                adjLeaves++;
            }
        }
        
        bestCenter = max(bestCenter, adjLeaves);
    }
    
    int ans = leafCnt - bestCenter;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}