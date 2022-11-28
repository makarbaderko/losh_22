#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Найти самую длинную строку формата ssssss которая будет последней лексикографически


bool isMonotonous(string s){
  vector<int> letters;
  for (int i = 0; i < s.length(); i++){
    letters.push_back(int(s[i]));
  }
  vector<int> up = letters;
  sort(up.begin(), up.end());
  vector<int> down = up;
  reverse(down.begin(), down.end());
  if ((letters == up) or (letters == down)) {
    return true;
  }
  return false;
}

string lex(string a, string b){
  vector<string> g(2);
  g[0] = a;
  g[1] = b;
  sort(g.begin(), g.end());
  return g[1];
}

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
}
