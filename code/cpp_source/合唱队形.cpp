#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,hight = 0,alen = 0,blen = 0,K = 0;
    cin >>n;
    vector<int> h,h1,a(n),b(n);
    vector<vector<int>>count(n,vector<int>(2));
    for(int i = 1;i <= n;i++){
        cin>>hight;
        h.push_back(hight);
    }
    a[0] = h[0];
    b[0] = h[n-1];  
    count[0][0] = 1;
    count[n-1][1] = 1;
    for(int i = 1;i<n;i++){
        if(h[i]>a[alen]) {
            alen++;
            a[alen] = h[i];
            count[i][0] = alen + 1;
        }
        else{
            int pos = upper_bound(a.begin(),a.begin()+alen+1,h[i])-a.begin();
            if(a[pos-1] == h[i]){
                count[i][0] = pos ;
            }
            else{
                a[pos] = h[i];
                count[i][0] = pos + 1;
            }
        }
    }

    for(int i = n-2;i>=0;i--){
        if(h[i]>b[blen]) {
            blen++;
            b[blen] = h[i];
            //count[n-1-i][1]=blen;
            count[i][1] = blen+1;
        }
        else{
            int pos = upper_bound(b.begin(),b.begin()+blen+1,h[i])-b.begin();
            if(b[pos-1] == h[i]){
                count[i][1] = pos;
            }
            else{
                b[pos] = h[i];
                //count[n-1-i][1]=blen;
                count[i][1] = pos + 1;
            }                                                                                                                                
        }  
    }

    for(int i = 0; i<a.size();i++){
            K = max(count[i][0]+count[i][1]-1,K);       
    }
 
    cout<<n-K;

}