#include <bits/stdc++.h>
using namespace std;

// Function to generate all prime squares up to max_limit using Sieve of Eratosthenes
vector<long long> sieve(int n, map<long long, int> &mp)
{
    vector<long long> primeSquares;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;

            mp[i * i] = 1;
            primeSquares.push_back(i * i);
        }
    }
    return primeSquares;
}

int main()
{
    int N;
    cout << "Enter N: ";
    cin >> N;

    int M = sqrt(N) + 1;
    map<long long, int> mp;
    vector<long long> primeSquares = sieve(M, mp);

    int flag = 1;
    int minSum = INT_MAX;
    pair<int, int> result;

    for (auto x : primeSquares)
    {
        if (mp.find(N - x) != mp.end())
        {
            flag = 0;
            int X = sqrt(x);
            int Y = sqrt(N - x);
            if (X + Y < minSum)
            {
                minSum = X + Y;
                result = {X, Y};
            }
        }
    }

    if (flag)
        cout << "No possible Primes" << endl;
    else
        cout << "Minimum X+Y: " << result.first + result.second << " with X: " << result.first << " and Y: " << result.second << endl;

    return 0;
}
