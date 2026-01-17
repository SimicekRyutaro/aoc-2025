#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

template <typename T>
std::ostream & operator<< (std::ostream & os, const std::vector<T> & v) {
    os << "[ ";
    for (const T & elem : v)
        os << elem << " ";
    os << "]";
    return os;
}

ld euclidean_dist(const tuple<ld, ld, ld> & a, const tuple<ld, ld, ld> & b) {
    auto [a1, a2, a3] = a;
    auto [b1, b2, b3] = b;
    return sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2) + (a3 - b3) * (a3 - b3));
}

class UnionFind {
   public:
    UnionFind(ll n) : _parents(n, -1), _depths(n, 1), _counts(n, 1) {}
    ll find(ll x) const {
        while (_parents[x] != -1)
            x = _parents[x];
        return x;
    }
    void unite(ll x, ll y) {
        ll a = find(x);
        ll b = find(y);
        if (a == b)
            return;
        if (_depths[a] > _depths[b]) {
            _parents[b] = a;
            _counts[a] += _counts[b];
            _counts[b] = 0;
        } else if (_depths[b] > _depths[a]) {
            _parents[a] = b;
            _counts[b] += _counts[a];
            _counts[a] = 0;
        } else {
            _parents[b] = a;
            ++_depths[a];
            _counts[a] += _counts[b];
            _counts[b] = 0;
        }
    }
    const vector<ll> & get_counts() const {
        return _counts;
    }
   private:
    vector<ll> _parents;
    vector<ll> _depths;
    vector<ll> _counts;
};

int main() {
    vector<tuple<ld, ld, ld>> points;
    string line;
    while (getline(cin, line)) {
        ld x, y, z;
        char tmp;
        istringstream iss(line);
        iss >> x >> tmp >> y >> tmp >> z;
        points.push_back({x, y, z}); 
    }
    ll n = points.size();
    set<tuple<ld, ll, ll>> distances;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            distances.insert({euclidean_dist(points[i], points[j]), i, j});
        }
    }

    UnionFind uf(n);
    ll result;
    for (auto it = distances.begin(); it != distances.end(); ++it) {
        ll i = get<1>(*it);
        ll j = get<2>(*it);

        ll i_set = uf.find(i);
        ll j_set = uf.find(j);

        if (i_set != j_set) {
            uf.unite(i_set, j_set);
            result = get<0>(points[i]) * get<0>(points[j]);
            ll i_cnt = uf.get_counts()[i];
            ll j_cnt = uf.get_counts()[j];

            if (i_cnt == n || j_cnt == n)
                break;
        }
    }
    cout << result << endl;
    return 0;
}
