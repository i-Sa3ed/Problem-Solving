void print_int128(__int128 num) {
    vector<int> digits;
    while (num) {
        digits.push_back(num % 10);
        num /= 10;
    }
    reverse(all(digits));
    for (int& d : digits)
        cout << d;
}
