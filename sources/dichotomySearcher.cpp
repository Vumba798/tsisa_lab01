#include <dichotomySearcher.hpp>
#include <utility>
#include <iomanip>
#include <iostream>

using std::endl;
using std::cin;
using std::cout;
using std::setfill;
using std::setw;
using std::right;
using std::setprecision;

std::vector<Result> DichotomySearcher::search() const{
    float l;
    float intervalFirst = _interval.first;
    float intervalSecond = _interval.second;

    std::vector<Result> resultVec;
    size_t stepNum = 1;
    do{
        l = intervalSecond - intervalFirst;
        float x1 = intervalFirst + l/2 - _delta;
        float x2 = intervalFirst + l/2 + _delta;
        float fx1 = _func(x1);
        float fx2 = _func(x2);

        resultVec.emplace_back(Result(
                    intervalFirst, intervalSecond,
                    x1, x2,
                    fx1, fx2,
                    l, stepNum));

        if (fx1 < fx2){
            intervalSecond = x2;
        }else{
            intervalFirst = x1;
        }

        ++stepNum;

    } while (l > _epsilon);

    return resultVec;
}

void DichotomySearcher::print() const{
    auto resultVec = search();

    cout << "| Left bound | Right bound |"
        <<"     x1     |     x2     |    f(x1)    |" <<
        "    f(x2)    |  length  | step Number |\n";
    cout << "|" << setfill('-') << setw(107) << right << "|\n";
    for (size_t i = 0; i < resultVec.size(); ++i){
        cout << setfill(' ');
        cout << "| " << setw(10) << setprecision(6) << resultVec[i].intervalFirst << " | " <<
            setw(11) << setprecision(6) << resultVec[i].intervalSecond << " | " <<
            setw(10) << setprecision(4) << resultVec[i].X1 << " | " <<
            setw(10) << resultVec[i].X2 << " | " <<
            setw(11) << setprecision(5) << resultVec[i].functionX1 << " | " <<
            setw(11) << resultVec[i].functionX2 << " | " <<
            setw(8) << setprecision(5) << resultVec[i].length << " | " <<
            setw(11) << resultVec[i].stepNum << " |\n";
    cout << "|" << setfill('-') << setw(107) << right << "|\n";
    }
}
