//
// Created by axel_ on 31/05/2020.
//

#include <include/gtest/gtest.h>
#include <Sequence.h>
#include <SequenceD.h>

using namespace std;
TEST(initialize_seqD,basic_test){
    SequenceD<8> sequenceD;

    ASSERT_EQ(sequenceD.size(),8);
    cout << sequenceD.to_string() << endl;

    cout<<"Seq_droite : " << sequenceD.right().to_string()<<endl;
    cout<<"Seq_gauche : " << sequenceD.left().to_string()<<endl;
}
