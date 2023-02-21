struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {
    }

    void read() { cin >> x >> y; }

    Point operator -(Point p) {
        Point res;
        res.x = x - p.x;
        res.y = y - p.y;

        return res;
    }
};
double length(Point p) {
    return sqrt(p.x * p.x + p.y * p.y);
    // notice that it can be generalized to any #dimensions
}