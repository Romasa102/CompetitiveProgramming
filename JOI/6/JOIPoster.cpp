#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,W,H;
    cin >> N >> W >> H;
    ll X[N],Y[N];
    rep(i,N){
        cin >> X[i] >> Y[i];
    }
    double EPS = 0.0000000001;
    ll ans = 0;
    rep(i,N){//center of circle A;
        rep(j,N){//A's sub
            repp(k,i,N){//center of circle B;
                rep(l,N){//B's sub
                    if(i!=j&&j!=k&&i!=k&&i!=l&&j!=l&&l!=k){
                        double cenDis = sqrt((X[i]-X[k])*(X[i]-X[k])+(Y[i]-Y[k])*(Y[i]-Y[k]));
                        double Adia = sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
                        double Bdia = sqrt((X[l]-X[k])*(X[l]-X[k])+(Y[l]-Y[k])*(Y[l]-Y[k]));
                        if(X[i] + Adia > W || X[i] - Adia < 0 || Y[i] + Adia > H || Y[i] - Adia < 0){
                            continue;
                        }
                        if(X[k] + Bdia > W || X[k] - Bdia < 0 || Y[k] + Bdia > H || Y[k] - Bdia < 0){
                            continue;
                        }
                        if(EPS + cenDis <abs(Adia-Bdia)){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}