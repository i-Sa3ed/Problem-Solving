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

struct Rectangle_ul_lr {
    Point ul, lr; // upper left, lower right
    double w, h; // width, length
    Rectangle_ul_lr() { w = h = 0; }

    void read()
    { cin >> ul.x >> ul.y >> lr.x >> lr.y; }
    void compute() {
        w = lr.x - ul.x;
        h = ul.y - lr.y;
    }
    double area() {
        compute();
        return (w * h);
    }

    bool is_inside(Point p, bool consider_border = false) {
        bool res;
        if (!consider_border) {
            res = (p.x > ul.x and p.x < lr.x)
                  and (p.y > lr.y and p.y < ul.y);
        }
        else {
            res = (p.x >= ul.x and p.x <= lr.x)
                  and (p.y >= lr.y and p.y <= ul.y);
        }

        return res;
    }
};

struct Rectangle_bl_tr {
    Point bl, tr;
    ll w, h; // width, length
    Rectangle_bl_tr() { w = h = 0; }

    void read()
    { cin >> bl.x >> bl.y >> tr.x >> tr.y; }
    void compute() {
        w = tr.x - bl.x;
        h = tr.y - bl.y;
    };
    ll area() {
        compute();
        return (w * h);
    };
};

ll inter_area(Rectangle_bl_tr r1, Rectangle_bl_tr r2)
{
    ll iw, il; // intersection width and length
    iw = max(0, min(r1.tr.x, r2.tr.x) - max(r1.bl.x, r2.bl.x));
    il = max(0, min(r1.tr.y, r2.tr.y) - max(r1.bl.y, r2.bl.y));

    return (iw * il);
}

ll inter_area(vector<Rectangle_bl_tr>& rectangles)
{
    Point max_bl, min_tr;
    min_tr.x = min_tr.y = INT_MAX;
    for(Rectangle_bl_tr& rect : rectangles) {
        max_bl.x = max(max_bl.x, rect.bl.x);
        max_bl.y = max(max_bl.y, rect.bl.y);
        min_tr.x = min(min_tr.x, rect.tr.x);
        min_tr.y = min(min_tr.y, rect.tr.y);
    }

    ll iw, il; // intersection width and length
    iw = max(0LL, min_tr.x - max_bl.x);
    il = max(0LL, min_tr.y - max_bl.y);

    return (iw * il);
}
