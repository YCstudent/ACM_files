#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int T, tmp;

int a[N], d[N];

int find(int x) {
    int l = 1, r = tmp;

    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}

int main() {
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int i = 1; i <= n; i++) d[i] = a[i];

        sort(a + 1, a + n + 1);
        tmp = unique(a + 1, a + n + 1) - a;

        for (int i = 1; i <= n; i++) {
            d[i] = find(d[i]);

            cout << d[i] << " ";
        }
        cout << endl;
    }
    return 0;
}