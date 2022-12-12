// Problem link: https://codeforces.com/contest/810/problem/B

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
void y_n(bool ok) { cout << (ok? "yes\n" : "no\n"); }

/// Global Variables ///

/// Don't forget the REINITIALIZATION man !! ///

void solve() {
    int n, f;
    cin >> n >> f;

    priority_queue<int> toAdd;

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int k, l;
        cin >> k >> l;
        int beforeF = min(k, l);
        ans += beforeF;

        if(k != 0 and l > k) {
            int afterF = min(2*k, l);
            toAdd.push(afterF - beforeF);
        }
    } // O(n)

    // adding:
    while (f-- and !toAdd.empty()) {
        ans += toAdd.top();
        toAdd.pop();
    } // O(f)

    cout << ans;
}

int main()
{
    Saeed_fast;

    int t = 1; //cin >> t;
    while(t--) { solve(); }

    return 0;
}