/// Matrix operations code ///
// for easy code
typedef vector<double> row; /// type is problem dependant
typedef vector<row> matrix;

matrix zeroMatrix(int n, int m) {
    // matrix with all values = 0
    return matrix(n, row(m, 0));
}

matrix identity(int n) {
    matrix ret = zeroMatrix(n, n);
    rep(i, ret)
    ret[i][i] = 1;
    return ret;
}

double matrixTrace(matrix& mat) {
    // trace = sum of diagonal values
    double trace = 0;
    rep(i, mat)
    trace += mat[i][i];
    return trace;
}

matrix rotate(matrix& v) {
    // clockwise rotation
    matrix r = zeroMatrix(v[0].size(), v.size());

    rep(i, v)
    rep(j, v[0])
    r[j][v.size() - 1 - i] = v[i][j];
    return r;
}

matrix add(matrix& a, matrix& b) {
    // must be of same dimensions
    matrix ret = zeroMatrix(a.size(), a[0].size());
    rep(i, a)
    rep(j, a[0])
    ret[i][j] = a[i][j] + b[i][j];
    return ret;
}

matrix addIdentity(const matrix& a) {
    matrix ret = a;
    rep(i, a)
    ret[i][i] = a[i][i] + 1;
    return ret;
}

matrix multiply(const matrix& a, const matrix& b) { // O(n^3)
    // cols of 'a' must be equal to rows of 'b'
    matrix mult = zeroMatrix(a.size(), b[0].size()); // mult dimensions = A*C

    rep(i, a) rep(k, a[0]) {
        if (a[i][k] == 0)
            continue;
        // Optimization: we could switch tha last 2 loops if b[k][j] has more zeros
        rep(j, b[0])
        mult[i][j] += a[i][k] * b[k][j]; // ith row * jth col
    }

    return mult;
}

// matrix power
matrix pow(const matrix& a, ll k) { // O(n^3 logn)
    // similar to normal numbers
    if (k == 0)
        return identity(a.size());

    if (k & 1)
        return multiply( a, pow(a, k-1) );

    return pow( multiply(a, a), k / 2 );
}

// matrix power sum
// a^1 + a^2 + a^3 + a^4 + a^5
// Didn't understand well! :(
matrix sumPows(matrix a, ll k) {
    if (k == 0)
        return zeroMatrix(a.size(), a.size());
    if (k & 1)
        return multiply(a, addIdentity( sumPows(a, k-1) ));
    return multiply( sumPows(a, k/2), addIdentity( pow(a, k/2) ) );
}
