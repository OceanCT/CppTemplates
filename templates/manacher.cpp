#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((-x)&(x))
#define square(x) ((x)*(x)) 
#define endl '\n'
#define pline putchar('\n')
#define pspace putchar(' ')
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
typedef long long ll;typedef unsigned long long ull;typedef __int128 int128;
inline int128 read() { int128 x;char ch(getchar());bool f(false);while (!isdigit(ch))f |= ch == 45, ch = getchar();x = ch & 15, ch = getchar();while (isdigit(ch))x = x * 10 + (ch & 15), ch = getchar();if (f)x = -x;return x; }
template<typename tp> inline void read(tp& x) { char ch(getchar());bool f(false);while (!isdigit(ch))f |= ch == 45, ch = getchar();x = ch & 15, ch = getchar();while (isdigit(ch))x = x * 10 + (ch & 15), ch = getchar();if (f)x = -x; }
template<typename tp, typename... args> inline void read(tp& x, args&...y) { read(x);read(y...); }
template<typename tp> inline void write(tp x) { if (x < 0)putchar('-'), x = -x;if (x > 9)write(x / 10);putchar(x % 10 + '0');return; }
template<typename tp, typename... args> inline void write(tp x, args... y) { write(x), putchar(' '), write(y...); }
template<typename tp> inline tp chmax(tp a, tp b) { return a > b ? a : b; };
template<typename tp, typename... args> inline tp chmax(tp a, args... b) { return chmax(a, chmax(b...)); }
template<typename tp> inline tp chmin(tp a, tp b) { return a < b ? a : b; }
template<typename tp, typename... args> inline tp chmin(tp a, args... b) { return chmin(a, chmin(b...)); }





template<typename tp>tuple<vector<int>, vector<int>> manacher(vector<tp> ts,int n) {
    vector<int> d1(ts.size()), d2(ts.size());
    for (int i = 0, l = 0, r = -1;i < n;i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && ts[i - k] == ts[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }for (int i = 0, l = 0, r = -1;i < n;i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && ts[i - k - 1] == ts[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    return { d1,d2 };
}

int main() {
    IOS;
    string s;
    cin >> s;
    auto [ans1, ans2] = manacher(vector<char>(s.begin(), s.end()),s.length());
    int ans = 0;
    for (auto k : ans1)ans = chmax(ans, k * 2 - 1);
    for (auto k : ans2)ans = chmax(ans, k * 2);
    cout<<ans<<endl;
    return 0;
}
