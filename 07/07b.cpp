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

ll count_timelines_rec(ll y, ll x, const vector<string> & map, std::map<pair<ll, ll>, ll> & memo) {
    if (y == map.size() - 1)
        return 1;
    if (memo.find({y, x}) != memo.end())
        return memo[{y, x}];

    if (map[y][x] != '^') {
        memo[{y, x}] = count_timelines_rec(y + 1, x, map, memo);
        return memo[{y, x}];
    } else {
        memo[{y, x}] = count_timelines_rec(y, x + 1, map, memo) + count_timelines_rec(y, x - 1, map, memo);
        return memo[{y, x}];
    }
}

ll count_timelines(ll y, ll x, const vector<string> & map) {
    std::map<pair<ll, ll>, ll> memo;
    return count_timelines_rec(y, x, map, memo);
}

int main() {
    vector<string> map;
    string line;
    while (getline(cin, line))
        map.push_back(line);
    ll start_row = -1, start_col = -1;
    for (ll r = 0; r < map.size(); ++r) {
        for (ll c = 0; c < map[0].size(); ++c) {
            if (map[r][c] == 'S') {
                start_row = r;
                start_col = c;
                break;
            }
        }
        if (start_row != -1)
            break;
    }
    ll result = count_timelines(start_row, start_col, map);
    cout << result << endl;
    return 0;
}
