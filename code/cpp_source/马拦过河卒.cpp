#include<iostream>
#include<vector>
using namespace std;
int F[21][21];
int method(int a,int b,int c,int d){
    
    if((a==c-1 & b==d-2)||(a==c-2 & b==d-1)|| (a==c+2 & b==d+1) ||(a==c+1 & b==d+2))return 0;
    if((a==c-1&b==d+2)||(a==c-2 & b==d+1)||(a==c+2&b==d-1)||(a==c+1&b==d-2)||(a==c&b==d))return 0;

    if((c == 2&&d!=b)&&(b>=d+1&&a ==0))return 0;
    if((c == 2&&d==b)&&(b>=d-1&&a ==0))return 0;
    if((d == 0)&&(b == 0 && a >= c))return 0;
    if((c == 0)&&(a == 0 && b >= d))return 0;
    if((c == 1&&d!=b)&&(b>=d+2&&a ==0))return 0;
    if((c == 1&&d==b)&&(b>=d-2&&a ==0))return 0;  
    if((d == 1&&c!=a)&&(a>=c+2&&b ==0))return 0;
    if((d == 1&&c==a)&&(a>=c-2&&b ==0))return 0;
    if((d == 2&&c!=a)&&(a>=c+1&&b ==0))return 0;
    if((d == 2&&c==a)&&(a>=c-1&&b ==0))return 0;
    
    if(F[a][b]!=0)return F[a][b];
    F[a][b] = method(a-1,b,c,d)+method(a,b-1,c,d); 
    return F[a][b];
}
int main(){
    int m,n,x,y;
    cin>>m>>n>>x>>y;
    if(x ==m&&y == n){
        cout<<0;
        return 0;
    }
    if(x ==0&&y == 0)
    {   cout<<0;
        return 0;
    }
    for(int i = 0;i<=m;i++)
    {  
            F[i][0] = 1;
    }

    for(int i = 0;i<=n;i++){
 
            F[0][i] = 1;
    }
    for(int i = 0;i<m;i++){
        for(int j =0;j<n;j++)
        cout<<F[i][j]<<" ";
        cout<<endl;
    }

    cout<<method(m,n,x,y);
    //马控制八个点 加自己 (x,y)
    //(x-1,y-2) (x-2,y-1) (x+2,y+1) (x+1,y+2) 
    //(x-1,y+2) (x-2,y+1) (x+2,y-1) (x+1,y-2)

    return 0;
}

