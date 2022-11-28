#include <iostream>
#include <set>
#include <vector>

using namespace std;
long long one = 1;
long long mod = 1e9 + 9;
long long mod1 = 1e9 + 7;
long long osn = 29;
vector<long long> osn_pow;
vector<long long> osn_pow_1;
vector<long long> a_hashed;
vector<long long> a_hashed_1;
vector<long long> b_hashed;
vector<long long> b_hashed_1;
long long left_bound;
long long right_bound;

long long check(long long a, long long b, long long any_module) {
    if (a < 0){
        a -= b;
        a += any_module;
        return a;
    } a -= b;
    return a;
}

long long multiply(long long a, long long b, long long any_module) {
    return (a * 1ll * b) % any_module;
}

long long hash_sub_str(string& s, long long l, long long r, vector<long long>& s_hashes, long long any_module, vector<long long>& powers) {
    if (l == 0) {
        return s_hashes[r];
    }
    return check(s_hashes[r], mul(s_hashes[l - 1], powers[r - l + 1], modulo), modulo);

}

bool has_common(long long k, string& a, string& b) {
    //Проверяет есть ли в двух хешированных строках одинаковая подстрока размера k
    //Честно скопипастил с ideona который лежал на кфе) Извините, Филипп Дмитриевич. Остальное подчерпнул идею) Не бейте, пожалуйста.
    set<pair<long long, long long> > used;
    long long n = a.size();
    for (long long i = 0; i < n - k + 1; i++) {
        used.insert(make_pair(hash_sub_str(a, i, i + k - 1, a_hashed, mod, osn_pow), hash_sub_str(a, i, i + k - 1, a_hashed_1, mod1, osn_pow_1)));
    }

    for (long long i = 0; i < n - k + 1; i++) {
        if (used.find(make_pair(hash_sub_str(b, i, i + k - 1, b_hashed, mod, osn_pow), hash_sub_str(b, i, i + k - 1, b_hashed_1, mod1, osn_pow_1))) != used.end()) {
            left_bound = i;
            right_bound = i + k;
            return true;
        }
    }
    return false;
}


int main() {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
	osn_pow.push_back(1);
    osn_pow_1.push_back(1);
	for (long long i = 0; i < n; i++) {
			osn_pow.push_back((osn_pow.back() * osn) % mod);
	}
	for (long long i = 0; i < n; i++) {
			osn_pow_1.push_back((osn_pow_1.back() * osn) % mod1);
	}

	a_hashed.push_back(((a[0] - 'a')) % mod);
    b_hashed.push_back(((b[0] - 'a')) % mod);
	for (long long i = 1; i < n; i++) {
			a_hashed.push_back((a_hashed.back() * osn + (a[i] - 'a')) % mod);
	}
	for (long long i = 1; i < n; i++) {
			b_hashed.push_back((b_hashed.back() * osn + (b[i] - 'a')) % mod);
	}
	a_hashed_1.push_back(((a[0] - 'a')) % mod1);
    b_hashed_1.push_back(((b[0] - 'a')) % mod1);
    for (long long i = 1; i < n; i++) {
        a_hashed_1.push_back((a_hashed_1.back() * osn + (a[i] - 'a')) % mod1);
    }
    for (long long i = 1; i < n; i++) {
        b_hashed_1.push_back((b_hashed_1.back() * osn + (b[i] - 'a')) % mod1);
    }

    long long l = 0;
    long long r = n + 1;

    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (has_common(mid, a, b)) {
            l = mid;
        } else {
            r = mid;
        }
    }


    for (long long i = left_bound; i < right_bound; i++) {
        cout << b[i];
    }
    return 0;
}
