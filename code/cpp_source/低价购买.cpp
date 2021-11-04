#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
long long max(long long x,long long y){return x>y?x:y;}

//a[i]存的是第i天股票的价格
//f[i]存的是第i天最长下降子序列的长度
//t[i]存的是以i结尾的最长下降子序列的种类（方案）
int main()
{   int n,maxx=0,p;
    cin>>n;
    vector<long long>f(n+1,0);//初始化长度
    vector<long long>t(n+1,0);//初始化方案
    vector<long long> a(n+1,0);//初始化价格
    for(int i=1;i<=n;i++)
    {   cin>>p;
        a[i] = p;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
            if(a[i]<a[j])//延长已经存在的最长下降子序列
                f[i]=max(f[i],f[j]+1);
        if(f[i]==0)
            f[i]++;//如果当前的数是目前为止最大的，则最长下降子序列是自己
        
        maxx=max(f[i],maxx);//在f数组更新完毕后，存下最长下降子序列的长度
        for(int j=1;j<i;j++)
            if(f[i]==f[j]&&a[i]==a[j])
                t[j]=0;//如果与前面的数列相同，则舍去前面的数列，防止重复计数
            else if(f[i]==f[j]+1&&a[i]<a[j])
                t[i]+=t[j];//如果可以接上前面的数列，则继承其方案数
        if(!t[i])//如果当前的数是目前为止最大的，则是初始方案
            t[i]=1;
    }

    long long sum=0;//sum计数，用于存最长下降子序列（方案）的个数
    for(int i=1;i<=n;i++)
        if(f[i]==maxx)
            sum+=t[i];
    cout<<maxx<<" "<<sum;
    return 0;
}