//
// Created by axel_ on 31/05/2020.
//
#include <Sequence.h>

using namespace std;

int main(){
    Sequence sequence1;

    cout<< "seq 1 : " <<sequence1.to_string()<<endl;

    int val1 = sequence1(0);
    int val2 = sequence1(1);
    int val3 = sequence1(2);
    int val4 = sequence1(3);

    sequence1[0] = val2;
    sequence1[1] = val3;
    sequence1[2] = val4;
    sequence1[3] = val1;

    cout<<  "seq 2 : " << sequence1.to_string()<<endl;

    rotate(ve.begin(), ve.begin()+pas, ve.end());
    return 0;
}
