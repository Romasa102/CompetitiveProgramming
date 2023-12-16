#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
void Sub4A5(ll N,string S,ll A,ll B,ll C){
    cin >> N >> S >> A >> B >> C;
    ll Fans = 1LL<<60;
    ll ans =0;
    rep(i,(N/3)*3){
        if(i%3==0){
            if(S[i]!='R'){
                ans++;
            }
        }
        if(i%3==1){
            if(S[i]!='G'){
                ans++;
            }
        }
        if(i%3==2){
            if(S[i]!='B'){
                ans++;
            }
        }
    }
    Fans = min(Fans,ans);
    if(N%3>=1){
        ans =0;
        repp(i,1,(N/3)*3+1){
            if(i%3==0){
                if(S[i]!='B'){
                    ans++;
                }
            }
            if(i%3==1){
                if(S[i]!='R'){
                    ans++;
                }
            }
            if(i%3==2){
                if(S[i]!='G'){
                    ans++;
                }
            }
        }
        Fans = min(Fans,ans);
    }
    if(N%3>=2){
        ans =0;

        repp(i,2,(N/3)*3+2){
            if(i%3==0){
                if(S[i]!='G'){
                    ans++;
                }
            }
            if(i%3==1){
                if(S[i]!='B'){
                    ans++;
                }
            }
            if(i%3==2){
                if(S[i]!='R'){
                    ans++;
                }
            }
        }
        Fans = min(Fans,ans);
    }

    cout << Fans+1000000000*(N%3) << endl;
}
int main(){
    ll N;
    string S;
    ll A,B,C;//A=cost to pop_front; B=cost to pop_back; C=cost to change the color
    cin >> N >> S >> A >> B >> C;
    if(A==1000000000&&B==1000000000&&C==1){
        Sub4A5(N,S,A,B,C);
        return 0;
    }
    ll Fans = 1LL<<60;
    rep(i,N+1){//pop_front i time
        rep(j,N+1){//pop_back j time
            if(i+j>N)continue;
            if((N-i-j)%3!=0)continue;
            ll ans = i*A+j*B;
            string R = S.substr(i,S.size()-i-j);
            rep(m,R.size()){
                if(m%3==0){
                    if(R[m]!='R')ans+=C;
                }
                if(m%3==1){
                    if(R[m]!='G')ans+=C;
                }
                if(m%3==2){
                    if(R[m]!='B')ans+=C;
                }
            }
            Fans = min(Fans,ans);
        }
    }
    cout << Fans << endl;
}