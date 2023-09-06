#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N){
        cin >> A[i];
    }
    ll Wcount = 0;
    stack<P> con;
    con.push({A[0],1});
    repp(i,1,N){
        if(i%2 == 0){
            if(A[i] == con.top().first){
                con.top().second++;
            }else{
                con.push({A[i],1});
            }
        }
        else{
            if(A[i] == con.top().first){
                con.top().second++;
            }else{
                ll cash = 0;
                cash = con.top().second+1;
                con.pop();
                if(con.empty()){
                    con.push({A[i],cash});
                }else{
                    con.top().first = A[i];
                    con.top().second+=cash;
                }
            }
        }
    }
    while(con.size()){
        if(con.top().first == 0){
            Wcount+=con.top().second;
        }
        con.pop();
    }
    cout << Wcount << endl;
}