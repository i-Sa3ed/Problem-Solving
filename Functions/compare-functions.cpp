struct test1 {
    int x, y;

    // 1- define an operator:
    bool operator<(test1 t2) const {
        return this->x < t2.x; // sorting based on x
    }
};

// 2- define a comparison function:
bool compare(const test1 &t1, const test1 &t2) {
    // notice: const, passing by reference will be useful if the struct is large.
    return t1.x < t2.x;
} // but here must pass it to the STL.

// 3- by defining a functor, an object acting like a function:
// by definign operator () inside it:
vector<int> sorted;

struct comp {
    int f, n;

    bool operator()(int a, int b) {
        return sorted[a] < sorted[b]; // notice that a, b are indexes.
    }
};

int main() {
    vector <test1> v;
    sort(v.begin(), v.end()); // can be used directly if defined an operator.
    sort(v.begin(), v.end(), compare);

    // we can pass the functor as a template argument:
    vector<int, comp> temp;

    stable_sort(v.begin(), v.end(), compare);
    // to handle the case that a, b are equivalent, will keep the initial order of them.
}