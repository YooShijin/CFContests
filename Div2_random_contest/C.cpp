#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define FOR(i, a, b) for (ll i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;
    vector<pii> arr(n);
    FOR(i, 0, n) {
        cin >> arr[i].ff;
        arr[i].ss = i + 1;
    }

    sort(all(arr), [&](pii a, pii b) {
        if (a.ff != b.ff) return a.ff > b.ff;
        return a.ss < b.ss;
    });

    vector<bool> pressed(n + 2, false);
    pressed[0] = pressed[n + 1] = true;

    int ans = 0, i = 0;
    while (i < n) {
        int w = arr[i].ff;
        vector<int> indices;
        while (i < n && arr[i].ff == w) {
            indices.pb(arr[i].ss);
            i++;
        }

        sort(all(indices));
        int l = 0;
        while (l < indices.size()) {
            int r = l;
            while (r + 1 < indices.size() && indices[r + 1] == indices[r] + 1) r++;
            int L = indices[l], R = indices[r];
            if (!pressed[L - 1] && !pressed[R + 1]) ans++;
            FOR(k, l, r + 1) pressed[indices[k]] = true;
            l = r + 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
