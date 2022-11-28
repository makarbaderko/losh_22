#include <iostream>
#include <string>


using namespace std;


const int maxN = 128;


bool isNumeric(const string &str) {
    char* p;
    strtol(str.c_str(), &p, 10);
    return *p == 0;
}


struct Trie {
   struct Trie *children[maxN];
   bool isTerminal;
};
struct Trie *buildnewNode(void)
   struct Trie *newNode = new Trie;
   newNode -> isTerminal = false;
   for (int i = 0; i < maxN; i++)
      newNode  ->  children[i] = NULL;
   return newNode;
}
void insert(struct Trie *root, string key) {
   struct Trie *curr = root;
   for (int i = 0; i < key.length(); i++) {
      int index = key[i] - 'A';
      if (!curr -> children[index])
         curr -> children[index] = buildnewNode();
         curr = curr -> children[index];
   }
   curr -> isTerminal= true;
}
bool search(struct Trie *root, string key) {
   struct Trie *curr = root;
   for (int i = 0; i < key.length(); i++) {
      int index = key[i] - 'A';
      if (!curr -> children[index])
         return false;
      curr = curr -> children[index];
   }
   return (curr != NULL && curr -> isTerminal);
}

int main() {
  int n;
  cin >> n;
  string text, req;
  cin >> text;
  struct Trie *root = buildnewNode();
  for (int from = 0; from < text.length() - 28
}
