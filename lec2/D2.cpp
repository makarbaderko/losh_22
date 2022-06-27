#include <iostream>
#include <vector>
#include<algorithm>


using namespace std;
vector<long long> t;
long long n;

long long sum(long long x) {
    long long res = 0;
    for (long long i = x; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

void add(long long x, long long delta) {
    for (long long i = x; i < n; i = (i | (i + 1)))
        t[i] += delta;
}

int main() {
    vector<pair<long long, long long>> reqsts;
    vector<long long> list;
    char com;
    long long x;
    while (cin >> com >> x) {
        if (com == '+') {
            reqsts.emplace_back(1, x);
            list.push_back(x);
        } else {
            reqsts.emplace_back(0, x);
        }
    }
    n = list.size();
    t = vector<long long>(n, 0);
    sort(list.begin(), list.end());

    for (auto req: reqsts) {
        long long l = -1, r = n, m;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (list[m] <= req.second) {
                l = m;
            } else {
                r = m;e
            }
        }
        if (req.first) {
            add(l, req.second);
        } else {
            if (l > -1) {
                cout << sum(l) << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}
