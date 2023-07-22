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