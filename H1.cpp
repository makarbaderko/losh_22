#include <cstdio>
#include <vector>
#define MAX 102
using namespace std;

char s[MAX][MAX];
int empty, res, n, m, a, b, i, j, c;
vector<vector<int> > g;
vector<int> mt, used, par;

int dfs(int v)
{
  if (used[v]) return 0;
  used[v] = 1;
  for (int i = 0; i < g[v].size(); i++)
  {
    int to = g[v][i];
    if (mt[to] == -1 || dfs(mt[to]))
    {
      mt[to] = v;
      par[v] = to;
      return 1;
    }
  }
  return 0;
}

void AugmentingPath(void)
{
  int i, j, run;
  mt.assign(n*m, -1);
  par.assign (n*m, -1);

  for (run = 1; run; )
  {
    run = 0; used.assign(n*m, 0);
    for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
    {
      if ((i + j) % 2) continue;
      if ((par[i * m + j] == -1) && dfs(i * m + j)) run = 1;
    }
  }
}

int main(void)
{
  scanf("%d %d %d %d\n", &n, &m, &a, &b);
  for(i = 0; i < n; i++) gets(s[i]);

  g.resize(n*m); empty = 0;
  for(i = 0; i < n; i++)
  for(j = 0; j < m; j++)
  {
    if (s[i][j] == '.') continue;
    empty++;
    if ((i + j) % 2) continue;
    int u = i*m + j;
    if (j           && (s[i][j-1] == '*')) g[u].push_back(u - 1);
    // left
    if ((j < m - 1) && (s[i][j+1] == '*')) g[u].push_back(u + 1);
    // right
    if (i           && (s[i-1][j] == '*')) g[u].push_back(u - m);
    // up
    if ((i < n - 1) && (s[i+1][j] == '*')) g[u].push_back(u + m);
    // down
  }

  if (2 * b <= a)
  {
    printf("%d\n",empty*b);
    return 0;
  }

  AugmentingPath();

  for (c = i = 0; i < n * m; i++)
    if (mt[i] != -1) c++;

  res = c * a + (empty - 2*c) * b;
  printf("%d\n",res);
  return 0;
}
