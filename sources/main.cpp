#include <iostream>
#include <string>
#include <passiveSearcher.hpp>
#include <dichotomySearcher.hpp>

using std::endl;
using std::cout;
using std::cin;

int main(int argc, char** argv){
    cout << "The function is: func(x) = -0.5*cos(0.5x) - 0.5" << endl << endl;
    cout << endl << "\t\t\tPASSIVE SEARCHER" << endl;
    cout << "===========================================================" << endl;
    PassiveSearcher ps(1, 4);
    ps.print();

    cout << endl << endl << endl << "\t\t\t\t\tDICHOTOMY SEARCHER" << endl;
    cout << "========================================================";
    cout << "===================================================" << endl;
    DichotomySearcher ds(1, 4);
    ds.print();
    return 0;
}
