//
// Created by axel_ on 31/05/2020.
//
#include <Sequence.h>

using namespace std;

int main(){

    Sequence sequence1;

    cout<<"affichage seq 1 " << sequence1.to_string()<< endl;

    Sequence sequence_res   = sequence1.sous_sequence(1,4);
    cout<<"affichage nouvelle sequence " << sequence_res.to_string()<< endl;



    return 0;


}
