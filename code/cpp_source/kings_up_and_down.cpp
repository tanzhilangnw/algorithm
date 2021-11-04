#include<iostream>
#include<cstring>
using namespace std;
long long dp[21][22][2]; 
bool visit[21];
long long ans = 0;
int l;
//c = 1 up c = 0 down c 下一个状态
long long dfs (int a,int b,int c){
    if(a == 0) return 1;
    if(dp[a][b][c] != -1){//不是初值说明算出来了
        return dp[a][b][c];
    }

    long long ans = 0;
    for(int i = 1 ;i<= l;i++){
        if((c && i > b && !visit[i] )||(!c && i < b && !visit[i]))//当前数比前数大 且状态是上升/当前数比前数小 且状态是下降
        {   visit[i] = true;
            ans += dfs(a-1,i,!c);
            visit[i] = false;
        }
    }
    return dp[a][b][c] = ans;//返回 dp[a][b][c]
}

int main(){
    int n,m;
    cin >>n;
    while(n--){
        memset(dp,-1,sizeof(dp));
        cin>>m>>l;
        if(l ==1) {cout<<m<<' '<<1<<endl;continue;}
        memset(visit,false,sizeof(visit));      
        cout<<m<<' '<<dfs(l,-1,1)+dfs(l,21,0)<<endl;
    }
    return 0;
}