class Solution {
    public:
        int peopleAwareOfSecret(int n, int delay, int forget) {
            const int MOD = 1e9 + 7;
    
            vector<int> dp(n + 1, 0);
            dp[1] = 1;
    
            for (int curDay = 1; curDay <= n; ++curDay) {
                if (dp[curDay] > 0) {
                    for (int nextDay = curDay + delay; nextDay < curDay + forget && nextDay <= n; ++nextDay) {
                        dp[nextDay] = (dp[nextDay] + dp[curDay]) % MOD;
                    }
                }
            }
            
            int result = 0;
            for (int day = n - forget + 1; day <= n; ++day) {
                if (day >= 1) {
                    result = (result + dp[day]) % MOD;
                }
            }
    
            return result;
        }
    };
