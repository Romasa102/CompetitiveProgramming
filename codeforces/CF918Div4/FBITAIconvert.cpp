#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

// --- Fenwick Tree (BIT) ---
struct FenwickTree {
    int size;
    vector<int> tree;

    // Initialize with size n
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    // Add x to index i (1-based internally)
    void add(int i, int x) {
        for (i++; i <= size; i += i & -i) {
            tree[i] += x;
        }
    }

    // Sum from [0, i]
    int query(int i) {
        int sum = 0;
        for (i++; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<P> ab(n);
    vector<ll> vals; // For coordinate compression

    for (int i = 0; i < n; ++i) {
        cin >> ab[i].first >> ab[i].second;
        vals.push_back(ab[i].second);
    }

    // 1. Sort Pairs by First Element (Same as original)
    sort(ab.begin(), ab.end());

    // 2. Coordinate Compression
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    // Helper to get rank (0-based index)
    auto get_rank = [&](ll v) {
        return lower_bound(vals.begin(), vals.end(), v) - vals.begin();
    };

    // 3. Process with BIT
    FenwickTree bit(vals.size());
    ll ans = 0;

    // Add the first element (ab[0]) to BIT
    // Original code: st.push_back(ab[0].second) BEFORE loop
    bit.add(get_rank(ab[0].second), 1);

    for (int i = 1; i < n; ++i) {
        ll current_val = ab[i].second;
        int rank = get_rank(current_val);

        // Original logic: Count elements >= current_val
        // BIT Logic: Total elements so far (i) - Count elements strictly smaller
        // query(rank - 1) gives count of elements < current_val
        ll count_smaller = bit.query(rank - 1);
        ll count_ge = i - count_smaller;

        ans += count_ge;

        // Add current element to BIT
        bit.add(rank, 1);
    }

    cout << ans << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}