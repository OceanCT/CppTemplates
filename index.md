# 树状数组

```cpp
#include<bits/stdc++.h>
using namespace std;
#define FIN freopen("in","r",stdin)
#define N 1000005
int c[N],n;
inline int lowbit(int k){return -k&k;};
inline void add(int x,int y){
    for(int i=x;i<=n;i+=lowbit(i)) c[i]+=y;
}
inline int sum(int x){
    if(!x) return 0;
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i))ans+=c[i];
    return ans;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){int tmp;cin>>tmp;add(i,tmp);}

    return 0;
}
```



# 逆元

```cpp
#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define N 1000005
int inv[N],n;
inline int add(int x,int y){return ((long long)x+y)%mod;};
inline int mul(int x,int y){return (long long)x*y%mod;}
inline int quickpow(int x,int y){
    long long ans = 1;
    while(y){
        if(y&1) ans = ans*x%mod;
        x = (long long)x*x%mod;
        y/=2;
    }
    return (int)ans;
}  
int main(){
    cin>>n;
    // 线性求逆元
    inv[1] = 1;
    for(int i=2;i<=n;i++) inv[i] = mul(mod-mod/i,inv[mod%i]);
    // 小费马定理
    for(int i=1;i<=n;i++) inv[i] = quickpow(i,mod-2);
    return 0;
}
```



# 马拉车

```cpp
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

```



# 单调栈

```cpp
#include<bits/stdc++.h>
using namespace std;
class monotype {
public:
    int con;
    bool mono(monotype other) {
        return other.con <= con ? true : false;
    }
};
template <typename MONOTYPE>
class monostack {
private:
    stack<MONOTYPE> sk;
public:
    void __preparePush(MONOTYPE k) {
        while (!sk.empty() && !sk.top().mono(k))sk.pop();
    }
    void push(MONOTYPE k) {
        __preparePush(k);
        sk.push(k);
    }
    bool empty() { return sk.empty(); }
    int size() { return sk.size(); }
    void pop() { sk.pop(); }
    MONOTYPE top() { return sk.top(); }
};

int main() {
    return 0;
}
```



# 快读快写

```cpp
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -1;ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48;ch = getchar(); }
    return x * f;
}
void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}
int main(){



    return 0;
}
```



# st表

```cpp
#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define FIN freopen("in","r",stdin);
#define IOS ios::sync_with_stdio(false);
int st[N][21], n, tmplog[N], tmp2[21];
// st_table
inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -1;ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48;ch = getchar(); }
    return x * f;
}
int st_oper(int a, int b) {
    return max(a, b);
}
void st_build() {
    tmp2[0] = 1;
    for (int i = 1; i <= 20; i++) {
        tmp2[i] = tmp2[i - 1] * 2;
        for (int j = tmp2[i - 1];j < min(tmp2[i], N);j++) {
            tmplog[j] = i - 1;
        }
    }
    for (int ilen = 1;ilen <= 19;ilen++) {
        int len = tmp2[ilen];
        for (int i = 1;i <= n - len + 1;i++) {
            st[i][ilen] = st_oper(st[i][ilen - 1], st[i + len / 2][ilen - 1]);
        }
    }
}
int st_query(int i, int j) {
    int len = j - i + 1;
    int ilen = tmplog[len];
    int len1 = tmp2[ilen];
    return st_oper(st[i][ilen], st[j - len1 + 1][ilen]);
}
// st_table_end
int main() {
    // FIN
    n = read();
    for (int i = 1; i <= n; i++)
        st[i][0] = read();
    st_build();
    return 0;
}
```



# 基本板

```cpp
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

```



# 字典树

```cpp
#include<bits/stdc++.h>
using namespace std;
#define N1 62
#define N 3000005
typedef struct Tire {
    int tr[N][N1], cnt[3000005], idx;
    int toi(char x) {
        if (x >= 'A' && x <= 'Z')return x - 'A';
        else if (x >= 'a' && x <= 'z')return x - 'a' + 26;
        else return x - '0' + 52;
    }
    void insert(string str) {
        int p = 0, len = str.length();
        for (int i = 0;i < len;i++) {
            int c = toi(str[i]);
            if (!tr[p][c])tr[p][c] = ++idx;
            p = tr[p][c];
            cnt[p]++;
        }
    }
    int find(string str) {
        int p = 0, len = str.length();
        for (int i = 0;i < len;i++) {
            int c = toi(str[i]);
            if (!tr[p][c])return 0;
            p = tr[p][c];
        }
        return cnt[p];
    }
    void init() {
        for (int i = 0;i <= idx;i++) {
            for (int j = 0;j < N1;j++) tr[i][j] = 0;
            cnt[i] = 0;
        }
        idx = 0;
    }
}tire;
int main(){



    return 0;
}
```



