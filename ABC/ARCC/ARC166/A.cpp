#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(j,T){
        ll N;
        string X,Y;
        cin >>N >> X >> Y;
        bool ans = true;
        priority_queue<ll,vector<ll>,greater<ll>>B;
        priority_queue<ll,vector<ll>,greater<ll>>C;
        priority_queue<ll>CB;
        rep(i,N){
            if(X[i] == 'B')B.push(i);
            if(X[i] == 'C')C.push(i);
        }
        rep(i,N){
            if(X[i] == 'B') B.pop();
            if(X[i] == 'C') C.pop();
            if(X[i] == 'C' && Y[i] != 'A'){
                CB.push(i);
            }
            if(X[i] != Y[i]){
                if(Y[i] == 'C'){
                    ans = false;
                    break;
                }
                if(X[i]=='A'){
                    if(B.empty()&&C.empty()){
                        ans = false;
                        break;
                    }
                    if(B.empty()){
                        ll use = C.top();
                        if(Y[use] == 'C'){
                            ans = false;
                            break;
                        }
                        X[use] = 'A';
                        X[i] = 'C';
                        CB.push(i);
                        C.pop();
                        continue;
                    }
                    if(C.empty()) {//use B;
                        ll use = B.top();
                        X[use] = 'A';
                        X[i] = 'B';
                        B.pop();
                        continue;
                    }
                    if(B.top() < C.top()){
                        ll use = B.top();
                        X[use] = 'A';
                        X[i] = 'B';
                        B.pop();
                    }else{//use C;
                        ll use = C.top();
                        if(Y[use] == 'C'){
                            ans = false;
                            break;
                        }
                        X[use] = 'A';
                        X[i] = 'C';
                        CB.push(i);
                        C.pop();
                    }
                    continue;
                }
                if(X[i] == 'B'){
                    if(CB.empty()){
                        ans = false;
                        continue;
                    }
                    ll use = CB.top();
                    if(Y[use] == 'C'){
                        ans = false;
                        break;
                    }
                    CB.pop();
                    X[i] = 'C';
                    X[use] = 'B';
                }
            }
        }
        if(ans){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}