#include <iostream>
#include <vector>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    string name;
    cin >> name;
    vector<vector<string> > cubes;
    vector<vector<string> > right;
    vector<vector<int> > left(n, 0);
    for (int i = 0; i < n; i++) {
        vector<string> cube;
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            cube.push_back(s);
        }
        cubes.push_back(cube);
    }
}