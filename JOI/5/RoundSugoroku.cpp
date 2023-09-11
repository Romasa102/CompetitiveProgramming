#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,A;
    cin >> N >> A;
    string S;
    cin >> S;
    deque<ll> rightS;
    deque<ll> leftS;
    rep(i,S.size()){
        if(S[i] == '#'){
            if(i > A){
                rightS.push_back(A-i);
            }else{
                leftS.push_back(abs(i-A));
            }
        }
    }
    sort(rightS.begin(),rightS.end());
    sort(leftS.begin(),leftS.end());
    bool leftside = true;
    ll before = 0;
    while(!rightS.empty() && !leftS.empty()){
        if(leftside){
            ll o = rightS.front();
            rightS.pop_front();
        }else{
            ll o = leftS.front();
            leftS.pop_front();
        }
    }
}