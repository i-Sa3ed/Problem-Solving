struct point {
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {
    }

    point operator -(point p) {
        point res;
        res.x = x - p.x;
        res.y = y - p.y;

        return res;
    }
};
double length(point p) {
    return sqrt(p.x * p.x + p.y * p.y);
    // notice that it can be generalized to any #dimensions
}