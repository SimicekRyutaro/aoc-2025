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
        ll result = 0;
        for (ll battery = 0; battery < 12; ++battery) {
            for (ll i = max_index + 1; i < str.length() - 11 + battery; ++i) {
                if (str[i] - '0' > max) {
                    max = str[i] - '0';
                    max_index = i;
                }
                if (max == 9)
                    break;
            }
            result = 10 * result + max;
            max = -1;
        }
        final_result += result;
    }
    cout << final_result << endl;
    return 0;
}
