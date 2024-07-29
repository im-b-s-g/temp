// Q1 #include <iostream>
//  #include <vector>
//  #include <algorithm>
//  #include <unordered_map>

// using namespace std;

// int minSwapsToSort(vector<int> &arr, vector<int> &target)
// {
//     int n = arr.size();
//     unordered_map<int, int> pos;

//     for (int i = 0; i < n; i++)
//     {
//         pos[target[i]] = i;
//     }

//     vector<bool> visited(n, false);
//     int swaps = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (visited[i] || target[i] == arr[i])
//         {
//             continue;
//         }

//         int cycle_size = 0;
//         int j = i;

//         while (!visited[j])
//         {
//             visited[j] = true;
//             j = pos[arr[j]];
//             cycle_size++;
//         }

//         if (cycle_size > 0)
//         {
//             swaps += (cycle_size - 1);
//         }
//     }

//     return swaps;
// }

// int maxScoreMinSwaps(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> sortedArr = arr;
//     sort(sortedArr.begin(), sortedArr.end());
//     vector<int> desiredArrangement(n);

//     for (int i = 0; i < n / 2; i++)
//     {
//         desiredArrangement[2 * i] = sortedArr[i];
//         desiredArrangement[2 * i + 1] = sortedArr[n - 1 - i];
//     }

//     return minSwapsToSort(arr, desiredArrangement) - 1;
// }

// int main()
// {
//     vector<int> arr = {9, 1, 2, 4, 3, 6, 7, 8};
//     cout << "Minimum number of swaps required: " << maxScoreMinSwaps(arr) << endl;
//     return 0;
// }

// Q2.------------------------------------------------------------------------------------------

// #include <bits/stdc++.h>
// using namespace std;

// int UpdateB(vector<int> &A, vector<int> &B, int i, int val, map<int, int> &mp, int &count)
// {
//     A[i] -= val;
//     mp[val] -= 1;

//     if (mp[val] == 0)
//         count -= 1;

//     for (int j = i; j < B.size(); j++)
//     {
//         B[j] = min(A[j], B[j - 1]);

//         if (mp[B[j]] == 0)
//             count += 1;
//     }

//     return count;
// }

// int main()
// {
//     vector<int> A{5, 7, 2, 4};
//     vector<int> B(4, 0);
//     vector<vector<int>> queries{{2, 2}, {4, 3}};
//     map<int, int> mp;
//     int count = 0;

//     B[0] = A[0];
//     for (int i = 1; i < 4; i++)
//     {
//         B[i] = min(A[i], B[i - 1]);
//     }

//     for (auto x : B)
//     {
//         if (mp[x] == 0)
//             count++;

//         mp[x] += 1;
//     }
//     vector<int> res;
//     for (int i = 0; i < 2; i++)
//     {
//         int X = queries[i][0];
//         int Y = queries[i][1];

//         int ans = UpdateB(A, B, X - 1, Y, mp, count);
//         res.push_back(ans);
//     }

//     cout << "Answer of queries" << endl;
//     for (auto x : res)
//         cout << x << " ";

//     return 0;
// }

// Q3.
#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

int findFromTop(vector<int> nums, int i, deque<int> &dq)
{
    int tCost = 0;
    int originalSize = dq.size();
    int moveCount = 0;

    while (!dq.empty() && dq.front() != nums[i])
    {
        tCost += dq.front();
        dq.push_back(dq.front());
        dq.pop_front();
        moveCount++;

        if (moveCount > originalSize)
        {
            throw runtime_error("Infinite loop detected in findFromTop.");
        }
    }
    dq.pop_front();
    return tCost;
}

int findFromBottom(vector<int> nums, int i, deque<int> &dq)
{
    int bCost = 0;
    int originalSize = dq.size();
    int moveCount = 0;

    while (!dq.empty() && dq.front() != nums[i])
    {
        bCost += dq.back();
        dq.push_front(dq.back());
        dq.pop_back();
        moveCount++;

        if (moveCount > originalSize)
        {
            throw runtime_error("Infinite loop detected in findFromBottom.");
        }
    }

    dq.pop_front();
    return bCost;
}

long long findMinOperationsCost(vector<int> nums, deque<int> &dq, int i, int n, int flag, vector<vector<long long>> &dp)
{
    if (i == n + 1)
    {
        return 0;
    }

    if (dp[i][flag] != -1)
    {
        return dp[i][flag];
    }

    int cost = 0;
    if (!dq.empty() && dq.front() == nums[i])
    {
        dq.pop_front();
        return dp[i][flag] = min(findMinOperationsCost(nums, dq, i + 1, n, 1, dp), findMinOperationsCost(nums, dq, i + 1, n, 0, dp)) % MOD;
    }

    if (flag)
    {
        cost = findFromTop(nums, i, dq);
    }
    else
    {
        cost = findFromBottom(nums, i, dq);
    }

    return dp[i][flag] = (cost + min(findMinOperationsCost(nums, dq, i + 1, n, 1, dp), findMinOperationsCost(nums, dq, i + 1, n, 0, dp))) % MOD;
}

int main()
{
    deque<int> dq;
    vector<int> arr{1, 1, 1, 1, 1};
    vector<int> nums = arr;

    sort(nums.begin(), nums.end());

    long long sum = 0;
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        dq.push_back(arr[i]);
    }

    vector<vector<long long>> dp(size + 2, vector<long long>(2, -1));

    try
    {
        sum = min(findMinOperationsCost(nums, dq, 1, size, 1, dp), findMinOperationsCost(nums, dq, 1, size, 0, dp));
        cout << "Minimum sum is: " << sum;
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
