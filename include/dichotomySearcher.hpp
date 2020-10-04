#ifndef INCLUDE_DICHOTOMYSEARCHER_HPP_
#define INCLUDE_DICHOTOMYSEARCHER_HPP_

#include "searcher.hpp"
#include <vector>

struct Result{
    float intervalFirst;
    float intervalSecond;
    float X1;
    float X2;
    float functionX1;
    float functionX2;
    float length;
    size_t stepNum;

    inline Result(
            float interFirst, float interSecond,
            float x1, float x2,
            float funcX1, float funcX2,
            float len, size_t num) :
        intervalFirst(interFirst), intervalSecond(interSecond),
        X1(x1), X2(x2),
        functionX1(funcX1), functionX2(funcX2),
        length(len), stepNum(num) {};
};

class DichotomySearcher : public Searcher{
private:
    float _delta;
public:
    inline DichotomySearcher(const int &a, const int &b) :
        Searcher(a, b),
        _delta(_epsilon / 3.0) {};

    std::vector<Result> search() const;
    void print() const override final;

};

#endif // INCLUDE_DICHOTOMYSEARCHER_HPP_

