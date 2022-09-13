#include <bits/stdc++.h>
using namespace std;
#define FIN freopen("in", "r", stdin)
#define N 1000005
int c[N], n;
inline int lowbit(int k) { return -k & k; };
inline void add(int x, int y)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += y;
}
inline int sum(int x)
{
    if (!x)
        return 0;
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        add(i, tmp);
    }

    return 0;
}