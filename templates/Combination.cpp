#include <bits/stdc++.h>
using namespace std;
#define N 3005
#define mod 1000000007
vector<vector<int>> combiantion;
void init()
{
    combiantion.resize(N);
    for (int i = 1; i < N; i++)
    {
        combiantion[i].resize(i + 1);
        combiantion[i][0] = combiantion[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            combiantion[i][j] = (combiantion[i - 1][j] + combiantion[i - 1][j - 1]) % mod;
        }
    }
}
int main()
{
    // C(i,j) = C(i-1,j-1)+C(i-1,j-1);

    return 0;
}