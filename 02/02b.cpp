#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
std::ostream & operator<< (std::ostream & os, const std::vector<T> & v) {
    os << "[ ";
    for (const T & elem : v)
        os << elem << " ";
    os << "]";
    return os;
}

ll num_of_digits(ll num) {
    if (num == 0)
        return 1;
    ll ret = 1;
    while (num /= 10)
        ++ret;
    return ret;
}

ll power(ll a, ll b) {
    ll ret = 1;
    while (b--)
        ret *= a;
    return ret;
}

ll invalid_id_sum_in_range(ll low, ll high) {
    ll low_digits = num_of_digits(low);
    ll high_digits = num_of_digits(high);
    
    ll ret = 0;
    set<ll> already_used;
    for (ll digits = 1; digits <= high_digits / 2; ++digits) {
        if (low_digits == high_digits && low_digits % digits != 0)
            continue;

        for (ll base = pow(10, digits - 1); num_of_digits(base) == digits; ++base) {
            ll current = base;
            while (low_digits > num_of_digits(current))
                current = current * pow(10, digits) + base;
            
            while (current <= high) {
                if (
                    current >= low &&
                    num_of_digits(current) >= 2 * digits &&
                    already_used.insert(current).second
                ) {
                    ret += current;
                }
                current = current * pow(10, digits) + base;
            }
        }
    }
    return ret;
}

int main() {
    ll low, high;
    char tmp;
    ll result = 0;
    while (cin >> low) {
        cin >> tmp >> high >> tmp;
        result += invalid_id_sum_in_range(low, high);
    }
    cout << result << endl;
    return 0;
}
