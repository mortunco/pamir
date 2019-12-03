//
// Created by fkaraoglanoglu on 2019-12-03.
//

#ifndef PAMIR_STATS_H
#define PAMIR_STATS_H
#include <utility>
#include <cmath>
#include <numeric>
#include <iterator>

template< class ITER>
static inline std::pair<double, double> get_distribution(ITER first, ITER last){
    double mean = 0;
    size_t count = std::distance(first,last);
    long long sum = 0;
    sum = std::accumulate(first,last,sum);
    mean = static_cast<double>(sum) / count;

    double variance = 0;
    for( auto iter = first; iter != last; ++iter){
        variance = variance + ((*iter - mean) * (*iter - mean));
    }
    variance = variance / count;

    return std::make_pair( mean, std::sqrt(variance));
}

#endif //PAMIR_STATS_H
