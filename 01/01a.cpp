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
        if (direction == 'L')
            dial = (((dial - distance) % 100) + 100) % 100;
        else
            dial = (dial + distance) % 100;
        if (dial == 0)
            ++password;
    }
    cout << password << endl;
    return 0;
}
