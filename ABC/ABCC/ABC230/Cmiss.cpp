#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N,A,B;
    cin >> N >> A >> B;
    long long P,Q,R,S;
    cin >> P >> Q >> R >> S;
    long long L = max(1 - A,1 - B);
    long long K = min(N - A,N - B);
    vector<vector<bool>> M(N + 1, vector<bool>(N + 1));
    for (long long i = L; i <= K; i++)
    {
        M.at(A + i).at(B + i) = true;
    }
    long long G = max(1 - A,B - N);
    long long H = min(N - A,B - 1);
    for (int i = G; i <= H; i++)
    {
        M.at(A + i).at(B - i) = true;
    }
    for (long long i = P; i <= Q; i++)
    {
        for (long long j = R; j <= S; j++)
        {
            if(M.at(i).at(j)){
                cout << "#";
            }else{
                cout << ".";
            }
        }
        cout << endl;        
    }
    return(0);   
}