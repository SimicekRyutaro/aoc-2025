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

void count_splits_rec(ll y, ll x, const vector<string> & map, set<pair<ll, ll>> & splitters_used) {
    if (y == map.size() - 1)
        return;

    if (map[y][x] != '^') {
        count_splits_rec(y + 1, x, map, splitters_used);
    } else {
        if (splitters_used.insert({y, x}).second) {
            count_splits_rec(y, x + 1, map, splitters_used);
            count_splits_rec(y, x - 1, map, splitters_used);
        }
    }
}

ll count_splits(ll y, ll x, const vector<string> & map) {
    set<pair<ll, ll>> splitters_used;
    count_splits_rec(y, x, map, splitters_used);
    return splitters_used.size();
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
    ll result = count_splits(start_row, start_col, map);
    cout << result << endl;
    return 0;
}
