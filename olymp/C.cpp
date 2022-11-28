#include <iostream>

using namespace std;

int main() {
  cout << "? f3" << endl;
  cout.flush();
  int ans;
  cin >> ans;
  if (ans == 0) {
    // kon, lad, pesh;
    cout << "? f4" << endl;
    cout.flush();
    cin >> ans;
    if (ans == 1) {
      //curr = f4
      cout << "? e2" << endl;
      cout.flush();
      cin >> ans;
      cout << "! n" << endl;
      cout.flush();
    } else {
      //lad pesh
      cout << "? e1" << endl;
      cout.flush();
      cin >> ans;
      if (ans == 1) {
        //curr = e1
        cout << "? e2" << endl;
        cout.flush();
        cin >> ans;
        cout << "! r" << endl;
      } else {
        cout << "! p" << endl;
      }
    }
  } else {
    //slon, korol, ferz
    cout << "? f2" << endl;
    cout.flush();
    cin >> ans;
    if (ans == 1) {
      //korol, ferz
      cout << "? d2" << endl;
      cout.flush();
      cin >> ans;
      if (ans == 1) {
        cout << "? e2" << endl;
        cout.flush();
        cin >> ans;
        cout << "! q" << endl;
        cout.flush();
      } else {
        cout << "? e2" << endl;
        cout.flush();
        cin >> ans;
        cout << "! k" << endl;
        cout.flush();
      }
    } else {
      cout << "? e2" << endl;
      cout.flush();
      cin >> ans;
      cout << "! b" << endl;
      cout.flush();
    }
  }
}
