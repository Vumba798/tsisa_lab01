#ifndef INCLUDE_PASSIVESEARCHER_HPP_
#define INCLUDE_PASSIVESEARHCER_HPP_
#include <searcher.hpp>
#include <vector>

class PassiveSearcher : public Searcher{
public:
    inline PassiveSearcher(float a, float b) : Searcher(a, b) {};
    std::vector<std::pair<float, float>> search() const;
    void print() const override final;
};

#endif // INCLUDE_PASSIVESEARHCER_HPP_

