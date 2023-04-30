#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    bool a,b,c,d;
    a = false;
    b = false;
    c = false;
    d = false;
    ll P = 0;
    rep(i,N){
        cin >> A[i];
        a = true;
        if(A[i] == 1){
            if(d == true){
                d == false;
                P++;
            }
            if(c == true){
                c == false;
                d = true;
            }
            if(b == true){
                b == false;
                c = true;
            }
            if(a == true){
                a = false;
                b = true;
            }
        }        
        else if(A[i] == 2){
            if(d == true){
                d == false;
                P++;
            }
            if(c == true){
                c == false;
                P++;
            }
            if(b == true){
                b == false;
                d = true;
            }
            if(a == true){
                a = false;
                c = true;
            }
        }        
        else if(A[i] == 3){
            if(d == true){
                d == false;
                P++;
            }
            if(c == true){
                c == false;
                P++;
            }
            if(b == true){
                b == false;
                P++;
            }
            if(a == true){
                a = false;
                d = true;
            }
        }   
        else if(A[i] == 4){
            if(d == true){
                d == false;
                P++;
            }
            if(c == true){
                c == false;
                P++;
            }
            if(b == true){
                b == false;
                P++;
            }
            if(a == true){
                a = false;
                P++;
            }
        }
        cout << A[i] << a << b << c << d;
    }
    cout << P << endl;
}