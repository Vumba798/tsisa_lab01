#ifndef INCLUDE_SEARCHER_HPP
#define INCLUDE_SEARCHER_HPP

#include <algorithm>
#include <cmath>
#include <utility>
#include <stdexcept>


class Searcher{
protected:
    float _epsilon = 0.1;
    std::pair<float,float> _interval;

    inline float _func(const float &x) const noexcept{
        return -0.5 * std::cos(0.5 * x) - 0.5;
    }

public:
    inline Searcher(const float &a, const float &b){
        if(a >= b){
            throw std::invalid_argument("a must be less than b");
        }
        _interval = std::make_pair(a,b);
    };
    virtual void print() const = 0;
};

#endif // INCLUDE_SEARCHER_HPP

