// #include <bits/stdc++.h>
// using namespace std;

// long long MOD = 1e9 + 7;

// int findFromTop(vector<int> &nums, int i, deque<int> &dq)
// {

//     int tCost = 0;
//     int originalSize = dq.size();
//     int moveCount = 0;

//     while (!dq.empty() && dq.front() != nums[i])
//     {
//         tCost += dq.front();
//         dq.push_back(dq.front());
//         dq.pop_front();
//         moveCount++;

//         if (moveCount > originalSize)
//         {S
//             throw runtime_error("Infinite loop detected in findFromTop.");
//         }
//     }

//     if (!dq.empty())
//     {
//         tCost += dq.front();
//         dq.pop_front();
//     }

//     return tCost;
// }

// int findFromBottom(vector<int> &nums, int i, deque<int> &dq)
// {

//     int bCost = 0;
//     int originalSize = dq.size();
//     int moveCount = 0;

//     while (!dq.empty() && dq.back() != nums[i])
//     {
//         bCost += dq.back();
//         dq.push_front(dq.back());
//         dq.pop_back();
//         moveCount++;

//         if (moveCount > originalSize)
//         {
//             throw runtime_error("Infinite loop detected in findFromBottom.");
//         }
//     }

//     if (!dq.empty())
//     {
//         bCost += dq.back();
//         dq.pop_back();
//     }
//     return bCost;
// }

// long long findMinOperationsCost(vector<int> &nums, deque<int> dq, int i, int n, int flag, vector<vector<long long>> &dp)
// {
//     if (i >= n && dq.empty())
//         return 0;
//     if (i >= n)
//     {
//         return INT_MAX;
//     }

//     if (dp[i][flag] != -1)
//     {
//         return dp[i][flag];
//     }

//     int cost = 0;
//     if (!dq.empty() && dq.front() == nums[i])
//     {
//         dq.pop_front();
//         return dp[i][flag] = min(findMinOperationsCost(nums, dq, i + 1, n, 1, dp), findMinOperationsCost(nums, dq, i + 1, n, 0, dp)) % MOD;
//     }

//     if (flag)
//     {
//         cost = findFromTop(nums, i, dq);
//     }
//     else
//     {
//         cost = findFromBottom(nums, i, dq);
//     }

//     long long nextCost = min(findMinOperationsCost(nums, dq, i + 1, n, 1, dp), findMinOperationsCost(nums, dq, i + 1, n, 0, dp));

//     if (nextCost == INT_MAX)
//     {
//         return dp[i][flag] = INT_MAX;
//     }

//     return dp[i][flag] = (cost + nextCost) % MOD;
// }

// int main()
// {
//     deque<int> dq;
//     vector<int> arr{4, 3, 2, 1};
//     vector<int> nums = arr;

//     sort(nums.begin(), nums.end());

//     long long sum = 0;
//     int size = arr.size();

//     for (int i = 0; i < size; i++)
//     {
//         dq.push_back(arr[i]);
//     }

//     vector<vector<long long>> dp(size + 1, vector<long long>(2, -1));
//     for (auto x : dq)
//         cout << x << " ";
//     try
//     {
//         sum = min(findMinOperationsCost(nums, dq, 0, size, 1, dp), findMinOperationsCost(nums, dq, 0, size, 0, dp));
//         if (sum == INT_MAX)
//         {
//             cout << "Minimum sum is: " << -1 << endl;
//         }
//         else
//         {
//             cout << "Minimum sum is: " << sum << endl;
//         }
//     }
//     catch (const runtime_error &e)
//     {
//         cout << e.what() << endl;
//     }
//     return 0;
// }
