#include <iostream>
using namespace std;

bool ispalindrome(int N)
{
    int S = 0;
    int K = N;
    while (N)
    {
        S = S * 10 + (N % 10);
        N = N / 10;
    }
    if (S == K)
        return true;
    else
        return false;
}

bool isprime(int N)
{
    if (N == 0 || N == 1)
        return false;
    for (int i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }

    return true;
}
int main()
{
    //code

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        if (ispalindrome(N) && isprime(N))
        {
            cout << "yes"
                 << "\n";
        }
        else
        {
            cout << "no"
                 << "\n";
        }
    }
    return 0;
}