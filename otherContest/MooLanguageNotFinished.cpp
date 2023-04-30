#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(i,T){
        ll N,C,Pi;
        cin >> N >> C >> Pi;
        string noun[N];
        string transitive[N];
        string intransitive[N];
        string conjunction[N];
        ll nounCount = 0;
        ll transitiveCount = 0;
        ll intransitiveCount = 0;
        ll conjunctionCount = 0;

        //get the imput
        rep(i,N){
            string cash;
            string cash2;
            cin >> cash >> cash2;
            if(cash2 == "noun"){
                noun[nounCount] = cash;
                nounCount++;
            }
            if(cash2 == "transitive-verb"){
                transitive[transitiveCount] = cash;
                transitiveCount++;
            }
            if(cash2 == "intransitive-verb"){
                intransitive[intransitiveCount] = cash;
                intransitiveCount++;
            }
            if(cash2 == "conjunction"){
                conjunction[conjunctionCount] = cash;
                conjunctionCount++;
            }
        }
        cout << "NounCount " << nounCount << "tranisitive-verg" << transitiveCount << "intransndiaverb" << intransitiveCount << "conjuctino" << conjunctionCount << endl;
        ll SentenceOne;
        ll SentenceTwo;
        
        // how many sentence 2 can we make this this value?
        SentenceTwo = min(C,transitiveCount);
        SentenceTwo = min(SentenceTwo,nounCount/2);
        nounCount -= SentenceTwo*2;
        C -= SentenceTwo;
        transitiveCount -= SentenceTwo;

        
        // how many sentence 1 can we make this this value?
        SentenceOne = min(intransitiveCount,nounCount);
        nounCount -= SentenceOne;
        intransitiveCount -= SentenceOne;

        //Consider the conjuction and join as many sentence as possible
        ll SentenceTwoJoin = 0;
        ll sentenceOneTwoJoin = 0;
        ll sentenceOneJoin = 0;
        SentenceTwoJoin = min(SentenceTwo/2,conjunctionCount);
        conjunctionCount - SentenceTwoJoin;
        SentenceTwo -= SentenceTwoJoin*2;
        if(conjunctionCount != 0){
            if(SentenceTwo >= 1 && SentenceOne >= 1){
                sentenceOneTwoJoin = 1;
                SentenceOne -=1;
                SentenceTwo -=1;
            }
            sentenceOneJoin = min(conjunctionCount, SentenceOne/2);
            SentenceOne -= sentenceOneJoin*2;
            conjunctionCount -= sentenceOneJoin;
        }

        //Consider the period limitation
        ll sentenceTwoJoinFinal = 0;
        ll sentenceOneTwoJoinFinal = 0;
        ll sentenceOneJoinFinal = 0;
        ll sentenceTwoFinal = 0;
        ll sentenceOneFinal = 0;
        sentenceTwoJoinFinal = min(SentenceTwoJoin,Pi);
        SentenceTwoJoin -= sentenceTwoJoinFinal;
        Pi -= sentenceTwoJoinFinal;
        sentenceOneTwoJoinFinal = min(sentenceOneTwoJoin,Pi);
        sentenceOneTwoJoin -= sentenceOneTwoJoinFinal;
        Pi -= sentenceOneTwoJoinFinal;
        sentenceOneJoinFinal = min(sentenceOneJoin,Pi);
        sentenceOneJoin -= sentenceOneJoinFinal;
        Pi -= sentenceOneJoinFinal;
        sentenceOneFinal = min(SentenceOne,Pi);
        SentenceOne -= sentenceOneFinal;
        Pi -= sentenceOneFinal;
        sentenceTwoFinal = min(SentenceTwo,Pi);
        SentenceTwo -= sentenceTwoFinal;
        Pi -= sentenceTwoFinal;
        cout << sentenceTwoJoinFinal * 7 + sentenceOneTwoJoinFinal * 6 + sentenceOneJoinFinal * 5 + sentenceTwoFinal * 3 + sentenceOneFinal * 2 << endl;
        
        //print one of the sentence
        ll nounUsed = 0;
        ll transitiveUsed = 0;
        ll intransitiveUsed = 0;
        ll conjuctionUsed = 0;
        rep(i,sentenceOneFinal){
            cout << noun[nounUsed] << " " << intransitive[intransitiveUsed] << ". ";
            nounUsed++;
            intransitiveUsed++;
        }
        rep(i,sentenceTwoFinal){
            cout << noun[nounUsed] << " " << transitive[transitiveUsed] << "" << endl;
        }
    }
}