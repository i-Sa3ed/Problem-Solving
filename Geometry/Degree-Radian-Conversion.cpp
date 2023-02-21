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