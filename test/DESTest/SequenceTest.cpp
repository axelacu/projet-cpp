//
// Created by axel_ on 31/05/2020.
//

#include <include/gtest/gtest.h>
#include <test.h>
#include <Sequence.h>
#include <list>

using namespace std;
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
    sequence2[3]=0;
    std::cout<< "Seq2 after : " << sequence2.to_string() <<std::endl;
    ASSERT_EQ(sequence2[3],0);
    ASSERT_EQ(sequence2(3),0);

    //test que des 0
    std::cout<< "Test du [] " <<std::endl;
    std::cout<< "Seq2 before : " << sequence2.to_string() <<std::endl;
    for(int i = 0; i<sequence2.size();i++){
        sequence2[i] = 0;
    }
    std::cout<< "Seq2 after : " << sequence2.to_string() <<std::endl;
    ASSERT_EQ(sequence2.to_string(),"0000");

}

TEST(operateur_egale,basic_test){
    Sequence sequence1;

    std::cout<< "Test du operateur= " <<std::endl;
    std::cout<< "Seq1 before : " << sequence1.to_string() <<std::endl;
    sequence1=10;
    std::cout<< "Seq1 before : " << sequence1.to_string() <<std::endl;
    std::string valtest = "1010";
    std::cout<< "resultat attendu : " << valtest <<std::endl;

    ASSERT_EQ(valtest,sequence1.to_string());
}

TEST(basic_decalage,basic_test){

    Sequence sequence1;
    Sequence seq_attendu;
    int val1 = sequence1(0);
    int val2 = sequence1(1);
    int val3 = sequence1(2);
    int val4 = sequence1(3);

    seq_attendu[0] = val2;
    seq_attendu[1] = val3;
    seq_attendu[2] = val4;
    seq_attendu[3] = val1;

    sequence1.decalage(1);

    ASSERT_EQ(sequence1.to_string(),seq_attendu.to_string());

}

TEST(operator_etoile,basic_test){
    Sequence sequence1;
    Sequence sequence2;

    cout<< "Sequence 1 : " << sequence1.to_string()<<endl;
    cout<< "Sequence 2 : " << sequence2.to_string()<<endl;
    Sequence sequence3 = sequence1*sequence2;
    cout<< "Sequence 3 : " << (sequence3).to_string()<<endl;

    for(int i = 0 ; i < sequence1.size();i++){
        bool bit_s1_val = sequence1(i);
        bool bit_s2_val = sequence2(i);
        ASSERT_EQ(!bit_s1_val != !bit_s2_val,sequence3(i));
    }

}

TEST(basic_permute,basic_test){
    Sequence sequence;
    sequence[0] = 1;
    sequence[1] = 1;
    sequence[2] = 0;
    sequence[3] = 0;
    cout<<"valeur de la sequence : " << sequence.to_string() << endl;
    vector<int> vect = {0,3,2,1};
    Sequence seq_permute = sequence.permutation(vect);
    cout<<"valeur de seq_permut " << seq_permute.to_string() << endl;

    ASSERT_EQ("1001",seq_permute.to_string());
}

TEST(basic_sousseq,basic_test){
    Sequence sequence;
    sequence[0] = 1;
    sequence[1] = 1;
    sequence[2] = 0;
    sequence[3] = 0;
    cout<<"affichage seq 1 " << sequence.to_string()<< endl;

    Sequence sequence_res   = sequence.sous_sequence(1,4);
    cout<<"affichage nouvelle sequence " << sequence_res.to_string()<< endl;

    ASSERT_EQ(sequence_res.to_string(),"100");
}