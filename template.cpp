#include <bits/stdc++.h>
using namespace std;

// debug:
#ifndef ONLINE_JUDGE
#include "D:\Problem Solving\Imp files - PDFs - Books\debug\debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

const double PI = acos(-1.0);
const double EPS = 1e-8; /// WARNING: problem dependent !!!

typedef long long ll;
typedef vector< vector<int> > GRAPH;

#define Saeed_fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'  // because '\n' is faster while compiling, and 'endl' is easier for coding ;)
#define all(c) (c).begin(), (c).end()
#define all1(a, n) ((a).begin() + 1), ((a).begin() + (n) + 1)
#define for1(iter, n) for (int (iter) = 1; (iter) <= (n); ++(iter))

inline void yes_or_no(bool ok) { cout << (ok? "YES\n" : "NO\n"); }
inline ll sum_to_n(ll n) { return n*(n + 1)/2; }
// returns: 0 if almost equal, 1 if `a` greater, -1 if `b` greater
inline int dcmp (double a, double b) { return fabs(a - b) <= EPS? 0 : a > b? 1 : -1; }

/////

void solve(int TC) {

}

int main()
{
    Saeed_fast;

    int TC = 1; cin >> TC;
    for (int test = 1; test <= TC; ++test) {
        solve(test);
    }

    return 0;
}