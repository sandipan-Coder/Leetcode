struct SegTree {
    struct Node {
        int mn = 0, mx = 0, lazy = 0;
    };

    int n;
    vector<Node> st;

    SegTree(int n_) : n(n_), st(4 * n_) {}

    // add a value v to the node p
    void apply(int p, int v) {
        st[p].mn += v;
        st[p].mx += v;
        st[p].lazy += v;
    }

    // to push the lazy value to the childrens else values get outdated
    void push(int p) {
        if (st[p].lazy != 0) {
            apply(p << 1, st[p].lazy);
            apply(p << 1 | 1, st[p].lazy);
            st[p].lazy = 0;
        }
    }

    // used by parent to update its mn and mx from childrens
    void pull(int p) {
        st[p].mn = min(st[p << 1].mn, st[p << 1 | 1].mn);
        st[p].mx = max(st[p << 1].mx, st[p << 1 | 1].mx);
    }

    // updating the ranges
    void rangeAdd(int p, int l, int r, int ql, int qr, int v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(p, v);
            return;
        }
        push(p);
        int m = (l + r) >> 1;
        rangeAdd(p << 1, l, m, ql, qr, v);
        rangeAdd(p << 1 | 1, m + 1, r, ql, qr, v);
        pull(p);
    }

    void rangeAdd(int l, int r, int v) {
        if (l > r) return;
        rangeAdd(1, 0, n - 1, l, r, v);
    }

    // Find leftmost index in [ql..qr] where value == 0, else -1
    int leftmostZero(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return -1;
        if (st[p].mn > 0 || st[p].mx < 0) return -1; // can't contain 0
        if (l == r) return l;

        push(p);
        int m = (l + r) >> 1;
        int left = leftmostZero(p << 1, l, m, ql, qr);
        if (left != -1) return left;
        return leftmostZero(p << 1 | 1, m + 1, r, ql, qr);
    }

    int leftmostZero(int ql, int qr) {
        if (ql > qr) return -1;
        return leftmostZero(1, 0, n - 1, ql, qr);
    }
};



class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        

        int n = (int)nums.size();

        SegTree st(n);                 // A[l] initially 0 for all l (when r = -1)
        unordered_map<int,int> last;   // last occurrence index
        last.reserve(n * 2);

        int ans = 0;

        for (int r = 0; r < n; r++) {
            int x = nums[r];
            int prev = -1;

            auto it = last.find(x);
            if (it != last.end()) prev = it->second;

            int delta = (x & 1) ? +1 : -1;   // odd:+1, even:-1 for A = odd-even

            st.rangeAdd(prev + 1, r, delta); // x becomes newly distinct for these l
            last[x] = r;

            int l0 = st.leftmostZero(0, r);  // earliest l with A[l] == 0
            if (l0 != -1) ans = max(ans, r - l0 + 1);
        }

        return ans;
    }
};