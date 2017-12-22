#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n,q;
    cin>>n;
    vector<string> inputs(n);
    for(int i =0; i<n; i++) cin>>inputs[i];
    cin>>q;
    vector<string> queries(q);
    for(int i =0; i<q; i++) cin>>queries[i];
    for(auto& query:queries){
        int count = 0;
        for(auto& input:inputs){
            string temp_inp = input;
            string temp_q = '^'+query+'$';
            regex expr(temp_q);
            smatch m_res;
            while(regex_search(temp_inp, m_res, expr)){
                for(auto& x:m_res) count+=1;
                temp_inp = m_res.suffix().str();
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
