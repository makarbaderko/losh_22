//g4 dominoes
dp[i][mask];
memset(dp, 0, sizeof(dp));
for (int i = 0; i < m; i++){
  for (int mask = 0; mask < (1 << n); mask++){
    if(dp[i][mask]){
      int &d = dp[i][mask];
      for (int nmask = 0; nmask < (1 << n); nmask++){
        if(areNeighbouring(mask, nmask, n)) {
          dp[i + 1][nmask] += dp[i][mask]
        }
      }
    }
  }
}
//1 - клеточка занята, 0 - не занята (ДП по профилю)
//mask - какие клеточки заняты в этом столбце, nmask - какие клеточки заняты в следующем столбце.
bool areNeighbouring(int mask, int nmask, int n){
  if (mask&nmask){
    return false;
  } else{
    return makeZeroesBeCoveredByVerticalDominoes(mask|nmask, n);
  }
}
bool makeZeroesBeCoveredByVerticalDominoes(int mask, int n) {
  for (int i = 0; i < n;) {
    if ((mask >> i)&1){
      i++;
    } else if (i + 1 == n || ((mask >> (i + 1) & 1))){
      return false;
    } else{
      i+=2;
    } return true;
  }
}
