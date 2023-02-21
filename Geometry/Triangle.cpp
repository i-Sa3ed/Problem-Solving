/// solve triangles
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