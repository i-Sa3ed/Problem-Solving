// bitset: set, reset, flip
int a = 0b111111;
bitset<6> bs = a;
bs.reset(0);
bs.reset(4);
cout << bs.to_string() << endl;

bs.set(0), bs.set(4);
cout << bs.to_string() << endl;


// a way to check is power of 2
//      a = 00000010000 => power of 2, b. it has only 1 bit with 1
//     -a = 11111110000
// a & -a = 00000010000
// then, a & -a must = a
int x = 256;
if (x == (x & -x))
cout << "YES\n";
else cout << "NO\n";

/// get MSB
// using a trivial for loop
int msb;
for (int i = 0; i < 32; ++i) {
if (x >> i & 1)
msb = i;
}
cout << "MSB = " << msb << endl;

// using clz
msb = 31 - __builtin_clz(x); // clz = count leading zeros
// if int => 31
// if ll => 63
// the general formula: size (64/32) = 1 + leading zeros + msb
cout << "MSB = " << msb << endl;

// using popcount
int count_ones = __builtin_popcount(x);
if (count_ones == 1)
cout << "power of 2\n";


/* // XOR Notes
 *
 * (a ^ a) = 0
 * (0 ^ a) = a
 * problem idea: given an array of 1e9 numbers, calc xor of them.
 * to solve it, check the freq of each number, and ignore numbers with even freq ;)
 */