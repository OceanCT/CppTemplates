#include<bits/stdc++.h>
using namespace std;
#define lowbit(x)  (-x&x)
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 int128;
inline int128 read() {int128 x;char ch(getchar());bool f(false);while (!isdigit(ch))f |= ch == 45, ch = getchar();x = ch & 15, ch = getchar();while (isdigit(ch))x = x * 10 + (ch & 15), ch = getchar();if (f)x = -x;return x;}
template<typename tp> inline void read(tp& x) {char ch(getchar());bool f(false);while (!isdigit(ch))f |= ch == 45, ch = getchar();x = ch & 15, ch = getchar();while (isdigit(ch))x = x * 10 + (ch & 15), ch = getchar();if (f)x = -x;}
template<typename tp, typename... args> inline void read(tp& x,args&...y){read(x);read(y...);}
template<typename tp> inline void write(tp x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');return;}
template<typename tp, typename... args> inline void write(tp x,args... y){write(x),putchar(' '),write(y...);}
template<typename tp> inline tp chmax(tp a, tp b) { return a > b ? a : b; };
template<typename tp, typename... args> inline tp chmax(tp a, args... b) { return chmax(a, chmax(b...)); }
template<typename tp> inline tp chmin(tp a, tp b) { return a < b ? a : b; }
template<typename tp, typename... args> inline tp chmin(tp a, args... b) { return chmin(a, chmin(b...)); }

int main() {
    



    
    return 0;
}