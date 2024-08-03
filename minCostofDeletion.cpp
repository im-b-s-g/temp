#include <bits/stdc++.h>
using namespace std;

vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

int printMinimumRemovals(string str, string X)
{
    int N = str.size();
    int M = X.size();

    int dp[N][M] = {};

    for (int j = 0; j < M; j++)
    {
        // If X[j] matches with str[0]
        if (str[0] == X[j])
        {
            dp[0][j] = 1;
        }
    }

    for (int i = 1; i < N; i++)
    {

        for (int j = 0; j < M; j++)
        {

            // If str[i] is equal to X[j]
            if (str[i] == X[j])
            {

                // Update state after removing str[i[
                dp[i][j] = dp[i - 1][j] + A[i];

                // Update state after keeping str[i]
                if (j != 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }

            // If str[i] is not equal to X[j]
            else
            {

                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Print the minimum number
    // of characters removals
    return dp[N - 1][M - 1];
}

// Driver Code
int main()
{
    // Input
    string str = "hallohallohallo";
    string X = "allo";

    // Function call to get minimum
    // number of character removals
    cout << "Minimum cost to delete characters " << printMinimumRemovals(str, X) << endl;

    return 0;
}
