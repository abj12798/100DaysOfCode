#include <iostream>

using namespace std;

int SecondLargestElementIndex(int *arr, int N)
{
    int res = 0;
    int index = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[res] <= arr[i])
        {
            index = res;
            res = i;
        }
    }

    if (arr[res] == arr[index])
        return -1;

    return index;
}

int main()
{
    int N;
    cin >> N;

    int *arr = new int[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int k = SecondLargestElementIndex(arr, N);
    cout << k << endl;
    return 0;
}