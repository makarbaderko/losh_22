#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Shift {
    int dx, dy;
};

int getIdx(int x, int y, int m) {
    return (x - 1) * m + y - 1;
}
bool dfs(int from, vector<vector<int>> &leftPart, vector<int> &rightPart, vector<int> &mark) {
    if (mark[from]) return false;
    mark[from] = true;
    for (int to: leftPart[from]) {
        if (rightPart[to] == -1 || dfs(rightPart[to], leftPart, rightPart, mark)) {
            rightPart[to] = from;
            return true;
        }
    }
    return false;
}

void kuhn(int n, int m, vector<vector<int>> &leftPart, vector<pair<int, int>> &matching) {
    auto rightPart = vector<int>(m, -1);
    auto mark = vector<int>(n, false);

    for (int i = 0; i < leftPart.size(); ++i) {
        if (dfs(i, leftPart, rightPart, mark))
            mark.assign(n, false);
    }
    matching = vector<pair<int, int>>();
    for (int i = 0; i < rightPart.size(); ++i)
        if (rightPart[i] != -1)
            matching.emplace_back(rightPart[i] + 1, i + 1);
}

int main() {
    char c;
    int n, m, a, b, empty = 0;
    cin >> n >> m >> a >> b;
    vector<vector<int>> field(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> leftPart(n * m);
    vector<pair<int, int>> matching;
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= m; ++y) {
            cin >> c;
            if (c == '*') {
                ++empty;
                field[x][y] = 1;
            }
        }
    vector<Shift> shifts = {{1,  0},
                            {-1, 0},
                            {0,  1},
                            {0,  -1}};
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= m; ++y)
            if ((x + y) % 2 == 0 && field[x][y])
                for (Shift const &shift: shifts) {
                    int n_x = x + shift.dx;
                    int n_y = y + shift.dy;
                    if (field[n_x][n_y])
                        leftPart[getIdx(x, y, m)].push_back(getIdx(n_x, n_y, m));
                }
    kuhn(n * m, n * m, leftPart, matching);
    int size = matching.size();
    cout << min(b * empty, a * size + b * (empty - 2 * size));
}
