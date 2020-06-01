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

TEST(crochet_seqD, basic_test){
    SequenceD<8> sequence1;

    sequence1[0] = 1;
    sequence1[1] = 1;
    sequence1[2] = 1;
    sequence1[3] = 1;
    sequence1[4] = 0;
    sequence1[5] = 1;
    sequence1[6] = 0;
    sequence1[7] = 1;

    ASSERT_EQ("1111 0101",sequence1.to_string());
    ASSERT_EQ(1,sequence1(1));
}
