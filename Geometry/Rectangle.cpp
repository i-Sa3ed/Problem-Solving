struct Rectangle {
    Point bl, tr;
    ll w, h; // width, length
    Rectangle() { w = h = 0; }

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

ll inter_area(Rectangle r1, Rectangle r2)
{
    ll iw, il; // intersection width and length
    iw = max(0, min(r1.tr.x, r2.tr.x) - max(r1.bl.x, r2.bl.x));
    il = max(0, min(r1.tr.y, r2.tr.y) - max(r1.bl.y, r2.bl.y));

    return (iw * il);
}

ll inter_area(vector<Rectangle>& rectangles)
{
    Point max_bl, min_tr;
    min_tr.x = min_tr.y = INT_MAX;
    for(Rectangle& rect : rectangles) {
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
