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
    if (low_digits == high_digits && low_digits % 2 == 1)
        return 0;

    ll first_half;
    if (low_digits % 2 == 0)
        first_half = low / power(10, low_digits / 2);
    else
        first_half = power(10, low_digits / 2);

    // 1 ... 9 ... 11 ... 0
    // 3 ... 999 ... 1 010 ... 1
    // 5 ... 99 999 ... 100 100 ... 2
    // 7 ... 9 999 999 ... 10 001 000 ... 3

    ll current = first_half * pow(10, num_of_digits(first_half)) + first_half;
    ll ret = 0;
    while (current <= high) {
        if (current >= low)
            ret += current;
        ++first_half;
        current = first_half * pow(10, num_of_digits(first_half)) + first_half;
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
