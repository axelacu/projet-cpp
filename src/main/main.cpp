#include <iostream>
//Commentaire
#include <Sequence.h>
#include <SequenceD.h>
#include <time.h>
#include <cstring>
#include <KeyGen.h>

using namespace std;

int main() {
    /**
     * Génaration de 16 clés à partir d'une clé random
     */
    SequenceD<64> sequenceD;

    KeyGen keyGen(sequenceD);

    for(int i = 0; i<16;i++){
        cout<<"Cle " << i << "\t" << keyGen.next().to_string() <<endl;
    }


    /**
     * test write - read
     */
     /*
    write(cout,sequenceD);
    cout<<endl;
    //1100100000111111101010010010011010101110110110111010011111100111

    read(cin,sequenceD);

    cout<<sequenceD.to_string()<<endl;

      */

     /**
      * test cin
      */
    /*
    char* value;
    SequenceD<64> sequenceD;
    cin>>sequenceD;
    cout<<sequenceD.to_string()<<endl;

     */
    //0110000101100001011000010110000101100001011000010110000101100001
}


