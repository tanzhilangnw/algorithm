#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1000*30*100+5;//30张1000元的发票(扩大100倍)
int max_val;  //可报销总额
int dp[maxn];
int cnt;      //合法发票数
int val[maxn];//每张合法发票的额度
int main()
{
    string v;
    int a = 0;
    int n;
    while(scanf("%s%d",&v,&n)==2 && n)
    {   int pos = v.find('.');
        v.erase(pos,pos);
        a = atoi(v.c_str());
        cout<<a<<endl;
        cnt=0;
        max_val= a ;
        for(int i=1;i<=n;i++)
        {
            int num;
            char type;//商品类型
            int va=0,vb=0,vc=0;
            scanf("%d",&num);
            bool flag=true;//合法发票
            while(num--)
            {
                scanf(" %c:%s",&type,&v);
                pos = v.find('.');
                v.erase(pos,pos);
                a = atoi(v.c_str());
                //cout<<v<<endl;
                if(type=='A') va+=a;
                else if(type=='B') vb+=a;
                else if(type=='C') vc+=a;
                else flag=false;//含有其他种类商品
            }
            if(flag && va<=600 && vb<=600 && vc<=600 && va+vb+vc<=1000)
                val[++cnt]=va+vb+vc;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=cnt;i++)
            for(int j=max_val;j>=val[i];j--)
                dp[j] = max(dp[j],dp[j-val[i]]+val[i]);  //经过优化的一维数组类型的背包方程
        cout<<dp[max_val]/100;
        //printf("%.2lf\n",(dp[max_val])/100.0 );
    }
    return 0;
}