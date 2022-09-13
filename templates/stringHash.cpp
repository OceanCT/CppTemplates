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

// mod 1e9+9,1e9+7
typedef struct StringHash {
    string s;ll mod, slen;vector<ll> heo, ans;
    StringHash() {}
    StringHash(string s1, ll mod1) { init(s1, mod1); }
    void init(string s1, ll mod1) {
        s = s1, mod = mod1, slen = s.length();
        heo.resize(slen), ans.resize(slen);
        heo[0] = 1;for (int i = 1;i < slen;i++) heo[i] = heo[i - 1] * 26 % mod;
        ll now = 0;
        auto fn = [](char ch) {return ch - 'a';};
        for (int i = 0;i < slen;i++) {
            now = (now + heo[slen - i - 1] * fn(s[i]) % mod) % mod;
            ans[i] = now;
        }
    }
    ll getHash(int l, int r) {
        if (l == 0) return ans[r];
        else return (ans[r] - ans[l - 1] + mod) % mod * heo[l] % mod;
    }
}StringHash;


#define N 100010
int main() {
    FIN;
    IOS;
    string s;cin >> s;
    int slen = s.length();
    StringHash s1, s2;
    s1.init(s, 100009);
    s2.init(s, 100007);
    auto check = [&s1, &s2](int pos, int len)->bool {
        return s1.getHash(pos, pos + len - 1) == s1.getHash(0, len - 1) && s2.getHash(pos, pos + len - 1) == s2.getHash(0, len - 1);
    };
    // cout<<s1.getHash(0,1);
    int q;cin >> q;
    while (q--) {
        int st;cin >> st;st--;
        if (check(st, 1)) {
            int l = 1, r = slen - st;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (check(st, mid)) { l = mid; } else r = mid - 1;
            }
            cout << l << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
    return 0;
}
