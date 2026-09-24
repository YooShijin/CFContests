#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (ll i = a; i < b; i++)

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n + 2);
    FOR(i, 0, n)
        cin >> a[i + 1];

    a[0] = a[1];
    a[n + 1] = a[n];

    ll ans = 0;
    FOR(i, 1, n + 1)
    ans += abs(a[i] - a[i - 1]);

    ll diff = 0;

    FOR(i, 2, n)
    {
        ll cur = abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);
        ll after = abs(a[i - 1] - a[i + 1]);
        diff = max(diff, cur - after);
    }

    diff = max(diff, abs(a[2] - a[1]));
    diff = max(diff, abs(a[n] - a[n - 1]));

    cout << ans - diff << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
