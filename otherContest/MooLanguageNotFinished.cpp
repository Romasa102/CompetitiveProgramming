#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
bool longSentence2Left = true;
ll nounUsed = 0;
ll transitiveUsed = 0;
ll intransitiveUsed = 0;
ll conjuctionUsed = 0;
string noun[10000];
string transitive[10000];
string intransitive[10000];
string conjunctions[10000];
ll longestSentenceTwoSize;
void printSentenceA(){
    cout << noun[nounUsed] << " " << intransitive[intransitiveUsed];
    nounUsed++;
    intransitiveUsed++;
    return;
}
void printSentenceB(){
    cout << noun[nounUsed] << " " << transitive[transitiveUsed] << " " << noun[nounUsed];
    nounUsed+=2;
    transitiveUsed++;
    if(longSentence2Left){
        rep(i,longestSentenceTwoSize){
            cout << ", " << noun[nounUsed];
            nounUsed++;
        }
    }
    return;
}
int main(){
    ll T;
    cin >> T;
    rep(i,T){
                
        nounUsed = 0;
        transitiveUsed = 0;
        intransitiveUsed = 0;
        conjuctionUsed = 0;
        //get the imput
        ll N,C,Pi;
        cin >> N >> C >> Pi;
        ll nounCount = 0;
        ll transitiveCount = 0;
        ll intransitiveCount = 0;
        ll conjunctionCount = 0;
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
                conjunctions[conjunctionCount] = cash;
                conjunctionCount++;
            }
        }

        //Get the number of Type1 and Type2
        ll sentenceSize = 0;
        ll SentenceOne = 0;
        ll SentenceTwo = 0;
        ll maxSize = 0;
        ll ConjuctionUse = min(conjunctionCount,C);
        ll maxSentenceCount = Pi + ConjuctionUse;
        ll conjuctionF = 0;

        rep(i,intransitiveCount){
            rep(j,transitiveCount){
                if(i+j <= maxSentenceCount && i+j*2 <= nounCount) {
                    ll cashC = C;
                    ll wordCount = i*2+j*3;
                    ll conjuctionCanUse = min(conjunctionCount,(i+j)/2);
                    wordCount += conjuctionCanUse;
                    cashC -= conjuctionCanUse;
                    int ccount = 0;
                    if(j >= 1) {
                        ccount = min(cashC,nounCount-i-j*2);
                        wordCount += ccount;
                    }
                    if(wordCount > maxSize) {
                        maxSize = wordCount;
                        SentenceOne = i;
                        SentenceTwo = j;
                        longestSentenceTwoSize = ccount;
                        conjuctionF = conjuctionCanUse;
                    }
                }
            }
        }

        cout << maxSize << endl;
        
        //print one of the sentence
        ll sentenceOneSentenceOne = 0;
        ll sentenceOneSentenceTwo = 0;
        ll sentenceTwoSentenceTwo = 0;
        if(SentenceOne/2 > conjuctionF){
            conjuctionF = 0;
            SentenceOne -= conjuctionF*2;
        }else{
            conjuctionF - SentenceOne/2;
            SentenceOne%=2;
        }
        if(SentenceOne==1&&SentenceTwo!=0&&conjuctionF!=0){
            sentenceOneSentenceTwo =1;
            SentenceOne-=1;
            SentenceTwo-=1;
            conjuctionF-=1;
        }
        sentenceTwoSentenceTwo=conjuctionF;
        rep(i,SentenceOne){
            printSentenceA();
            cout << ". ";
        }
        rep(i,SentenceTwo){
            printSentenceB();
            cout << ". ";
        }
        rep(i,sentenceOneSentenceOne){
            printSentenceA();
            cout << " " << conjunctions[conjuctionUsed] << " ";
            printSentenceA();
            conjuctionUsed++;
            cout << ". ";
        }
        rep(i,sentenceOneSentenceTwo){
            printSentenceA();
            cout << " " << conjunctions[conjuctionUsed] << " ";
            printSentenceB();
            cout << ". ";
            conjuctionUsed++;
        }
        rep(i,sentenceTwoSentenceTwo){
            printSentenceB();
            cout << " " << conjunctions[conjuctionUsed] << " ";
            printSentenceB();
            conjuctionUsed++;
        }
    }
}