bool isPrime(int x) {
    if(x == 0 or x == 1)
        return false;
    if(x == 2)
        return true;

    for (ll i = 2; i*i <= x; ++i) {
        if(x % i == 0)
            return false;
    }
    return true;
}

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

unsigned long long nCr (int n, int r)
{
    if (r > n)
        return 0;
    r = max(r, n - r);
    unsigned long long ans = 1, div = 1, i = r + 1;

    while (i <= n)
    {
        ans *= i;
        i++;
        ans /= div;
        div++;
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
