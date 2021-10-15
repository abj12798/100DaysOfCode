/*
Geek likes prime numbers and his little sister likes to play with arrays. She needs your help as he gave her an array arr of integers of size N, and the task to find the number of subarrays with prime sum.

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains a single integer N.
3. The next line of each test case contains N space-separated integers.


Output: For each test case, print the answer

Constraints:
1. 1 ≤ T ≤ 10
2. 1 ≤ N ≤ 10^3
3.  1 ≤ arr[i] ≤ 10^4


*/

#include <iostream>
#include <vector>

using namespace std;

bool isPrime(long long N)
{

    if (N == 0 || N == 1)
        return false;

    for (long long i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;
        vector<long long> array;
        vector<long long> prefixSum;
        long long sum = 0;
        for (long long i = 0; i < N; ++i)
        {
            int X;
            cin >> X;
            array.push_back(X);
            sum = sum + X;
            prefixSum.push_back(sum);
        }

        long long result = 0;

        for (long long i = (N - 1); i >= 0; i--)
        {
            for (long long j = -1; j < i; j++)
            {
                if (j == -1)
                {
                    result = (isPrime(prefixSum[i])) ? result + 1 : result;
                }
                else
                {

                    if (isPrime(prefixSum[i] - prefixSum[j]))
                    {
                        result = result + 1;
                    }
                }
            }
        }

        cout << result << "\n";
    }
    return 0;
}
