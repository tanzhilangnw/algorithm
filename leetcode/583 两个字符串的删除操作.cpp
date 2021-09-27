//������������ word1 �� word2���ҵ�ʹ�� word1 �� word2 ��ͬ�������С������ÿ������ɾ������һ���ַ����е�һ���ַ���
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        for (int i = 1; i <= len1; i++) {
            char c = word1[i - 1];
            for (int j = 1; j <= len2; j++) {
                if (c == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        }
        int len = dp[len1][len2];
        return len1 + len2 - 2 * len;
    }
};