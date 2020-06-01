//
// Created by axel_ on 01/06/2020.
//

#include "NonMember.h"

//https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c
const char* stringToChar(std::string data){
    std::stringstream sstream(data);
    char c;
    std::string output;
    while(sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        c = char(bits.to_ulong());
        output+=c;
    }
    return output.c_str();
}

std::ostream& operator<<(std::ostream& out,SequenceD<64> seqD64)
{
    for(int i=0;i<64;i+=8)
    {
        Sequence sequence = seqD64.sous_sequence(i,i+8);
         std::string contseq = sequence.to_string();
        char val= *stringToChar(contseq);
        out<<  val;

    }
    return out;
}


