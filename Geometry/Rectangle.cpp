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

Rectangle get_overlapping_rectangle(Rectangle rec1, Rectangle rec2) {
    Rectangle overlap;

    overlap.left = max(rec1.left, rec2.left);
    overlap.lower = max(rec1.lower, rec2.lower);

    overlap.right = min(rec1.right, rec2.right);
    overlap.upper = min(rec1.upper, rec2.upper);

    return overlap; // if (overlap.area <= 0) => no overlap
}

Rectangle get_overlapping_rectangle(vector<Rectangle>& rectangles)
{
    Rectangle overlap;
    overlap.right = overlap.upper = INT_MAX;
    for(Rectangle& rect : rectangles) {
        overlap.left = max(overlap.left, rect.left);
        overlap.lower = max(overlap.lower, rect.lower);
        overlap.right = min(overlap.right, rect.right);
        overlap.upper = min(overlap.upper, rect.upper);
    }

    return overlap; // if (overlap.area <= 0) => no overlap
}
