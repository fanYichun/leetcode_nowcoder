#include <stdio.h>
#include <stdlib.h>

int coinChange(int* coins, int coinsSize, int amount) {
    for (int i = 0; i < coinsSize; i++) {
        for (int j = i + 1; j < coinsSize; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    int* dp = (int*)malloc((amount + 1) * sizeof(int));
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        dp[i] = 10001;
        for (int j = 0; j < coinsSize; j++) {
            if (i >= coins[j]) {
                dp[i] = (dp[i] > 1 + dp[i - coins[j]] ? 1 + dp[i - coins[j]] : dp[i]);
            }
        }
    }

    if (dp[amount] == 10001) dp[amount] = -1;
    return dp[amount];
}

int main() {
    int arr[] = { 186, 419, 83, 408 };
    int result = coinChange(arr, 4, 6249);
    return 0;
}