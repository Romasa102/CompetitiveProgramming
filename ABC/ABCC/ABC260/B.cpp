#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    ll X,Y,Z;
    cin >> N;
    cin >> X >> Y >> Z;
    bool Win[N];
    vector<P> A(N);
    vector<P> B(N);
    rep(i,N){
        Win[i] = false;
    }
    rep(i,N){
        cin >> A[i].first;
        A[i].second =i*-1;
    }
    rep(i,N){
        cin >> B[i].first;
        B[i].second = i*-1;
    }
    vector<P> C(N);
    rep(i,N){
        C[i].first = A[i].first + B[i].first;
        C[i].second = i*-1;
    }
    sort(A.begin(),A.end(),greater<P>());
    rep(i,X){
        Win[A[i].second * -1] = true;
    }
    
    sort(B.begin(),B.end(),greater<P>());
    ll counter = 0;
    rep(i,N){
        if(counter >= Y){
            break;
        }
        if(Win[B[i].second * -1] == false){
            Win[B[i].second * -1] = true;
            counter++;
        }
    }
    sort(C.begin(),C.end(),greater<P>());
    rep(i,N){
        cout << C[i].first << endl;
    }
    ll counterTwo = 0;
    rep(i,N){
        if(counterTwo >= Z){
            break;
        }
        if(Win[C[i].second * -1] == false){
            Win[C[i].second * -1] = true;
            counterTwo++;
        }
    }
    rep(i,N){
        if(Win[i] == true){
            cout << i+1 << endl;
        }
    }
}