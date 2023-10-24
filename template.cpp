#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// debug:
#ifndef ONLINE_JUDGE
#include "D:\Problem Solving\files and books\debug\debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

const double PI = acos(-1.0);
const double EPS = 1e-8; /// WARNING: problem dependent !!!
const int OO = 1e6;

typedef long long ll;
typedef vector< vector<int> > GRAPH;
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set; // find_by_order, order_of_key

#define Saeed_fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'  // because '\n' is faster while compiling, and 'endl' is easier for coding ;)
#define all(c) (c).begin(), (c).end()
#define all1(a, n) ((a).begin() + 1), ((a).begin() + (n) + 1)
#define rep(i, n) for(int (i) = 0; (i) < n; ++(i))
#define rep1(i, n) for (int (i) = 1; (i) <= n; ++(i))

inline void yn(bool ok) { cout << (ok? "YES\n" : "NO\n"); }
inline ll sum_to_n(ll n) { return n*(n + 1)/2; }
// double compare
// returns: 0 if almost equal, 1 if `a` greater, -1 if `b` greater
inline int dcmp (double a, double b) { return fabs(a - b) <= EPS? 0 : a > b? 1 : -1; }

/////

void solve(int TC) {

}

int main()
{
    Saeed_fast;

    int TC = 1;
    cin >> TC;
    for (int test = 1; test <= TC; ++test) {
        solve(test);
    }

    return 0;
}