// problem link: https://codeforces.com/contest/1735/problem/A

#include <bits/stdc++.h>
using namespace std;

// debug stuff:
#ifndef ONLINE_JUDGE
#include "D:/Problem Solving/Some related files/debug/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

///new data types:
using ll = long long;

///macros:
#define Saeed_fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'  // because '\n' is faster while compiling, and 'endl' is easier for coding ;)
#define all(c) c.begin(), c.end()


/// Don't forget the REINITIALIZATION man !! ///
void solve() {
    int n; cin >> n;
    int work = n - 3;
    cout << (work / 3) - 1 << endl;
}

int main()
{
    Saeed_fast;

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}