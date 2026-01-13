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

ll rolls_around(ll r, ll c, const vector<string> & map) {
    vector<ll> offsets = {-1, 0, 1};
    ll ret = 0;
    for (ll yoffset : offsets) {
        for (ll xoffset : offsets) {
            ll y = r + yoffset;
            ll x = c + xoffset;
            if (y == r && x == c)
                continue;
            if (y >= 0 && y < map.size() && x >= 0 && x < map[y].size() && map[y][x] == '@')
                ++ret;
        }
    }
    return ret;
}

int main() {
    vector<string> map;
    string tmp;
    while (getline(cin, tmp))
        map.push_back(tmp);
    ll result = 0;
    bool next_iter = true;
    while (next_iter) {
        next_iter = false;
        ll tmp_result = 0;
        vector<pair<ll, ll>> to_remove;
        for (ll r = 0; r < map.size(); ++r) {
            for (ll c = 0; c < map[r].size(); ++c) {
                ll around = 99999;
                if (map[r][c] == '@')
                    around = rolls_around(r, c, map);
                if (around < 4) {
                    ++tmp_result;
                    to_remove.push_back({r, c});
                }
            }
        }
        for (const pair<ll, ll> & coords : to_remove)
            map[coords.first][coords.second] = '.';
        result += tmp_result;
        next_iter = tmp_result ? true : false;
    }

    cout << result << endl;
    return 0;
}
