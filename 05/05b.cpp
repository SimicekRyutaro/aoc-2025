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
    for (ll i = 0; i < starts.size() - 1; ++i) {
        ll current_start = starts[i];
        ll next_start = starts[i + 1];
        ll current_end = ends[i];
        if (current_end < next_start)
            result += current_end - current_start + 1;
        else
            result += next_start - current_start;
    }
    result += ends.back() - starts.back() + 1;
    cout << result << endl;
    return 0;
}
