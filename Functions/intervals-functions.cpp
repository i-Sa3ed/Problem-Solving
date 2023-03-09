vector< pair<int, int> > merge_intervals(vector< pair<int, int> >& ranges) {
    assert(!ranges.empty());

    sort(all(ranges));

    vector< pair<int, int> > res;
    res.push_back(ranges.front());

    for (int i = 1; i < ranges.size(); ++i) {
        if (ranges[i].first <= res.back().second) // overlapping intervals
            res.back().second = max(res.back().second, ranges[i].second);
        else
            res.push_back(ranges[i]);
    }

    return res;
}
