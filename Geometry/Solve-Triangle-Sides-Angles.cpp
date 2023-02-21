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