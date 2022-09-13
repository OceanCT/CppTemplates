#include <bits/stdc++.h>
using namespace std;
#define N1 26
#define N 1000005
typedef struct ACA
{
    int tr[N][N1], cnt[3000005], idx, fail[N];
    int toi(char x)
    {
        if (x >= 'A' && x <= 'Z')
            return x - 'A';
        else if (x >= 'a' && x <= 'z')
            return x - 'a' + 26;
        else
            return x - '0' + 52;
    }
    void insert(string str)
    {
        int p = 0, len = str.length();
        for (int i = 0; i < len; i++)
        {
            int c = toi(str[i]);
            if (!tr[p][c])
                tr[p][c] = ++idx;
            p = tr[p][c];
            cnt[p]++;
        }
    }
    int find(string str)
    {
        int p = 0, len = str.length();
        for (int i = 0; i < len; i++)
        {
            int c = toi(str[i]);
            if (!tr[p][c])
                return 0;
            p = tr[p][c];
        }
        return cnt[p];
    }
    void init()
    {
        for (int i = 0; i <= idx; i++)
        {
            for (int j = 0; j < N1; j++)
                tr[i][j] = 0;
            cnt[i] = 0;
        }
        idx = 0;
    }
    void build()
    {
        queue<int> q;
        for (int i = 0; i < N1; i++)
        {
            if (tr[0][i])
                q.push(tr[0][i]);
        }
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
            {
                if (tr[now][i])
                {
                    fail[tr[now][i]] = tr[fail[now]][i];
                    q.push(tr[now][i]);
                }
                else
                    tr[now][i] = tr[fail[now]][i];
            }
        }
    }
    int find(string s)
    {
        int len = s.length(), now = 0, ans = 0;
        for (int i = 0; i < len; i++)
        {
            now = tr[now][toi(s[i])];
            for (int t = now; t && cnt[now] != -1; t = fail[t])
            {
                ans += cnt[t];
                cnt[t] = -1;
            }
        }
        return ans;
    }
} aca;
int main()
{

    return 0;
}