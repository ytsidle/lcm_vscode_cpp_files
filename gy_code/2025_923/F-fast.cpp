#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 7;
#define ls (p << 1)
#define rs (p << 1 | 1)
struct Node {
    int sum2, sum3, sum4;
} tree[4 * M];
int MAX;
void push_up(int p) {
    tree[p].sum2 = tree[ls].sum2 & tree[rs].sum2;
    tree[p].sum3 = tree[ls].sum3 & tree[rs].sum3;
    tree[p].sum4 = tree[ls].sum4 & tree[rs].sum4;
}
void update(int p, int l, int r, int idx, const Node& val) {
    if (l == r) {
        tree[p] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (idx <= mid) {
        update(ls, l, mid, idx, val);
    } else {
        update(rs, mid + 1, r, idx, val);
    }
    push_up(p);
}
Node query(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return tree[p];
    }
    int mid = (l + r) >> 1;
    Node res = { MAX, MAX, MAX };
    bool has_left = false;
    if (L <= mid) {
        Node left = query(ls, l, mid, L, R);
        res.sum2 &= left.sum2;
        res.sum3 &= left.sum3;
        res.sum4 &= left.sum4;
        has_left = true;
    }
    if (mid < R) {
        Node right = query(rs, mid + 1, r, L, R);
        if (has_left) {
            res.sum2 &= right.sum2;
            res.sum3 &= right.sum3;
            res.sum4 &= right.sum4;
        } else {
            res = right;
        }
    }
    return res;
}
inline bool check_num(int num) {
    return num == MAX;
}
inline int lowbit(int num){
	return (-num)&num;
}
inline int count_ones(int num) {
    int re=0;
	while(num){
		num-=lowbit(num);
		re++;
	}
	return re;
}

int n, m, q;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    MAX = (1 << n) - 1;
    for (int i = 1; i <= m; ++i) {
        Node node = {0, 0, 0};
        for (int j = 0; j < n; ++j) {
            char xc;
            cin >> xc;
            if (xc == '1' || xc == '0') {
                int bit = xc - '0';
                node.sum2 = (node.sum2 << 1) | bit;
                node.sum3 = (node.sum3 << 1) | (1 - bit);
            } else { 
                node.sum2 = (node.sum2 << 1) | 1;
                node.sum3 = (node.sum3 << 1) | 1;
            }
            node.sum4 = (node.sum4 << 1) | (xc == '?' ? 1 : 0);
        }
        update(1, 1, m, i, node);
    }

    int ans = 0;
    while (q--) {
        int op;
        cin >> op;
        
        if (op == 0) {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 1, m, l, r);
            
            if (check_num(res.sum2 | res.sum3)) {
                ans ^= (1 << count_ones(res.sum4));
            }
        } else { 
            int id;
            cin >> id;
            Node node = {0, 0, 0};
            
            for (int j = 0; j < n; ++j) {
                char xc;
                cin >> xc;
                
                if (xc == '1' || xc == '0') {
                    int bit = xc - '0';
                    node.sum2 = (node.sum2 << 1) | bit;
                    node.sum3 = (node.sum3 << 1) | (1 - bit);
                } else {
                    node.sum2 = (node.sum2 << 1) | 1;
                    node.sum3 = (node.sum3 << 1) | 1;
                }
                node.sum4 = (node.sum4 << 1) | (xc == '?' ? 1 : 0);
            }
            update(1, 1, m, id, node);
        }
    }
    cout << ans << endl;
    return 0;
}
