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
    vector<string> nums;
    string operations;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        if (line[0] == '+' || line[0] == '*') {
            operations = line;
            break;
        }
        nums.push_back(line);
    }
    ll result = 0;
    ll tmp;
    bool adding;

    for (ll col = 0; col < operations.size() + 1; ++col) {
        if (col == operations.size()) {
            result += tmp;
            break;
        }
        if (col + 1 < operations.size() && operations[col + 1] != ' ') {
            result += tmp;
            continue;
        }

        if (operations[col] == '+') {
            adding = true;
            tmp = 0;
        } else if (operations[col] == '*') {
            adding = false;
            tmp = 1;
        }

        ll current_num = 0;
        for (ll row = 0; row < nums.size(); ++row) {
            if (nums[row][col] != ' ')
                current_num = 10 * current_num + nums[row][col] - '0';
        }

        if (adding)
            tmp += current_num;
        else
            tmp *= current_num;
    }
    cout << result << endl;
    return 0;
}
