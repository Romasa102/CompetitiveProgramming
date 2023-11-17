#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    deque<ll> abc;
    ll before = -1;
    ll Tbefore = -1;
    rep(i,S.size()){
        if(S[i] == 'A'){
            Tbefore = before;
            before = 0;
            abc.push_front(0);
        }
        if(S[i] == 'B'){
            Tbefore = before;
            before = 1;
            abc.push_front(1);
        }
        if(S[i] == 'C'){
            if(Tbefore == 0 && before == 1){
                abc.pop_front();abc.pop_front();
                if(abc.size()>=1){
                    before = abc.front();
                }else{
                    before = -1;
                    Tbefore = -1;
                    continue;
                }
                Tbefore = -1;
                if(abc.size()>=2){
                    abc.pop_front();
                    Tbefore = abc.front();
                    abc.push_front(before);
                }
            }else{
                Tbefore = before;
                before = 2;
                abc.push_front(2);
            }
        }
    }
    while(!abc.empty()){
        if(abc.back() == 0){
            cout << 'A';
        }else if(abc.back() == 1){
            cout << 'B';
        }else{
            cout << 'C';
        }
        abc.pop_back();
    }cout << endl;
}