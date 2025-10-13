#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
int main(){
    string S;
    ll A;
    cin >> S >> A;
    vector<ll> cNum;
    vector<ll> cSum;
    vector<char> c;
    string currentN = "";
    rep(i,S.size()){
        if('a' <= S[i] && S[i] <= 'z'){
            c.push_back(S[i]);
        }else{
            currentN += S[i];
            if(i == S.size()-1 || ('a' <= S[i+1] && S[i+1] <= 'z')){
                cNum.push_back(stoll(currentN));
                currentN = "";
            }
        }
    }
    cSum.resize(cNum.size());
    cSum[0] = cNum[0];
    repp(i,1,cSum.size()){
        cSum[i] = cSum[i-1]+cNum[i];
    }
    A = A%(cSum[cSum.size()-1])+1;
    ll pos = lower_bound(cSum.begin(),cSum.end(),A)-cSum.begin();
    cout << c[pos] << endl;
}