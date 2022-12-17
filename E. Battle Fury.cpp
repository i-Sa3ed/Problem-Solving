// Problem link: https://codeforces.com/gym/100247/problem/F

#include <bits/stdc++.h>
using namespace std;

// debug:
#ifndef ONLINE_JUDGE
#include "D:/Problem Solving/Some related files/debug/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

using ll = long long;
#define Saeed_fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'  // because '\n' is faster while compiling, and 'endl' is easier for coding ;)
#define rep(n) for(int i = 0; i < n; ++i)
#define all(c) c.begin(), c.end()
#define all1(a, n) (a.begin() + 1), (a.begin() + n + 1)
void y_n(bool ok) { cout << (ok? "YES\n" : "NO\n"); }

/*
 * IDEA:
 * if x number of hits is enough, so > x are also enough = binary search optimization
 * define min and max number of possible hits, then search for the min one
 * for each check:
 *  - we decrease each monster by 'q' points
 *  - if there are some of them still alive, decrease them by (p - q) and count those operations (those are the needed hits)
 *  - compare the available hits with the needed hits
 */

/// Global Variables ///
ll n, p, q, mx = 0;
vector<int> a;

/// Don't forget the REINITIALIZATION man !! ///

bool can(int hits) {
    vector<int> alive;
    for (int i = 1; i <= n; ++i) {
        ll d = a[i] - hits * q; // each monster was hit by 'q' points (initially)
        if (d > 0) // still alive and need to use 'p' option
            alive.push_back(d);
    }

    ll needed = hits + alive.size();
    if (p - q) { // to avoid division by 0
        needed = 0;
        for (double it : alive)
            needed += ceil(it / (p - q)); // hit it by 'p' points
    }

    return (hits >= needed);
}
int min_hits() {
    int l = 1, h = mx / q + 1, m;

    int ans;
    while (l <= h) {
        m = (l + h) / 2;
        if (can(m))
            ans = m, h = m - 1;
        else
            l = m + 1;
    }

    return ans;
}
void solve() {
    cin >> n >> p >> q;
    a.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(mx, (ll)a[i]);
    }

    cout << min_hits();
}

int main()
{
    Saeed_fast;

    int t = 1; //cin >> t;
    while(t--) { solve(); }

    return 0;
}
