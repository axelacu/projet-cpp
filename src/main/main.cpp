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

    SequenceD<64> sequenceD;

    write(cout,sequenceD);
    cout<<endl;
    //1100100000111111101010010010011010101110110110111010011111100111

    read(cin,sequenceD);

    cout<<sequenceD.to_string()<<endl;
    /*
    char* value;
    SequenceD<64> sequenceD;
    cin>>sequenceD;
    cout<<sequenceD.to_string()<<endl;

     */
    //0110000101100001011000010110000101100001011000010110000101100001
}


