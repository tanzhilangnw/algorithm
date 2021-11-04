#include<vector>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main() {
    long long n, M,V, maxV = 0;//M是质量,V是体积,n是物品个数
    cin >> M;
    cin >> V;
    cin >> n;
    vector<long long> v(n + 1);//体积数组
    vector<long long> m(n + 1);//质量数组
    vector<long long> c(n + 1);//热量数组
    vector<vector<vector<long long>>> dp((n + 1), vector<vector<long long>>(M + 1, vector<long long>(V+1,0)));
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        cin >> m[i];
        cin >> c[i];
    }

    for (long long j = M; j >= m[1]; j--) {
        for(long long k = V;k>v[1];k--)
        dp[1][j][k] = c[1];
    }

    for (int i = 2; i <= n; i++)
        for (long long j = M; j >= 0; j--) {
            for(long long k = V;k >= 0;k--)

            if (j < m[i]||k<v[i]) dp[i][j][k] = dp[i - 1][j][k];
            else dp[i][j] = max(dp[i - 1][j][k], dp[i - 1][j - m[i]][k-v[i]] + c[i]);
        }
    cout << dp[n][M][V];
    return 0;
}
