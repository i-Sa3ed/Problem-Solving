////////////////// degree = radian ///////////////
/// radian <=> degree functions
const double PI = acos(-1.0);

double to_degree_from_minutes(double minutes) {
    return (minutes/60);
}
double to_radian(double degree) {
    return (degree * PI / 180);
}
double to_degree(double radian) {
    if (radian < 0) radian += 2*PI; // add a cycle
    return (radian * 180 / PI);
}

//////////////////// rectangle class //////////////////////
struct Rectangle {
    double left, right, lower, upper;
    double w, h; // width, length
    Rectangle() { left = right = lower = upper = w = h = 0; }

    void set(double l, double r, double low, double up) {
        left = l, right = r, low = lower, upper = up;
    }

    void compute() {
        w = right - left;
        h = upper - lower;
    }
    double area() {
        compute();
        if (w < 0 or h < 0)
            return -1; // invalid rectangle
        return (w * h);
    }

    bool is_inside(Point p, bool consider_border = false) {
        bool res;
        if (!consider_border) {
            res = (p.x > left and p.x < right)
                  and (p.y > lower and p.y < upper);
        }
        else {
            res = (p.x >= left and p.x <= right)
                  and (p.y >= lower and p.y <= upper);
        }

        return res;
    }
};

////////////////////// triangle functions ///////////////////
// notice that we represent the angles with capital letters, while the sides with small ones
double fix_angle(double A) {
    return (A > 1? 1 : (A < -1? -1 : A));
}

// sin rule => sin(A) / a = sin(B) / b
double get_side_a(double b, double A, double B) {
    return (sin(A) * b / sin(B));
}
double get_angle_A_given_abB(double a, double b, double B) {
    return asin(fix_angle( a*sin(B)/b ));
}

// cos rule => a^2 = b^2 + c^2 - 2bc*cos(A)
double get_angle_A_given_sides(double a, double b, double c) {
    return acos(fix_angle(  (b*b + c*c - a*a)/(2*b*c)  ));
}

/// triangle area:
double triangle_area(point p0, point p1, point p2) {
    double a = length(p0 - p1), b = length(p0 - p2), c = length(p1 - p2);
    double s = (a + b + c) / 2;
    return sqrt((s-a) * (s-b) * (s-c) * s);
}

// given 3 medians, find area
double triangle_area(double m1, double m2, double m3) {
    // area of triangle using medians as sides =
    // 3/4 * (original area)

    if (m1 <= 0 or m2 <= 0 or m3 <= 0) return -1; // impossible

    // make area by sides = medians:
    double s = (m1+m2+m3) / 2;
    double mediansArea = (s * (s-m1) * (s-m2) * (s-m3));
    double area = 4.0 / 3.0 * sqrt(mediansArea); // original area

    if (mediansArea <= 0 or area <= 0) return -1; // impossible
    return area;
}

//////////////// point-line distance ///////////////////
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
