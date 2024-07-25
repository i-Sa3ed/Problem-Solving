////////////////// Find the roots of equations ///////////////////
/////// Quadratic ///////
// using the general rule:
// Prints roots of quadratic equation
// ax*2 + bx + x
void findRoots(int a, int b, int c)
{
    // If a is 0, then equation is
    // not quadratic, but linear
    if (a == 0) {
        cout << "Invalid";
        return;
    }

    int d = b * b - 4 * a * c;
    double sqrt_val = sqrt(abs(d));

    if (d > 0) {
        cout << "Roots are real and different ";
        cout << (double)(-b + sqrt_val) / (2 * a) << " "
             << (double)(-b - sqrt_val) / (2 * a);
    }
    else if (d == 0) {
        cout << "Roots are real and same ";
        cout << -(double)b / (2 * a);
    }

    // d < 0
    else {
        cout << "Roots are complex ";
        cout << -(double)b / (2 * a) << " + i"
             << sqrt_val / (2 * a) << " "
             << -(double)b / (2 * a) << " - i"
             << sqrt_val / (2 * a);
    }
}

/////////// Cubic ///////////
// using the divisors of d
bool check(ll x){
	return a * x * x * x + b * x * x + c * x + d == 0;
}
 
int main()
{
    GO
    int t;
	cin >> t;
	while(t--){
		cin >> a >> b >> c >> d;
		ll ans = -1e9;
		if(check(0)) ans = 0;
		for(ll i = 1; i * i <= abs(d); i++){
			if(d % i == 0){
				if(check(i)) ans = i;
				if(check(-i)) ans = -i;
				if(check(d / i)) ans = d / i;
				if(check(-d / i)) ans = -d / i;
			}
		}
		if(ans != -1e9){
			cout << "Yes\n";
			cout << ans << '\n';
		}
		else cout << "No\n";
	}
    return 0;
}

// using Binary search:
// Function to find the integral
// solution of the given equation
void findSolution(int A, int B, int C,
                  int D, int E)
{

    // Initialise start and end
    int start = 0, end = 100000;

    long long int mid, ans;

    // Implement Binary Search
    while (start <= end) {

        // Find mid
        mid = start + (end - start) / 2;

        // Find the value of f(x) using
        // current mid
        ans = check(A, B, C, D, mid);

        // Check if current mid satisfy
        // the equation
        if (ans == E) {

            // Print mid and return
            cout << mid << endl;
            return;
        }

        if (ans < E)
            start = mid + 1;
        else
            end = mid - 1;
    }

    // Print "NA" if not found
    // any integral solution
    cout << "NA";
}

////////////////// Factorization ///////////////////
class Factorization {
public:
    vector<int> prime_factors(int n) {
        vector<int> factors;
        while (n % 2 == 0) { // add all 2s
            factors.push_back(2);
            n /= 2;
        }
        for (int i = 3; 1LL * i * i <= n; i += 2) { // check for odd factors
            while (n % i == 0) {
                factors.push_back(i);
                n /= i;
            }
        }
        if (n > 2) factors.push_back(n); // handle prime numbers
        return factors;
    }
    vector<int> unique_factors(int n) {
        // returns the unique factors for `n`
        // O(sqrt(n))

        vector<int> factors;
        for (int i = 1; 1LL * i * i <= n; ++i)
            if (n % i == 0) {
                factors.push_back(i);
                if (n/i != i)
                    factors.push_back(n/i);
            }
        return factors;
    }
};

///////////////////////////////////////////////////////////


unsigned long long gcd(long long x, long long y)
{
    if (x < y)
        swap (x, y);

    while(x != 0 && y != 0)
    {
        long long r = x % y;
        x = y;
        y = r;
    }

    return x;
}

unsigned long long lcm (long long x, long long y)
{
    return x / gcd(x, y) * y;
}

///////////////////////////////////////////////////////////

ll nCr(int n, int r) {
    if (r > n)
        return 0;

    r = max(r, n - r); // optimization
    ll ans = 1, div = 1, i = r + 1;
    while (i <= n) {
        ans *= i; ++i;
        ans /= div; ++div;
    }

    return ans;
}

