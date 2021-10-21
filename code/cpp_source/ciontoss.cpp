#include<iostream>
#include<cmath>
using namespace std;
int main(){
    
    long long n,k,i,j;
    while(scanf("%d%d",&n,&k)!=EOF){
        //cin>>n;
        //cout<<n;
        //cin>>k;
        //cout<<k;
        int dp[101][2];
        dp[0][0] = 1;
        dp[0][1] = 0;
        for(int i = 1;i<=n;i++)
        {   //第i次结果是正面，至多有k次正面
            dp[i][1] = dp[i-1][0]+dp[i-1][1]; 
            //第i次结果是反面，至多有k次正面
            dp[i][0] = dp[i-1][0]+dp[i-1][1];
            if(i == k)
                dp[i][0] -= 1; 
            if(i> k)
                dp[i][0] -= dp[i-k][1];
        }
        cout<< pow(2,n)-(dp[n][1]+dp[n][0])<<endl;
    }
    
    return 0;
}