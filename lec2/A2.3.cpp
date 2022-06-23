#include <iostream>
#include <vector>
#include <string>


using namespace std;
int n, k;
vector< vector<int> > t;

int sum (int x, int y)
{
	int result = 0;
	for (int i = x; i >= 0; i = (i & (i+1)) - 1)
		for (int j = y; j >= 0; j = (j & (j+1)) - 1)
			result += t[i][j];
	return result;
}

void add (int x, int y)
{
	for (int i = x; i < n; i = (i | (i+1)))
		for (int j = y; j < n; j = (j | (j+1)))
			t[i][j]++;
}

int main() {
    int n, k;
    cin >> n >> k;
    t.resize(n);
    for (int i = 0; i < k; i++){
        string req;
        cin >> req;
        if (req == "ADD") {
            int x, y;
            cin >> x >> y;
            add(x, y);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << sum(x2,y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) - sum(x1 - 1, y1 - 1) << endl;
        }
    }
}