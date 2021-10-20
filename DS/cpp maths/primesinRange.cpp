
#include <iostream>
#include <vector>
#include <math.h>
//For simplification and to reduce the chance of error due to value out of integer range, keep all the variables as long long instead of int
#define int long long
using namespace std;
void segmentedsieve(long long N, vector<long long> &prime)
{

    vector<bool> sievelookup(N + 1, true);

    for (long long i = 2; i <= N; i++)
    {
        if (sievelookup[i])
        {
            prime.push_back(i);
            for (long long j = i * i; j <= N; j += i)
            {
                sievelookup[j] = false;
            }
        }
    }
    sievelookup.clear();
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> prime;
    //size of upto  200005 is sufficient
    segmentedsieve(200005, prime);

    int T;
    cin >> T;
    while (T--)
    {
        int L, R;
        cin >> L >> R;
        vector<int> isprimeinRange(R - L + 1, -1);
        for (int i = 0; i < prime.size() && prime[i] <= R; ++i)
        {
            //cout << prime[i] << " ";
            int sm = floor(L / prime[i]) * prime[i];
            if (sm < L)
            {
                sm += prime[i];
            }
            if (sm == prime[i])
            {
                sm += prime[i];
            }
            for (int j = sm; j <= R; j += prime[i])
            {
                if (isprimeinRange[j - L])
                {
                    isprimeinRange[j - L] = -2;
                }
            }
        }
        long long sum = 0;
        for (int j = L; j <= R; j++)
        {
            if (isprimeinRange[j - L] == -1)
            {
                sum++;
            }
        }
        // 1 isn't a prime number
        if (L == 1)
            sum--;
        cout << sum
             << "\n";
    }
    return 0;
}