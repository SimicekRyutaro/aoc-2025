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
    vector<vector<ll>> nums;
    vector<char> operations;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        if (line[0] == '+' || line[0] == '*') {
            char c;
            while (iss >> c)
                operations.push_back(c);
            break;
        }
        nums.push_back({});
        ll x;
        while (iss >> x)
            nums.back().push_back(x);
    }
    ll result = 0;
    for (ll col = 0; col < nums[0].size(); ++col) {
        ll tmp = (operations[col] == '+') ? 0 : 1;
        for (ll row = 0; row < nums.size(); ++row) {
            if (operations[col] == '+')
                tmp += nums[row][col];
            else
                tmp *= nums[row][col];
        }
        result += tmp;
    }
    cout << result << endl;
    return 0;
}
