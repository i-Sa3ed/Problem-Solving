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

/// Line utilities ///
inline int dcmp (double a, double b) { return fabs(a - b) <= EPS? 0 : a > b? 1 : -1; }

bool is_collinear(point a, point b, point c) {
    // check if `c` on the LINE a<->b
    return fabs( cp(b-a, c-a) ) < EPS;

    // why used `cp`?
    // because it uses `sin` => same value for T = 0, T = 180 (sin(0) = sin(180) = 0)
}
bool is_above_line(point a, point b, point c) {
    // check if `c` is above line (a <=> b)
    return fabs( cp(b-a, c-a) ) > EPS; // positive angle
}

bool is_point_on_ray(point a, point b, point c) {
    // check if `c` is on ray (a => b)
    if (!is_collinear(a, b, c))
        return false;
    return dcmp( dp(b-a, c-a), 0 ) == 1; // (cos(0) = 1, which is > 0)

    // why used `dp`?
    // because it uses `cos` => differ between 0 and 180
    // so we check if T == 0 and != 180
}
// Notice: we can also use 'normalization' to check it

bool is_point_on_segment(point a, point b, point c) {
    // check if `c` on the segment (a-b)
    // simply, it must be on the ray from both directions ;)
    return is_point_on_ray(a, b, c) and is_point_on_ray(b, a, c);
}

double dist_to_line(point a, point b, point c) {
    // compute the min (vertical) dist from `c` to the line (a <=> b)
    double area_2 = cp(b-a, c-a); // 2 * area between the two vectors
    double base = length(a-b);
    double dist = area_2 / base; // from triangle formula (dist = height)

    return fabs(dist);
}
double dist_to_segment(point a, point b, point c) {
    // this time compute to the segment, not to the line
    // so, we have 3 cases:
        // c on the left
        // c on the right
        // c between a and b

    double d1, d2;
    point v1 = b - a, v2 = c - a;

    if ( (d1 = dp(v1, v2)) <= 0) // left
        return length(c - a);
    if ( (d2 = dp(v1, v1)) <= d1 ) // right (Black Box!)
        return length(c - b);

    // case 3: on the segment
    double t = d1 / d2; // the portion from the segment.
    return length(c - (a + v1*t));
}



int main() {
    point p(3, 3);
    cout << angle(p) * 180 / PI << '\n'; // 45

    point p1(0, 2);
    point v = vec(p, p1);
    cout << v << '\n';

    cout << length(p) << '\n';

    return 0;
}