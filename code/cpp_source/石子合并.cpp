#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
long long Arr[3000], Sum[3000];
long long Min[3000][3000], Max[3000][3000];
int main() {
    int n;
    cin >> n;

    // 初始化数组
    for (int i = 1; i <= n; i++) {
        cin >> Arr[i];
        Arr[i + n] = Arr[i];
    }

    // 计算最大和
    for (int i = 1; i <= 2 * n; i++) {
        Sum[i] = Sum[i - 1] + Arr[i];
    }

    // 开始递归循环
    for (int i = 2 * n - 1; i >= 1; i--) {
        for (int j = i + 1; j < i + n; j++) {
            //Min[i][j] = INF;
            //for (int k = i; k < j; k++) {
               // Min[i][j] = min(Min[i][j], Min[i][k] + Min[k + 1][j] + Sum[j] - Sum[i - 1]);
                Max[i][j] = max(Max[i+1][j],Max[i][j-1]) + Sum[j] - Sum[i - 1];
            //}
        }
    }

    // 遍历找到最大与最小值
    long long MaxValue = 0, MinValue = INF;
    for (int i = 1; i <= n; i++) {
        MaxValue = max(MaxValue, Max[i][i + n - 1]);
        //MinValue = min(MinValue, Min[i][i + n - 1]);
    }

    //cout << MinValue << endl << MaxValue << endl;
    cout << MaxValue;
}