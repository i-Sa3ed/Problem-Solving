void getAllSubMasks(int mask) {
    // prints all subsets of SET bits only.

    for(int subMask = mask ; subMask ; subMask = (subMask - 1) & mask) {
        bitset<32> b(subMask);
        cout << b << endl;
    }

    // For reverse: ~subMask&mask = subMask^mask
}

// Application: vis array in an efficient way
const int MAX = 100000000;
bool vis[MAX / 8 + 1];
void setVisited(int i) { // in past: vis[i] = 1
    vis[i >> 3] |= (1 << (i & 7));
    // vis[i / 8] |= (1 << (i % 8));
    // Here we utilize every single bit inside bool byte!
}
bool isVisited(int i) { // in past: if (vis[i])
    return vis[i >> 3] & (1 << (i & 7));
}