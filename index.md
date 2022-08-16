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
int st[N][21], n, tmplog[N], tmp2[N];
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



