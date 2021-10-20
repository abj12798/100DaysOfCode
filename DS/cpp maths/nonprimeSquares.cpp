/*
Geek, Jessy, and Walter participated in a coding contest, and they solved all the questions except for this question. They called you and asked for help. The question contains two integers l and r and the task is to find the sum of squares of non-prime numbers in the range l to r. Can you help Geek's team to win the contest?

Note: The answer can be very large. So, output answer modulo 109+7.

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains two space-separated integers l and r.

Output: For each test case, print the answer

Constraints:
1. 1 ≤ T ≤ 105
2. 1 ≤  l ≤ r ≤ 105
*/

#include <iostream>
#include <vector>
#define M 1000000007
using namespace std;

void sieve(vector<unsigned long long> &prefixSum)
{

    prefixSum[0] = 0;
    prefixSum[1] = 1;
    unsigned long long range = prefixSum.size();
    for (unsigned long long i = 2; i <= range; ++i)
    {
        if (prefixSum[i] == M + 1)
        {
            for (unsigned long long j = i * i; j <= range; j = j + i)
            {
                prefixSum[j] = M + 2;
            }
        }

        if (prefixSum[i] == M + 1)
        {
            prefixSum[i] = prefixSum[i - 1];
        }
        else
        {
            prefixSum[i] = (prefixSum[i - 1] + (i * i) % M) % M;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    vector<unsigned long long> lookup(100001, M + 1);
    sieve(lookup);
    cin >> T;

    while (T--)
    {
        unsigned long long l, r;
        cin >> l >> r;
        cout << (lookup[r] - lookup[l - 1]) % M << "\n";
    }
    //code
    return 0;
}