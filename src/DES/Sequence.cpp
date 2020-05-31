
// Created by axel_ on 13/05/2020.
#include <iostream>
#include <vector>
#include <initializer_list>
#include <Sequence.h>

using namespace std;

Sequence::Sequence(int taille)
{//Attribution aléatoire de valeurs booléenneà la liste
    for(int i=0;i<taille;i++){
        sequence_left.push_back(rand()%2);
    }
}
//[s1,s2,s3]
//[1001,1011,0101]
Sequence::Sequence(std::list<Sequence> sequences_list) {
    taille=0;

    for(list<Sequence>::iterator it = sequences_list.begin(); it != sequences_list.end(); it++){
        int size = it->size();
        //Ajout des valeurs de chaque liste dans une seule et unique liste
        for(int val = 0; val<size;val++){
            int bit = it->operator()(val);
            sequence_left.push_back(bit);
            taille++;
        }

    }
}



