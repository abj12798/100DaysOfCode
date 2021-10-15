#include <iostream>
#include <vector>
#include <math.h>
#define int long long int
using namespace std;

vector<int> sieve(int N)
{

    vector<bool> sievelookup(N + 1, true);
    vector<int> prime;

    for (int i = 2; i <= N; i++)
    {
        if (sievelookup[i])
        {
            prime.push_back(i);
            for (int j = i * i; j <= N; j += i)
            {
                sievelookup[j] = false;
            }
        }
    }

    return prime;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N;
        cin >> M >> N;

        vector<int> prime = sieve(floor(sqrt(N)) + 1);
        vector<bool> isprimeinRange(N - M + 1, true);
        int sum = 0;
        for (int i = 0; i < prime.size(); i++)
        {

            int sm = floor(M / prime[i]) * prime[i];
            if (sm < M)
            {
                sm += prime[i];
            }
            if (sm == prime[i])
            {
                sm += prime[i];
            }
            for (int j = sm; j <= N; j += prime[i])
            {
                if (isprimeinRange[j - M])
                {
                    isprimeinRange[j - M] = false;
                }
            }
        }
        for (int j = M; j <= N; j++)
        {
            if (isprimeinRange[j - M])
            {
                sum += j;
            }
        }
        cout << sum << " ";
    }

    return 0;
}