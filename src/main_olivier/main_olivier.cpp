//
// Created by axel_ on 31/05/2020.
//
#include <Sequence.h>
#include <SequenceD.h>
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c
int main(){

    SequenceD<64> seqD64;

    for(int i= 0; i<seqD64.size();i+=8){
        Sequence sequence = seqD64.sous_sequence(i,i+8);
        std::string contseq = sequence.to_string();
        char val= strtol(contseq.c_str(),0,2); //*stringToChar(contseq);
        cout<<val;
    }


    /*
    SequenceD<64> sequence;

    Sequence sequence1 = sequence.sous_sequence(32,40);

    cout<<sequence.to_string()<<endl;
    cout<<sequence1.to_string()<<endl;
*/
    return 0;


}
