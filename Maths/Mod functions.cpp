// calc x^n mod m
// Notice: m must be > 0
__int128 mod_power(__int128 x, ll n, ll m) { // O(log n)
    // use int128 to avoid overflow

    __int128 res = 1;
    while (n) {
        if (n & 1LL) // x^n = x^(n-1) * x
            res = (res%m * x%m) % m, --n;
        else // x^n = x^n/2 * x^n/2 = x^2^(n/2)
            x = (x%m * x%m) % m, n /= 2;
    }

    return res;
}
