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
void solve()
{
    ll n;
    cin >> n;
    vll v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    deque<int> dq(v.begin(), v.end());
    string ans = "";
    bool small = true;
    while (dq.size())
    {
        if (small)
        {
            if (dq.front() > dq.back())
            {
                dq.pop_back();
                ans += 'R';
            }
            else
            {
                dq.pop_front();
                ans += 'L';
            }
            small = false;
        }
        else
        {
            if (dq.front() > dq.back())
            {
                dq.pop_front();
                ans += 'L';
            }
            else
            {
                dq.pop_back();
                ans += 'R';
            }
            small = true;
        }
    }
    cout << ans << endl;
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