#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
vector<vector<P>> parent(600, vector<P>(600));
P find(P num){
    if(parent[num.first][num.second] == num){
        return num;
    }
    return find(parent[num.first][num.second]);
}
void Union(P a,P b){
    parent[find(a).first][find(a).second] = find(b);
}
int main(){
    ll H,W;
    cin >> H >>W;
    ll A[H][W];
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }
    rep(i,H){
        rep(j,W){
            parent[i][j] = {i,j};
        }
    }
    rep(i,H){
        rep(j,W){
            if(i+1 != H && A[i][j]==A[i+1][j]){
                Union({i,j},{i+1,j});
            }
            if(i-1 >= 0 && A[i][j]==A[i-1][j]){
                Union({i,j},{i-1,j});
            }
            if(j+1 != W && A[i][j]==A[i][j+1]){
                Union({i,j},{i,j+1});
            }
            if(j-1 >= 0 && A[i][j]==A[i][j-1]){
                Union({i,j},{i,j-1});
            }
        }
    }
    map<P,ll> size;
    ll maxSum = 0;
    rep(i,H){
        rep(j,W){
            size[find({i,j})]++;
            maxSum = max(maxSum,size[find({i,j})]);
        }
    }
    map<pair<P,ll>,set<P>> adjacent; //map<oneParentsPos,map<color,vector<otherParentPos>>>
    rep(i,H){
        rep(j,W){
            if(i+1 != H && A[i][j]!=A[i+1][j]){
                adjacent[{find({i,j}),A[i+1][j]}].insert(find({i+1,j}));
            }
            if(i-1 >= 0 && A[i][j]!=A[i-1][j]){
                adjacent[{find({i,j}),A[i-1][j]}].insert(find({i-1,j}));
            }
            if(j+1 != W && A[i][j]!=A[i][j+1]){
                adjacent[{find({i,j}),A[i][j+1]}].insert(find({i,j+1}));
            }
            if(j-1 >= 0 && A[i][j]!=A[i][j-1]){
                adjacent[{find({i,j}),A[i][j-1]}].insert(find({i,j-1}));
            }
        }
    }
    rep(i,H){
        rep(j,W){
            if(i+1 != H && A[i][j]!=A[i+1][j]){
                ll sum  = 0;
                sum += size[find({i,j})];
                for(P o : adjacent[{find({i,j}),A[i+1][j]}]){
                    sum += size[o];
                }
                maxSum = max(maxSum,sum);
            }
            if(i-1 >= 0 && A[i][j]!=A[i-1][j]){
                ll sum  = 0;
                sum += size[find({i,j})];
                for(P o : adjacent[{find({i,j}),A[i-1][j]}]){
                    sum += size[o];
                }
                maxSum = max(maxSum,sum);
            }
            if(j+1 != W && A[i][j]!=A[i][j+1]){
                ll sum  = 0;
                sum += size[find({i,j})];
                for(P o : adjacent[{find({i,j}),A[i][j+1]}]){
                    sum += size[o];
                }
                maxSum = max(maxSum,sum);
            }
            if(j-1 >= 0 && A[i][j]!=A[i][j-1]){
                ll sum  = 0;
                sum += size[find({i,j})];
                for(P o : adjacent[{find({i,j}),A[i][j-1]}]){
                    sum += size[o];
                }
                maxSum = max(maxSum,sum);
            }
        }
    }
    cout << maxSum << endl;
}