#include <bits/stdc++.h>

using namespace std;

#define fast        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ll          long long
#define el          "\n"
#define fi          first
#define se          second
#define all(v)      v.begin(), v.end()

const ll N = 1e6 + 6, mod = 1e9 + 7, OO = 1e18;
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
char di[] = {'D', 'L', 'U', 'R'};

void file() {
#ifndef ONLINE_JUDGE
    freopen("moon-in.txt", "r", stdin);
    freopen("moon-out.txt", "w", stdout);
#endif
}

ll n, k;
vector<ll> v;

bool can(ll x) {
    ll sum = k;
    for (int i = n / 2; i < n; ++i) {
        if (v[i] >= v[n / 2] + x)continue;
        sum -= (v[n / 2] + x - v[i]);
        if (sum < 0)return 0;
    }
    if (sum < 0)return 0;
    return 1;
}

int main() {
    file();
    fast
    cin >> n >> k;
    v.resize(n);
    for (auto &i: v)
        cin >> i;
    sort(all(v));
    ll m = v[n / 2];
    ll st = 0, en = k, ans = 0;
    while (st <= en) {
        ll mid = st + en >> 1;
        if (can(mid))
            st = mid + 1 , ans = mid ;
        else
            en = mid - 1 ;
    }
    cout<<ans + m<<el;
    return 0;
}

