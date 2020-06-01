#include <iostream>
//Commentaire
#include <Sequence.h>
#include <SequenceD.h>
#include <time.h>
#include <cstring>

using namespace std;

void afficher(deque<int> deque){
    for(int i = 0; i < deque.size(); i++){
        cout<< deque[i];
    }
    cout<<endl;
}


int main() {
    char* value;
    SequenceD<64> sequenceD;
    cin>>sequenceD;
    cout<<sequenceD.to_string()<<endl;
    return 0;
}


