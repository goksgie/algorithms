#include <iostream>
#include <string>

using namespace std;

int solve(string opr){
    string::size_type sz;
    int op1 = stoi(opr,&sz);
    int op2 = stoi(opr.substr(sz+1));
    
    if(opr[sz] == '+') return op1+op2;
    else return op1-op2;
}

int main() {
    string opr;
    cin >> opr;
    int result = solve(opr);
    cout << result << endl;
    return 0;
}