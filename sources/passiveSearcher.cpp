#include <passiveSearcher.hpp>
#include <algorithm>
#include <iomanip>
#include <iostream>


using std::endl;
using std::cout;
using std::setw;
using std::setfill;

std::vector<std::pair<float, float>> PassiveSearcher::search() const{
    float l;
    size_t N = 1;

    // first is a value, second is an _interval of uncertainty
    std::vector<std::pair<float, float>> minElementVec;

    do{
        l = 2.0 / (N+1) * (_interval.second-_interval.first);
        std::vector<float> tmpVec;
        for (size_t k = 1; k <= N; ++k){
            float x = static_cast<float>(k)/(N+1) * (_interval.second-_interval.first) + _interval.first;
            tmpVec.emplace_back(_func(x));
        }
        float min = *std::min_element(tmpVec.begin(), tmpVec.end());
        minElementVec.emplace_back(std::make_pair(min, l)); 

        ++N;
    } while (l > _epsilon);

    return minElementVec;
}

void PassiveSearcher::print() const{
    auto vec = search();
    cout << "| Amount of points | " << "Minimal value" << " | " <<
        setw(6) << "Uncertainty interval |\n";
    cout << "|" << setfill('-') << setw(57) << "" <<  "|" << endl;
    for (size_t i = 0; i < vec.size(); ++i){
        cout << setfill(' ') << setw(0);
        cout << "| " << setw(16) << i + 1 << " | " <<
           setw(13) <<  vec[i].first << " | " <<
           setw(20) << vec[i].second << " |\n";
    }
    cout << "|" << setfill('-') << setw(57) << "" <<  "|" << endl;
}
