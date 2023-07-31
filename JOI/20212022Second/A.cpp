#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    stack<string> book;
    ll N;
    cin >> N;
    rep(i,N){
        string S;
        cin >> S;
        if(S == "READ"){
            cout << book.top() << endl;
            book.pop();
        }
        else{
            book.push(S);
        }
    }
}