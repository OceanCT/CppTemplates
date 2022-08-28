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