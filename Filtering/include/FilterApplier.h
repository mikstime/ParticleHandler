//
// Created by Михаил on 2019-03-07.
//

#ifndef PARTICLEDISTINGUISHER_FILTERAPPLIER_H
#define PARTICLEDISTINGUISHER_FILTERAPPLIER_H


#include "opencv2/core/mat.hpp"
#include "Filter.h"
#include <map>
#include "TYPES.h"

class FilterApplier {
    std::vector<Filter*> filters;
public:
    void setFilter(Filter*);
    void addFilter(Filter*);
    void addFilters(std::vector<Filter*>);
    int deleteFilter(Filter*);
    void deleteFilters();

    cv::Mat applyFilters(cv::Mat);

    void reset();
};


#endif //PARTICLEDISTINGUISHER_FILTERAPPLIER_H
