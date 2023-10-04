#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string pol[3][4][4];
    rep(i,3)rep(j,4)cin >> pol[i][j][0];
    ll num1 = 0;
    ll num2 = 0;
    ll num3 = 0;
    rep(i,4)rep(j,4){
        if(pol[0][i][0][j] == '#'){
            num1++;
        }
    }
    rep(i,4)rep(j,4){
        if(pol[1][i][0][j] == '#'){
            num2++;
        }
    }
    rep(i,4)rep(j,4){
        if(pol[2][i][0][j] == '#'){
            num3++;
        }
    }
    rep(l,3){
        rep(k,3){
            rep(i,4){
                rep(j,4){
                    pol[l][i][k+1][j] = pol[l][j][k][3-i];
                }
            }
        }
    }
    //polN,X,ROTATION,Y
    repp(i,-3,4){
        repp(j,-3,4){
            rep(k,4){
                string boxA[4] = {"....","....","....","...."};
                ll count1 = 0;
                rep(t,4){
                    rep(y,4){
                        if(t+i>3||t+i<0||y+j>3||y+j<0){
                            boxA[t][y] = '.';
                            continue;
                        }
                        boxA[t][y] = pol[0][t+i][k][y+j];
                        if(boxA[t][y] == '#'){
                            count1++;
                        }
                    }
                }
                if(count1 != num1){
                    continue;
                }

                repp(l,-3,4){
                    repp(m,-3,4){
                        rep(n,4){
                            string boxB[4] = {"....","....","....","...."};
                            ll count2 = 0;
                            rep(t,4){
                                rep(y,4){
                                    if(t+l>3||t+l<0||y+m>3||y+m<0){
                                        boxB[t][y] = '.';
                                        continue;
                                    }
                                    boxB[t][y] = pol[1][t+l][n][y+m];
                                    if(boxB[t][y] == '#'){
                                        count2++;
                                    }
                                }
                            }
                            if(count2 != num2){
                                continue;
                            }
                            repp(o,-3,4){
                                repp(p,-3,4){
                                    rep(q,4){
                                        string boxC[4] = {"....","....","....","...."};
                                        ll count3 = 0;
                                        rep(t,4){
                                            rep(y,4){
                                                if(t+o>3||t+o<0||y+p>3||y+p<0){
                                                    boxC[t][y] = '.';
                                                    continue;
                                                }
                                                boxC[t][y] = pol[2][t+o][q][y+p];
                                                if(boxC[t][y] == '#'){
                                                    count3++;
                                                }
                                            }
                                        }
                                        if(count3 != num3){
                                            continue;
                                        }
                                        string finalB[4] = {"....","....","....","...."};
                                        bool success = true;
                                        rep(r,4){
                                            rep(s,4){
                                                if(finalB[r][s] == '#' && boxA[r][s] == '#'){
                                                    success = false;
                                                }
                                                if(finalB[r][s] == '.' && boxA[r][s] == '#'){
                                                    finalB[r][s] = '#';
                                                }
                                                if(finalB[r][s] == '#' && boxB[r][s] == '#'){
                                                    success = false;
                                                }
                                                if(finalB[r][s] == '.' && boxB[r][s] == '#'){
                                                    finalB[r][s] = '#';
                                                }
                                                if(finalB[r][s] == '#' && boxC[r][s] == '#'){
                                                    success = false;
                                                }
                                                if(finalB[r][s] == '.' && boxC[r][s] == '#'){
                                                    finalB[r][s] = '#';
                                                }
                                            }
                                        }
                                        ll counter = 0;
                                        rep(r,4){
                                            rep(s,4){
                                                if(finalB[r][s] == '#'){
                                                    counter++;
                                                }
                                            }
                                        }
                                        if(counter==16&&success){
                                            cout << "Yes" << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}