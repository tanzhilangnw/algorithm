//#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main() {
    long long n, V, maxV = 0;
    cin >> V;
    cin >> n;
    vector<long long> v(n+1);
    vector<vector<long long>> dp((n + 1), vector<long long>(V + 1,0));
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    /*sort(v.begin(), v.end());
    reverse(v.begin(),v.end());*/
    //for (int i = 0; i < n; i++)
    //{
    //    maxV += v[i];
    //    if (maxV > V) {
    //        maxV -= v[i];
    //        continue;
    //    }
    //}
    for (long long j = V; j >= v[1]; j--) {
        dp[1][j] = v[1];
    }

    for (int i = 2; i <= n; i++)
        for (long long j = V; j >= 0; j--){
            if (j < v[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i]);
    }
    cout << V - dp[n][V];
    return 0;
}