    for (int a = 1; a <= amount; ++a) {
        for (int c : coins) {
            if (a >= c && dp[a - c] != INT_MAX) {
                dp[a] = min(dp[a], dp[a - c] + 1);
            }
        }
    }