unsigned long long nPr(int n, int r)
{
    if (r > n)
        return 0;
    unsigned long long p = 1, i = n - r + 1;

    while (i <= n)
    {
        p *= i++;
    }

    return p;
}

///////////////////// Evaluate Expression //////////////////////////////////////

double operate(double x, double y, char op) {
    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '^':
            return pow(x, y);
        default:
            return 0;
    }
}

string infix_to_postfix(string infix) { // O(n) time
    // for simplicity:
    // all numbers are single digits, string has no spaces
    // operators are: +, -, *, /, ()

    Stack<char> operators;
    string postfix;

    map<char, int> rank;
    rank['+'] = rank['-'] = 1;
    rank['*'] = rank['/'] = 2;
    rank['^'] = 3;
    rank['('] = 0;

    // coding tricks:
    infix += '+'; // lowest priority: force the stack to go empty
    operators.push('#'); // with rank = 0, to avoid isEmpty using
    int n = infix.size();
    for (int i = 0; i < n; ++i) {
        if (isdigit(infix[i]))
            postfix += infix[i];
        else {
            if (infix[i] == '(') operators.push(infix[i]);
            else if (infix[i] == ')') {
                while (operators.top() != '(')
                    postfix += operators.pop();
                operators.pop();
            }
            else {
                while (rank[infix[i]] < rank[operators.top()] or (rank[infix[i]] == rank[operators.top()] and infix[i] != '^')) // handle ^, b. it's right to left
                    postfix += operators.pop();
                operators.push(infix[i]);
            }
        }
    }

    return postfix;
}

double evaluate_postfix_exp(string exp) {
    // expression must have NO spaces

    Stack <double> stk;

    int n = exp.size();
    for(int i = 0; i < n; ++i) {
        if(isdigit(exp[i])) stk.push(int(exp[i] - '0'));
        else {
            double y = stk.pop(), x = stk.pop(); // remove last 2 elements
            stk.push(operate(x, y, exp[i]));
        }
    }

    return stk.top();
}

///////////////////// Modular Arithmetics Template //////////////////////////////////////

template<int mod = MOD>
struct mint {
private:
    // assume -P <= x < 2P, (it's faster)
    int norm(int x) const {
        if (x < 0)
            x += mod;
        if (x >= mod)
            x -= mod;
        return x;
    }

public:
    int x;
    mint(int32_t x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    int val() const { return x; }
    mint operator-() const { return mint(norm(mod - x)); }
    mint inv() const {
        assert(x != 0);
        return power(mod - 2);
    }
    mint power(ll b) const {
        mint res = 1, a = x;
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
    mint &operator*=(const mint &rhs) {
        x = (ll)x * rhs.x % mod;
        return *this;
    }
    mint &operator+=(const mint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    mint &operator-=(const mint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    mint &operator/=(const mint &rhs) { return *this *= rhs.inv(); }
    friend mint operator*(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res *= rhs;
        return res;
    }
    friend mint operator+(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res += rhs;
        return res;
    }
    friend mint operator-(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res -= rhs;
        return res;
    }
    friend mint operator/(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, mint &a) {
        ll v;
        is >> v;
        a = mint(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mint &a) {
        return os << a.val();
    }
    friend mint max(mint a, mint b) {
        return a.x > b.x ? a : b;
    }
    friend mint min(mint a, mint b) {
        return a.x < b.x ? a : b;
    }
};

using Z = mint<>;

////////////////////

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

///////// Decimal <=> Base /////////
string hex_letters = "0123456789ABCDEF";
int toInt(char c) { return hex_letters.find(c); }

ll baseToDecimal(string in, int base) {
    ll res = 0;
    for (char c : in)
        res *= base, res += toInt(c);
    return res;
}
string decimalToBase(ll number, int base) {
    if (number == 0)
        return "0";

    string res;
    while (number) {
        res = hex_letters[number % base] + res; // notice that we add to the left, to the upper value
        number /= base;
    }
    return res;
}

/////////////// Matrix Stuff ///////////////////
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
