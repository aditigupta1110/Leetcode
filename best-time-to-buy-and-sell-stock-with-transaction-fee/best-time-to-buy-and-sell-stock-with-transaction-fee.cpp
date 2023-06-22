class Solution {
public:
    int maxProfit(vector<int>& A, int fee) {
        if (A.empty()) return 0;
        int N = A.size(), buy = INT_MIN;
        vector<int> dp(N + 1);
        for (int i = 0; i < N; ++i) {
            buy = max(buy, dp[i] - A[i]);
            dp[i + 1] = max(dp[i], A[i] - fee + buy);
        }
        return dp[N];
    }
};