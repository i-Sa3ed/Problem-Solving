#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double EPS = (1e-10);
typedef complex<double> point; // we can use 'complex' to represent 2d point

#define X real()
#define Y imag()

#define angle(a)    (atan2((a).Y, (a).X))
#define vec(a, b)   ((b) - (a))

#define length(a)   (hypot((a).Y, (a).X))
#define normalize(a) ((a)/length(a)) // not understood!

/// Dot / Cross product
// dp = a*b cos(T)
#define dp(a, b)    ( (conj(a) * (b)).X )
// cp = a*b sin(T)
#define cp(a, b)    ( (conj(a) * (b)).Y )

#define same(p1, p2)    (dp(vec(p1, p2), vec(p1, p2)) < EPS)
#define lengthSqr(p)    (dp(p, p))

// rotate 'p' with angle 'ang'
#define rotate0(p, ang)     ( (p)*exp(point(0, ang)))
// to rotate around 'about' point => make about as origin, then shift
#define rotateA(p, ang, about)  ( rotate0(vec(about, p), ang) + (about) )

// reflect 'v' with respect to 'm'
#define reflect0(v, m)  ( conj((v) / (m)) * (m) )

int main() {
    point p(3, 3);
    cout << angle(p) * 180 / PI << '\n'; // 45

    point p1(0, 2);
    point v = vec(p, p1);
    cout << v << '\n';

    cout << length(p) << '\n';

    return 0;
}