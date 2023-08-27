#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll V,E;
    cin >> V >> E;
    ll s[E];
    ll t[E];
    ll d[E];
    rep(i,E){
        cin >> s[i] >>  t[i] >> d[i];
    }
    ll length[V][V];
    rep(i,V){
        rep(j,V){
            length[i][j] = 1LL << 60;
        }
    }
    rep(i,V){
        length[i][i] = 0;
    }
    rep(i,E){
        length[s[i]][t[i]] = d[i];
    }
    rep(h,V){
        rep(i,V){
            rep(j,V){
                if(length[i][j] > length[i][h] + length[h][j]){
                    length[i][j] = length[i][h] + length[h][j];
                }
            }
        }
    }
    rep(i,V){
        if(length[i][i] < 0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for(int i = 0; i < V; i++){
        if(length[i][0] >= 1LL<<59)printf("INF");
        else{
            printf("%lld",length[i][0]);
        }

        for(int k = 1;k < V; k++){
            if(length[i][k] >= 1LL<<59)printf(" INF");
            else{
                printf(" %lld",length[i][k]);
            }
        }
        printf("\n");
    }
}