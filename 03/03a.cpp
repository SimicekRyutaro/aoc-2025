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

int main() {
    ll final_result = 0;
    string str;
    while (getline(cin, str)) {
        ll max_index = -1, max = -1;
        for (ll i = 0; i < str.length() - 1; ++i) {
            if (str[i] - '0' > max) {
                max = str[i] - '0';
                max_index = i;
            }
            if (max == 9)
                break;
        }
        ll result = 10 * max;
        max = -1;
        for (ll i = max_index + 1; i < str.length(); ++i) {
            if (str[i] - '0' > max)
                max = str[i] - '0';
            if (max == 9)
                break;
        }
        result += max;
        final_result += result;
    }
    cout << final_result << endl;
    return 0;
}
