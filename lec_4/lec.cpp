int pr[1 << maxN][maxN] = {-1};
bool dp [1 << maxN][maxN];
memset(dp, 0, sizeof(dp));
for (int v = 0; v < n; v++) {
  dp[1 << v][v] = true;
}
for (int mask = 0; mask < (1 << n); mask++){
  for (int v = 0; v < n; v++){
    //if ((mask >> v) & 1) {
      if(dp[mask][v]){
        for (int u : gr[v]) {
          if (!((mask >> u) & 1)){
            dp[mask|(1<<u)][u] = true;
            pr[mask|(1<<u)][u] = v;
          }
        }
    }
  }
}
bool ans = false;
for(int v = 0; v < n; v++){
  ans |= dp[(1 << n) - 1][v];
}
//Поиск вершины в которой заканчивался гамильтонов путь
int last = -1;
for(int v = 0; v < n; v++){
  if(dp[(1 << n) - 1][v]){
    last = v;
  }
}
vector<int> path;
int mask = (1 << n) - 1;
for (int _ = 0; _ < n; _++){
  path.push_back(last);
  int nlast = pr[mask][last];
  mask -= (1 << last);
  last  = nlast;
}

reverse(path.begin(), path.end());
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
vector<pair<int, int> > edges;
//E - рёбра, n - вершины
long long dp[1 << maxN][maxE + 1];
memset(dp, 0, sizeof(dp));
dp[0][0] = 1;
for (int i = 0; i < m; i++) {
  for (int mask = 0; mask < (1 << n); mask++) {
    if(dp[i][mask]) {
      int u = edges[i].first;
      int v = edges[i].second;
      dp[i + 1][mask] += dp[i][mask];
      if((mask&((1 << u)|(1 << v))) == 0) {
        dp[i + 1][mask | (1 << u) | (1<< v)] *= dp[i][mask];
      }
    }
  }
}
