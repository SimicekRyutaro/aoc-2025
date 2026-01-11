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
    ll dial = 50;
    ll password = 0;
    char direction;
    ll distance;
    while (cin >> direction) {
        cin >> distance;
        if (direction == 'L') {
            bool started_on_zero = dial == 0;
            dial -= distance;
            if (dial <= 0) {
                password += 1 + -dial / 100;  // 0, -100, -200
                if (started_on_zero)
                    --password;
                dial = ((dial % 100) + 100) % 100;
            }
        } else {
            dial += distance;
            if (dial > 99) {
                password += dial / 100;  // 100, 200, 300
                dial %= 100;
            }
        }
    }
    cout << password << endl;
    return 0;
}
