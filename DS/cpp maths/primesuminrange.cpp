#include <iostream>
#include <vector>
#include <math.h>
#define long long int int

using namespace std;

void sieve(vector<int> &prefixSum)
{

    prefixSum[1] = 0;
    prefixSum[0] = 0;

    for (int i = 2; i <= prefixSum.size(); ++i)
    {
        if (prefixSum[i] == -1)
        {
            for (int j = i * i; j <= prefixSum.size(); j = j + i)
            {
                prefixSum[j] = -2;
            }
        }

        if (prefixSum[i] == -1)
            prefixSum[i] = prefixSum[i - 1] + i;
        else
            prefixSum[i] = prefixSum[i - 1];
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    vector<int> prefixPrimeSum(1000001, -1);
    sieve(prefixPrimeSum);
    cin >> T;
    while (T--)
    {
        int M, N;
        cin >> M >> N;

        cout << prefixPrimeSum[N] - prefixPrimeSum[M - 1] << "\n";
    }
    return 0;
}