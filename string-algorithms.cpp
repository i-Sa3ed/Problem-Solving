////////////////////////////// Palindrome Stuff /////////////////////////////

bool is_palindrome(string& s) {
    int n = s.size();
    for (int i = 0; i < n/2; ++i) {
        if (s[i] != s[n-1-i])
            return false;
    }
    return true;
}

string build_palindrome_min_lexi(vector<int>& frq) {
    string half;
    char odd = '*';
    for(int i = 0; i < 26; ++i) {
        half += string(frq[i] / 2, char(i + 'a'));
        if(frq[i] & 1)
            odd = char(i + 'a');
    }

    string res = half;
    if (odd != '*') res += odd;
    reverse(all(half));
    res += half;

    return res;
}

// check if we can make the string palindrome by reordering it
bool can_be_palindrome(string s) {
    int alp[26] = {};
    for (char c : s)
        alp[c-'a']++;

    int oddFrq = 0;
    for (int i : alp) {
        oddFrq += (i & 1);
    }

    return oddFrq <= 1;
}

////////////////////////////// Capitalization /////////////////////////////

string string_tolower(string x) {
    string res;
    for (char c : x)
        res += tolower(c);
    return res;
}

string string_toupper(string x) {
    string res;
    for (char c : x)
        res += toupper(c);
    return res;
}
