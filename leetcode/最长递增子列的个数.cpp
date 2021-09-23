//给定一个未排序的整数数组，找到最长递增子序列的个数。

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector <int> dp(n), cnt(n);
        int maxLength = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = cnt[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    if (dp[j] + 1 > dp[i]) {
                        cnt[i] = cnt[j];
                        dp[i] = dp[j] + 1;
                    }
                    else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
            }

            if (dp[i] > maxLength) {
                maxLength = dp[i];
                ans = cnt[i];
            }
            else if (dp[i] == maxLength) {
                ans += cnt[i];
            }

        }
        return ans;
    }
};