//
// Created by axel_ on 01/06/2020.
//

#include <include/gtest/gtest.h>
#include <test.h>
#include <SequenceD.h>
#include <Permutation.h>
#include <KeyGen.h>

using namespace std;
/**
 *
 * Contient un ensemble tests basique pour nos fonctions (certains test sont des affichages)
 *  TEST Permutation
 *
 */
TEST(test_permetation,basic_test){
    SequenceD<64> sequenceD;
    for(int i=1 ; i < 65; i++){
        sequenceD[i-1] = i;
    }

    Permutation<64,56> perm;

    SequenceD<56> sequence = perm(sequenceD,PC1);

    cout<<sequence.to_string()<<endl;
}