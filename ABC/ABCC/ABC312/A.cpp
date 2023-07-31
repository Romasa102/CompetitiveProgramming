#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    if(S == "ACE"||S == "BDF"||S == "CEG"||S == "DFA"||S =="EGB"||S == "FAC"||S == "GBD"){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}