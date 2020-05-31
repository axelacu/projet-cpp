#include <iostream>
//Commentaire
#include <Sequence.h>
#include <SequenceD.h>
#include <time.h>

using namespace std;

void afficher(deque<int> deque){
    for(int i = 0; i < deque.size(); i++){
        cout<< deque[i];
    }
    cout<<endl;
}

int main() {
    SequenceD<2> sr;
    cout<<sr.to_string()<<endl;
    afficher(sr.sequence_left);
    afficher(sr.sequence_right.sequence_left);

    return  0;
}


