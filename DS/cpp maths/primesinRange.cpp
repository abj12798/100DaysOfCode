#include <iostream>
#include <vector>
using namespace std;

void sieve(vector<long long> &prefixSum)
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
            prefixSum[i] = prefixSum[i - 1] + 1;
        else
            prefixSum[i] = prefixSum[i - 1];
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> lookup(1000000000, -1);
    sieve(lookup);
    int T;
    cin >> T;
    while (T--)
    {
        int L, R;
        cin >> L >> R;
        cout << lookup[R] - lookup[L - 1] << "\n";
    }
    return 0;
}