#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
ll M = 999999999999999999;
void Dn(int MaxN,int MinN,vector<ll> D){
    if(*lower_bound(D.begin(),D.end(),MinN) <= MaxN){
        if(MaxN - MinN <= M){
            M = MaxN - MinN;
            return;
        }
    }else{
        if(D[D.size()-1] >= MaxN){
            if(*lower_bound(D.begin(),D.end(),MinN) >= MaxN){
                if(*lower_bound(D.begin(),D.end(),MinN) - MinN <= M){
                    M = *lower_bound(D.begin(),D.end(),MinN) - MinN;
                    return;
                }
            }
        }
        if(*--lower_bound(D.begin(),D.end(),MaxN) <= MinN){
            if(lower_bound(D.begin(),D.end(),MaxN) != D.begin()){
                if(MaxN - *--lower_bound(D.begin(),D.end(),MaxN) <= M){
                    M = MaxN - *--lower_bound(D.begin(),D.end(),MaxN);
                    return;
                }
            }
        }
    }
}
void Cn(int MaxN,int MinN,vector<ll> C,vector<ll> D){
    if(*lower_bound(C.begin(),C.end(),MinN) <= MaxN){
        if(lower_bound(C.begin(),C.end(),MinN) != C.end()){
            Dn(MaxN,MinN,D);
        }}
        else{
        if(C[C.size()-1] >= MaxN){
            if(*lower_bound(C.begin(),C.end(),MinN) >= MaxN){
                Dn(*lower_bound(C.begin(),C.end(),MinN),MinN,D);
            }
        }
        if(C[0] <= MinN){
            if(*--lower_bound(C.begin(),C.end(),MaxN) <= MinN){
                if(lower_bound(C.begin(),C.end(),MaxN) != C.begin()){
                    Dn(MaxN,*--lower_bound(C.begin(),C.end(),MaxN),D);
                }
            }
        }
    }
    
    return;
}
void Bn(int MaxN,int MinN,vector<ll> B,vector<ll> C,vector<ll> D){
    if(*lower_bound(B.begin(),B.end(),MinN) <= MaxN){
        Cn(MaxN,MinN,C,D);
    }else{
        if(B[B.size()-1] >= MaxN){
            if(*lower_bound(B.begin(),B.end(),MinN) >= MaxN){
                Cn(*lower_bound(B.begin(),B.end(),MinN),MinN,C,D);
            }
        }
        if(B[0] <= MinN){
            if(*--lower_bound(B.begin(),B.end(),MaxN) <= MinN){
                if(lower_bound(B.begin(),B.end(),MaxN) != B.begin()){
                    Cn(MaxN,*--lower_bound(B.begin(),B.end(),MaxN),C,D);
                }
            }

        }
    }
    return;
}
int main(){
    ll N;
    cin >> N;
    ll S[4];
    if(N == 1){
        cin >> S[0] >> S[1] >> S[2] >> S[3];
        sort(S,S+4);
        cout << S[3] - S[0] << endl;
        return 0;
    }
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    vector<ll> D(N);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        cin >> B[i];
    }
    rep(i,N){
        cin >> C[i];
    }
    rep(i,N){
        cin >> D[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    sort(D.begin(),D.end());
    rep(i,N){
        ll maxN;
        ll minN;
        maxN = A[i];
        minN = A[i];
        Bn(maxN,minN,B,C,D);
    }
    cout << M << endl;
}