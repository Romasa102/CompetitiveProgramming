#include <bits/stdc++.h>
using namespace std;
int main(){
    string A;
    cin >> A;
    int n = A.size();
    int y = A[n-1] - '0';
    string X = A.substr(0,n-2);
    if(y <= 2){
        cout << X << "-" << endl;
    }else if(3 <= y && y <= 6){
        cout << X << endl;
    }else if(7 <= y && y <= 9){
        cout << X << "+" << endl;
    }
}