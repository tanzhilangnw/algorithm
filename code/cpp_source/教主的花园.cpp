#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,v;
    long long sum =0;
    cin>>n;
    vector<vector<long long>> a(n+1,vector<long long>(4,0));
    vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(4,vector<long long>(2,0)));//0表示比相邻低 1表示比相邻高
    for(int i =1;i<=n;i++)
    {   cin>>v;
        a[i][1] = v;
        cin>>v;
        a[i][2] = v;
        cin>>v;
        a[i][3] = v;
    }
    for(int j = 1;j<4;j++){
        for(int i=1;i<4;i++){
            for(int k =1;k<3;k++){
                dp[1][i][k] = 0;
            }
        }
        dp[0][j][1] = dp[0][j][0] = a[n][j];
        for(int i=1;i<=n-1;i++){
            //第一棵树高度是1 比相邻树低
            dp[i][1][0] = max(dp[i-1][3][1],dp[i-1][2][1])+a[i][1];
            //第一棵树高度是2 比相邻树低
            dp[i][2][0] = dp[i-1][3][1]+a[i][2];
            //第一棵树高度是2 比相邻树高
            dp[i][2][1] = dp[i-1][1][0]+a[i][2];
            //第一棵树高度是3 比相邻树高
            dp[i][3][1] = max(dp[i-1][2][0],dp[i-1][1][0])+a[i][3];
            //cout<< dp[i][1][0] <<" "<<dp[i][2][0]<<" "<<dp[i][2][1] <<" "<< dp[i][3][1]<<endl;
        }
        for(int i =3;i>j;i-- )
        sum = max(sum,dp[n-1][i][1]);
        
        for(int i = 1;i<j;i++)
        sum = max(sum,dp[n-1][i][0]);
        //dp[n][1][0]=max(dp[n-1][2][1],dp[n-1][3][1])+a[n][1];
        //dp[n][2][0]=dp[n-1][3][1]+a[n][2];
        //dp[n][2][1]=dp[n-1][1][0]+a[n][2];
        //dp[n][3][1]=max(dp[n-1][1][0],dp[n-1][2][0])+a[n][3];
    }
    //cout<< dp[n][1][0] <<" "<<dp[n][2][0]<<" "<<dp[n][2][1] <<" "<< dp[n][3][1]<<endl;
    //cout<<max(max(max(dp[n][3][1],dp[n][2][1]),dp[n][2][0]),dp[n][1][0]);
    cout<<sum;
    return 0;
}