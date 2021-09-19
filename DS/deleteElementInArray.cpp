#include <iostream>
#include <vector>

using namespace std;

int deleteElementInArray(int *arr, int N, int num)
{

    int i = 0;

    for (i = 0; i < N; ++i)
    {
        if (arr[i] == num)
            break;
    }
    if (i == N)
        return N;
    for (int j = 0; j < (N - 1); ++j)
    {
        arr[j] = arr[j + 1];
    }
    return N - 1;
}

int main()
{

    int *arr;

    int N;
    cin >> N;
    arr = new int[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    return 0;
}
