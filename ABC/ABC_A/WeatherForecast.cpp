#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;
    char o ;
    if(S[N-1] == 'o'){
        cout << "Yes" << endl;
    }
    else if(S[N-1] == 'x'){
        cout << "No" << endl;
    }
}