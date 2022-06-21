#include <iostream>
#include <vector>
#include<string>

using namespace std;

int main(){
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int m, n;
        cin >> m >> n;
        vector<vector<int> > gr(m);
        for (int i = 0; i < m; i++) {
            vector<int> vec;
            while(true){
                int v;
                cin >> v;
                if(v == 0) {
                    break;
                } 
                vec.push_back(v);
            }
            gr[i] = vec;
        }
        
    }
}