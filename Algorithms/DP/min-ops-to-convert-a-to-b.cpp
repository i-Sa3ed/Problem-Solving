int n, m;
/// be careful with MAX value: a source for RTE :(
const int MAX = 1e9, M = 1e4;
int memory[2*M + 10];

int dp_minimize(int num) {
    if (num == m)
        return 0;
    if (num <= 0 or memory[num] == MAX) // out of boundary or cycle
        return MAX;

    int& ret = memory[num];
    if (ret != -1)
        return ret;
    ret = MAX; // visited

    // operations: represents the next choices
    int minus = 1 + dp_minimize(num - 1);
    int multiply = num < m? 1 + dp_minimize(num*2) : MAX;

    return ret = min(minus, multiply);
}