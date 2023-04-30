#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    char SO,ST,STh;
    cin >> SO >> ST >> STh;
    char EO,ET,Eth;
    cin >> EO >> ET >> Eth;
    ll dif;
    if(SO == EO){
        dif++;
    }if(ST == ET){
        dif++;
    }else if(STh == Eth){
        dif++;
    }
    if(dif == 2){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}