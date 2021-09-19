#include <iostream>

using namespace std;

int largestElementIndex(int *arr, int N)
{
    int maxElement = -1;
    int index = 0;
    for (int i = 0; i < N; ++i)
    {
        if (maxElement < arr[i])
        {
            maxElement = arr[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int k = largestElementIndex(arr, N);
    cout << k << endl;
    return 0;
}