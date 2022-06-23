#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n, k;
vector< vector<int> > t;

void add (int x, int y)
{
	for (int i = x; i < n; i = (i | (i+1)))
		for (int j = y; j < n; j = (j | (j+1)))
			t[i][j]++;
}

int summ(int y1, int y2, int x) {
    int result;
    for (int i = y1; i <= y2; i++) {
        result += t[x][i];
    }
    return result;
}

int main() {
    int n, k;
    t.resize(n);
    for (int i = 0; i < k; i++) {
        string req;
        cin >> req;
        if (req == "ADD") {
            int x, y;
            cin >> x >> y;
            add(x, y);
        } else {
            int x1, y1, x2, y2;
            int res;
            for (int i = x1; i <= x2; i++) {
                res += summ(y1, y2, i);
            }
            cout << res << endl;
        }
    }
}