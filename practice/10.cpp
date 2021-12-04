// USAGE: `g++ scorer.cpp`
// ./a.out <path-to-input> <path-to-output>
// example: ./a.out ./inputA ./outputA

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc, char** argv){
    string input_file_path, output_file_path;

    if(argc != 3){
        cout<<"Give 2 arguments in form: ./a.out <path-to-input> <path-to-output>"<<endl;
        return 0;
    }

    // taking input and output file path as input
    input_file_path = argv[1];
    output_file_path = argv[2];


    ifstream fin(input_file_path);
    int n;
    fin >> n;

    int a, b;
    vector<int> alpha, values;

    // alpha and values
    for (int i = 0; i < n; i++) {
        fin >> a;
        alpha.push_back(a);
        fin >> b;
        values.push_back(b);
    }
    
    // covariance matrix
    vector<vector<int>> covar(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> a;
            covar[i].push_back(a);
        }
    }

    ifstream fout(output_file_path);
    // betas from output file path
    vector<int> beta;

    for (int i = 0; i < n; i++) {
        fout >> b;
        beta.push_back(b);
    }

    LL cov = 0, value = 0;

    // value
    for (int i = 0; i < n; i++) {
        LL valuation = 1ll * values[i] * beta[i];
        value += valuation;
    }
    
    // covariance 
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            LL p = 1ll * beta[i] * beta[j] * covar[i][j];
            cov += p;
        }
    }

    // score
    LL score = value - cov;

    // to make negative score zero
    if(score < 0){
        cout<<"Your score is negative:"<<score<<endl;
        cout<<"So its rounded to 0"<<endl;
    }
    else{
        cout << score << endl;
    }

    return 0;
}