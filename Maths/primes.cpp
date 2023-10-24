
/// Facts
// (2^31)-1 is a prime number with value 2147483647 => max prime that fit in 32-bit
// (2^61)-1 is a prime number with value 2305843009213693951 => max prime that fit in 64-bit
// primesRangeCnt 10^i (4, 25, 168, 1229, 9592, 78498, 664579, 5761455) [e.g. 4 primes <= 10^1] ~= n / log(n)

bool isPrime(ll x) {
    // O(sqrt(n)) .. BUT, almost the func. terminates early
    if(x == 2)
        return true;
    if(x < 2 or x % 2 == 0)
        return false;

    for (ll i = 3; i*i <= x; i += 2) {
        if(x % i == 0)
            return false;
    }
    return true;
}

// count #primes in range using Sieve algo
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (!is_prime[i])
            continue;

        // mark all multiples of i as non-primes
        for (int j = 2 * i; j <= n; j += i)
            is_prime[j] = false;
    }

    return is_prime;
}

