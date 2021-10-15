#include <iostream>
#include <vector>
#include <math.h>
#define long long int int

using namespace std;

vector<bool> sieve(int N)
{
    vector<bool> lookup(N + 1, true);
    lookup[1] = lookup[0] = false;

    for (int i = 2; i <= N; ++i)
    {
        if (lookup[i])
        {
            for (int j = i * i; j <= N; j = j + i)
            {
                lookup[j] = false;
            }
        }
    }

    return lookup;
}

vector<int> primePrefixSum(vector<bool> &lookup)
{

    int S = lookup.size();
    vector<int> prefixSum(S, 0);

    int sum = 0;

    for (int i = 0; i <= S; ++i)
    {
        if (lookup[i])
        {
            sum = sum + i;
            prefixSum[i] = sum;
        }
        else
        {
            prefixSum[i] = sum;
        }
    }

    return prefixSum;
}
vector<bool> Lookup = sieve(10009);
int main()
{

    int T;

    for (int i = 0; i < Lookup.size(); ++i)
    {
        if (Lookup[i])
            cout << i << " ";
    }
    vector<int> prefixsum = primePrefixSum(Lookup);
    cin >> T;
    while (T--)
    {
        int M, N;
        cin >> M >> N;
        cout << prefixsum[N] - prefixsum[M - 1] << endl;
    }
    return 0;
}