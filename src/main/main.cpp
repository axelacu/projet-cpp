#include <iostream>
//Commentaire
#include <Sequence.h>
#include <time.h>

using namespace std;

//http://www.cplusplus.com/forum/general/65862/
const char* Convert(unsigned int val)
{
    std::string binary_string;
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);

    for(int i = 0; i < sizeof(int) * 8; i++)
    {
        if( (val & mask) == 0 )
            binary_string += '0' ;
        else
            binary_string+= '1' ;

        mask  >>= 1;
    }
    return binary_string.c_str();
}

int main() {
    cout<<Convert(1)<<endl;
    return 0;
}
