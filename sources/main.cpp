#include <iostream>
#include <string>
#include <passiveSearcher.hpp>
#include <dichotomySearcher.hpp>

using std::endl;
using std::cout;
using std::cin;

int main(int argc, char** argv){
    PassiveSearcher ps(1, 4);
    ps.print();

    DichotomySearcher ds(1, 4);
    ds.print();
    return 0;
}
