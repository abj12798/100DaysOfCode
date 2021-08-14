#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generate_brackets(char *out, int indx, int open, int close, int n)
{

    if (indx == (2 * n))
    {
        out[indx] = '\0';
        cout << out << endl;
        return;
    }

    if (open < n)
    {
        out[indx] = '(';
        generate_brackets(out, indx + 1, open + 1, close, n);
    }

    if (close < open)
    {
        out[indx] = ')';
        generate_brackets(out, indx + 1, open, close + 1, n);
    }
    return;
}

vector<string> generate_brackets(int n)
{

    vector<string> result;
    result.clear();
    //generate_brackets("",0,0,0,n);

    return result;
}

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        char *out = new char[2 * n];
        generate_brackets(out, 0, 0, 0, n);
    }
    return 0;
}