#include <iostream>
using namespace std;

int main() {
    long long a, b, c, r;
    long long x, y;
    cin >> a >> b >> c >> r;
    if (b){
        x = 0;
        y = -c/b;
    } 
    else {
        y = 0;
        x = -c / a;
    }
    cout << a << ' ' << b << ' ' << fixed << setprecision(5) << r * sqrt(pow(b, 2) + pow(a, 2)) - a * x - b * y;
}
