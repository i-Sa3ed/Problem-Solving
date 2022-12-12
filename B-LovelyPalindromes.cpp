// "Problem Link: https://codeforces.com/contest/688/problem/B"

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
    string n; cin >> n;
    cout << n;
    reverse(all(n));
    cout << n;
}

int main()
{
    Saeed_fast;

    int t = 1; //cin >> t;
    while(t--) { solve(); }

    return 0;
}