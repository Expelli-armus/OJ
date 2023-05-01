#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int n, q, a[N], tr[N];

int lowbit(int x) { return x & -x; }

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main() {
    cin >> n >> q;
    // 初始化
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        add(i, a[i]);
    }
    // 查询、修改操作
    while (q --) {
        int k, x, y; cin >> k >> x >> y;
        if (k == 1) add(x, y - a[x]), a[x] = y; // 修改
        else cout << query(y) - query(x - 1) << endl; // 查询
    }
    return 0;
}

