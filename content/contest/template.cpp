#include <bits/stdc++.h>
using namespace std;

template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U> &pr) {
    out << "(" << pr.first << "; " << pr.second << ")";
    return out;
}
template<class T>
ostream& operator<<(ostream& out, const vector<T> &cont) {
    out << "[";
    for (const auto &x : cont) out << x << ", ";
    out << "]";
    return out;
}
#define dmp(x) cerr << #x << " = " << x << endl
#define dmpn(x) cerr << #x << " = " << x << "; "

// kactl only
// #define rep(i, a, b) for(int i = a; i < (b); ++i)
// typedef vector<int> vi;
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

void solve() {
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
