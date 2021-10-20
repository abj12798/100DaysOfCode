// { Driver Code Starts
//Initial Template for C++

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    //Function to find list of all words possible by pressing given numbers.

    void initializemap(map<int, string> &m)
    {
        m[1] = "";
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        m[0] = "";
    }
    void makeword(int a[], int N, int i, string op, vector<string> &ans, map<int, string> &m)
    {
        if (i == N)
        {
            ans.push_back(op);
            return;
        }

        string str = m[a[i]];
        for (int j = 0; j < str.length(); j++)
        {
            makeword(a, N, i + 1, op + str[j], ans, m);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans;
        string op = "";
        map<int, string> m;
        initializemap(m);
        makeword(a, N, 0, op, ans, m);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int T;

    cin >> T; //testcases

    while (T--)
    { //while testcases exist
        int N;

        cin >> N; //input size of array

        int a[N]; //declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; //input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends