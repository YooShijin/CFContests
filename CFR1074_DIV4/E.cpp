#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<long long> a(n), b(m);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        string s;
        cin >> s;

        sort(b.begin(), b.end());

        vector<long long> d(k + 1, 0), mn(k + 1, 0), mx(k + 1, 0);
        for (int i = 1; i <= k; i++) {
            d[i] = d[i - 1] + (s[i - 1] == 'R' ? 1 : -1);
            mn[i] = min(mn[i - 1], d[i]);
            mx[i] = max(mx[i - 1], d[i]);
        }

        vector<int> dieAt(k + 2, 0);

        auto canDieBy = [&](long long pos, long long leftSpike, long long rightSpike, int mid) {
            bool ok = false;
            if (leftSpike != (long long)4e18) {
                if (pos + mn[mid] <= leftSpike) ok = true;
            }
            if (rightSpike != (long long)4e18) {
                if (pos + mx[mid] >= rightSpike) ok = true;
            }
            return ok;
        };

        for (int i = 0; i < n; i++) {
            long long pos = a[i];

            auto it = lower_bound(b.begin(), b.end(), pos);

            long long leftSpike = (long long)4e18;
            long long rightSpike = (long long)4e18;

            if (it != b.begin()) leftSpike = *(it - 1);
            if (it != b.end()) rightSpike = *it;

            if (leftSpike == (long long)4e18 && rightSpike == (long long)4e18) continue;

            int lo = 1, hi = k, ans = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (canDieBy(pos, leftSpike, rightSpike, mid)) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            if (ans != -1) dieAt[ans]++;
        }

        int alive = n;
        for (int i = 1; i <= k; i++) {
            alive -= dieAt[i];
            cout << alive << (i == k ? '\n' : ' ');
        }
    }
    return 0;
}
