//
// Created by axel_ on 31/05/2020.
//

#include <include/gtest/gtest.h>
#include <test.h>
#include <Sequence.h>
#include <list>

TEST(initialize_seq,basic_test){
    Sequence sequence1;
    Sequence sequence2;

    ASSERT_EQ(sequence1.size(),4);
    ASSERT_EQ(sequence2.size(),4);
    std::list<Sequence> list;

    list.push_back(sequence1);
    list.push_back(sequence2);

    Sequence sequence_list(list);
    ASSERT_EQ(sequence_list.size(),sequence1.size() + sequence2.size());

    std::cout<< "Seq 1 : " << sequence1.to_string() <<std::endl;
    std::cout<< "Seq 2 : " << sequence2.to_string() <<std::endl;
    std::cout<< "Seq 3 : " << sequence_list.to_string() <<std::endl;

}

TEST(modif_seq,basic_test){
    Sequence sequence1;
    std::cout<< "Seq1 before : " << sequence1.to_string() <<std::endl;
    sequence1[1]=1;
    std::cout<< "Seq1 after : " << sequence1.to_string() <<std::endl;
    ASSERT_EQ(sequence1[1],1);

    Sequence sequence2;
    std::cout<< "Seq2 before : " << sequence2.to_string() <<std::endl;
    sequence1[3]=0;
    std::cout<< "Seq2 after : " << sequence2.to_string() <<std::endl;
    ASSERT_EQ(sequence2[4],1);
    ASSERT_EQ(sequence2(4),1);

    //test que des 0
    std::cout<< "Test du [] " <<std::endl;
    std::cout<< "Seq2 before : " << sequence2.to_string() <<std::endl;
    for(int i = 0; i<sequence2.size();i++){
        sequence2[i] = 0;
    }
    std::cout<< "Seq2 after : " << sequence2.to_string() <<std::endl;
    ASSERT_EQ(sequence2.to_string(),"0000");

    /*
    std::cout<< "Test du = " <<std::endl;
    std::cout<< "Seq1 before : " << sequence1.to_string() <<std::endl;
    sequence1=1;
    std::cout<< "Seq1 before : " << sequence1.to_string() <<std::endl;
    std::string valtest = "0001";
    std::cout<< "resultat attendu : " << valtest <<std::endl;

    ASSERT_TRUE(valtest==sequence1.to_string());**/

}
