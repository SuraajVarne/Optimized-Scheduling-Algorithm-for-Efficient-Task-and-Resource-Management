#include "algorithm.h"
#include <queue> // Include the <queue> header
#include <algorithm>
#include <limits>

using namespace std;

vector<int> topologicalSort(const vector<int>& executionTimes, const vector<vector<int>>& dependencies) {
    int n = executionTimes.size();
    vector<int> inDegree(n, 0);
    vector<int> order;
    queue<int> q; // Use std::queue here

    for (const auto& dep : dependencies) {
        for (int v : dep) {
            inDegree[v]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : dependencies[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return order;
}

vector<std::vector<int>> dynamicProgramming(const vector<int>& executionTimes, const vector<vector<int>>& dependencies, int K) {
    int n = executionTimes.size();
    vector<std::vector<int>> dp(n + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= K; ++j) {
            int currExecTime = 0;
            int minTime = numeric_limits<int>::max();

            for (int k = i; k >= 1; --k) {
                currExecTime += executionTimes[k - 1];

                if (j > 1 && k < i) {
                    currExecTime += dependencies[k - 1][i - 1];
                }

                minTime = min(minTime, max(dp[k - 1][j - 1], currExecTime));
            }

            dp[i][j] = minTime;
        }
    }

    return dp;
}

int backtracking(const vector<int>& executionTimes, const vector<vector<int>>& dp, int n, int K, vector<int>& schedule) {
    int i = n;
    int j = K;

    while (i > 0 && j > 0) {
        for (int k = i; k >= 1; --k) {
            if (dp[i][j] == dp[k - 1][j - 1] + max(executionTimes[k - 1], dp[i][j] - dp[k - 1][j - 1])) {
                for (int l = k; l <= i; ++l) {
                    schedule[l - 1] = j;
                }
                i = k - 1;
                j--;
                break;
            }
        }
    }

    return dp[n][K];
}

int minExecutionTime(const vector<int>& executionTimes, const vector<vector<int>>& dependencies, int K) {
    vector<int> order = topologicalSort(executionTimes, dependencies);
    vector<vector<int>> dp = dynamicProgramming(executionTimes, dependencies, K);
    vector<int> schedule(executionTimes.size(), 0);

    int minTime = backtracking(executionTimes, dp, executionTimes.size(), K, schedule);
    return minTime;
}
