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
    vector<ll> starts, ends;
    string str;
    while (getline(cin, str)) {
        if (str == "")
            break;
        istringstream iss(str);
        ll start, end;
        char tmp;
        iss >> start >> tmp >> end;
        starts.push_back(start);
        ends.push_back(end);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    ll result = 0;
    ll x;
    while (cin >> x) {
        auto it = lower_bound(starts.begin(), starts.end(), x);
        if (it == starts.begin() && x < *it)
            continue;
        if (it == starts.end() || x < *it)
            --it;
        ll index = it - starts.begin();
        if (x <= ends[index])
            ++result;
    }
    cout << result << endl;
    return 0;
}
