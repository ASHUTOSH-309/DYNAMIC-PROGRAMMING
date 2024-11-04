#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Include the current item or exclude it
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // Exclude the current item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value will be in dp[n][W]
    return dp[n][W];
}

int main() {
    int W = 50;  // Maximum weight capacity of knapsack
    vector<int> weights = {10, 20, 30};  // Weights of items
    vector<int> values = {60, 100, 120};  // Values of items

    int max_value = knapsack(W, weights, values);
    cout << "Maximum value in Knapsack = " << max_value << endl;

    return 0;
}
