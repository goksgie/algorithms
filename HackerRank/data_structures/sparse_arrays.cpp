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
            if(query.size() != input.size()) continue;
            bool should_continue = false;
            for(int i =0; i<query.size(); i++){
                if(query[i] != input[i]){
                    should_continue = true;
                    break;
                }
            }
            if(should_continue) continue;
            count+=1;
        }
        cout<<count<<endl;
    }
    return 0;
}
