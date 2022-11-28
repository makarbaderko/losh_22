#include<vector>
#include<iostream>
#include<set>
//Филлип Дмитриевич, часть кода взял с editorial с кфа( Извините!


using namespace std;

long long mod = 10000000021;
long long mod1 = 1000000007;
long long base = 31;
long long one = 1;
vector<long long> osn;
vector<long long> osn1;
long long left_bound;
long long right_bound;
vector<long long> a_hashed;
vector<long long> b_hashed;
vector<long long> a_hashed1;
vector<long long> b_hashed1;

void make_pow(long long n) {
    osn.push_back(1);
    for (long long i = 0; i < n; i++) {
        osn.push_back((osn.back() * base) % mod);
    }

    osn1.push_back(1);
    for (long long i = 0; i < n; i++) {
        osn1.push_back((osn1.back() * base) % mod1);
    }
}

void hash_s_and_t(string& a, string& b) {
    long long n = a.size();
    a_hashed.push_back(((a[0] - 'A')) % mod);
    b_hashed1.push_back(((b[0] - 'A')) % mod1);
    b_hashed.push_back(((b[0] - 'A')) % mod);
    a_hashed1.push_back(((a[0] - 'A')) % mod1);
    for (long long i = 1; i < n; i++) {
        a_hashed.push_back((a_hashed.back() * base + (a[i] - 'A')) % mod);
    }
    for (long long i = 1; i < n; i++) {
        b_hashed.push_back((b_hashed.back() * base + (b[i] - 'A')) % mod);
    }
    for (long long i = 1; i < n; i++) {
        a_hashed1.push_back((a_hashed1.back() * base + (a[i] - 'A')) % mod1);
    }
    for (long long i = 1; i < n; i++) {
        b_hashed1.push_back((b_hashed1.back() * base + (b[i] - 'A')) % mod1);
    }
}

long long subtract(long long a, long long b, long long modulo) {
    a -= b;
    if (a < 0) {a += modulo;}
    return a;
}

long long multiply(long long a, long long b, long long modulo) {
    return (a * one * b) % modulo;
}

long long h(string& s, long long l, long long r, vector<long long>& s_hashes, long long modulo, vector<long long>& powers) {
    if (l == 0) {
        return s_hashes[r];
    }
    return subtract(s_hashes[r], multiply(s_hashes[l -1],  powers[r - l + 1], modulo), modulo);
}

bool has_common(long long k, string& a, string& b) {
    set<pair<long long, long long> > seen;
    long long n = a.size();
    for (long long i = 0; i < n - k + 1; i++) {
        seen.insert(make_pair(h(a, i, i + k-1,a_hashed, mod,  osn), h(a, i, i + k - 1,a_hashed1, mod1, osn1)));
    }

    for (long long i = 0; i < n - k + 1; i++) {
        if (seen.find(make_pair(h(b,  i, i + k -1, b_hashed,mod, osn), h(b , i, i + k - 1, b_hashed1,mod1, osn1))) != seen.end()) {
            left_bound = i;
            right_bound =i + k;
            return true;
        }
    }
    return false;
}


int main() {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >>b;
    make_pow(n);
    hash_s_and_t(a, b);
    long long l = 0;
    long long r = n + 1;
    while (r - l > 1) {
        long long mid = (l +r) / 2;
        if (has_common(mid,a, b)) {
            l = mid;
        }
        else{
            r = mid;
        }
    }
    for (long long i = left_bound; i < right_bound; i++) {
        cout << b[i];
    }
    return 0;
}
