#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 1000 * 30 * 100 + 5;//30��1000Ԫ�ķ�Ʊ(����100��)
int max_val;  //�ɱ����ܶ�
int dp[maxn];
int cnt;      //�Ϸ���Ʊ��
int val[maxn];//ÿ�źϷ���Ʊ�Ķ��
int main()
{
    string v;
    int a = 0;
    int n;
    scanf("%s%d",&v,&n);
    //cin >> v >> n;
    while (n)
    {
        int pos = v.find('.');
        v.erase(v.begin()+pos);
        a = std::stoi(v);
        cnt = 0;
        max_val = a;
        for (int i = 1; i <= n; i++)
        {
            int num;
            char type;//��Ʒ����
            string temp;
            int va = 0, vb = 0, vc = 0;
            scanf("%d",num);
            bool flag = true;//�Ϸ���Ʊ
            while (num--)
            {
                //cin >> temp;
                //type = temp[0];
                //temp.erase(temp.begin(),temp.begin()+2);
                scanf("%c:%s", type, temp);
                pos = temp.find('.');
                temp.erase(temp.begin() + pos);
                a = std::stoi(temp);
                if (type == 'A') va += a;
                else if (type == 'B') vb += a;
                else if (type == 'C') vc += a;
                else flag = false;//��������������Ʒ
            }
            if (flag && va <= 60000 && vb <= 60000 && vc <= 60000 && va + vb + vc <= 100000)
                val[++cnt] = va + vb + vc;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= cnt; i++)
            for (int j = max_val; j >= val[i]; j--)
                dp[j] = max(dp[j], dp[j - val[i]] + val[i]);  //�����Ż���һά�������͵ı�������
        printf("%d\n", dp[max_val]);
        printf("%d.%02d\n", dp[max_val], dp[max_val] - dp[max_val] / 100 * 100);
        cin >> v >> n;
    }
    return 0;
}