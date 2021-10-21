dp = [[0 for i in range(2)] for j in range(105)]#创建二维列表

def solve(x): #递推
    dp[0][0] = 1
    dp[0][1] = 0
    for i in range(1, n + 1):
        dp[i][0] = dp[i][1] = dp[i - 1][0] + dp[i - 1][1]
        if i == x + 1:
            dp[i][0] -= 1
        elif i > x:
            dp[i][0] -= dp[i - x - 1][1]
    return dp[n][0] + dp[n][1]

while True:
    try: #以EOF结尾，所以用try语句
        n, k = map(int, input().split())
        print(solve(n) - solve(k - 1))
    except EOFError: #EOF就跳出
        break
