#include<iostream>
#include<string>
#include<vector>
using namespace std;

void generate_brackets(string out,int indx,int open,int close,int n,vector<string>& res){

    if(indx == 2*n){
        return res.push_back(out);
    }

    else if(open < n){
        out = out + '(';
        generate_brackets(out,indx + 1, open + 1, close, n,res);
        return;
    }

    else if(close < open){
        out = out + ')';
        generate_brackets(out, indx + 1, open, close + 1, n,res);
        return;

    }

}

vector<string> generate_brackets(int n){

    vector<string> result;
    result.clear();
    generate_brackets("",0,0,0,n,result);

    return result;

}

int main(){

    int T;
    cin>>T;

    while(T--){
        int n;
        cin>>n;
        vector<string> res = generate_brackets(n);
        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<endl;
        }
    }
    return 0;
}