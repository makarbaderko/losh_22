int goUp(int v, int h) {
  for (int l = log2n; l>=0; --l){
    if (h >= (1 << l)){
      v = up[v][l];
      h -= (1 <<l);
    }
  }
  return v;
}

int lca(u, v) {
  if (isAncestor(u, v)){
    return u
  }
  for (l = log2n; l >= 0){
    if (!isAncestor(up[u][l], v)) {
      u = up[u][p];
    } return;
  }
}
