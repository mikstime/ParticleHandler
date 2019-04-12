//
// Created by Михаил on 2019-03-07.
//

#include "FilterApplier.h"
#include <opencv2/core/core.hpp>
#include <vector>
#include <iostream>
#include "Filter.h"
#include "TYPES.h"

void FilterApplier::addFilter(Filter * filter) {
    // Add filter to the end of filters
    filters.push_back(filter);
}
int FilterApplier::deleteFilter(Filter *filter_) {
    // Find filter in filters
    int id;
    for(id = 0; id < filters.size(); id++) {
        if(filters[id] == filter_)
            break;
    }
    // If no filter was found return -1
    if(id == filters.size())
        return -1;
    // Otherwise delete it
    for(; id < filters.size() - 1; id++) {
        filters[id] = filters[id + 1];
    }
    filters.pop_back();
    // Return 0 if filter has been deleted
    return 0;
}

void FilterApplier::addFilters(std::vector<Filter *> filters_) {
    // Concat two vectors
    for(Filter* filter : filters_)
        addFilter(filter);
}

void FilterApplier::applyFilters(const cv::Mat & image_, cv::Mat & result) {
    // If filter has an atomic operation use it
    // If not just apply it
    std::vector<Filter*> AtomicFilters;
    std::vector<Filter*> OrdinaryFilters;
    // Set image for each filter and split filters
    cv::Mat imagec(image_);
    for(Filter* filter : filters) {
        filter->setImage(imagec);
        if(filter->hasAtomic())
            AtomicFilters.push_back(filter);
        else
            OrdinaryFilters.push_back(filter);
    }
    // apply atomic filters
    if(!AtomicFilters.empty()) {
        for(Filter* filter : AtomicFilters) {
            imagec.forEach<Pixel>(
                    [&](Pixel& pixel, const int* position) -> void {
                            filter->applyAtomic(pixel, position);

                        }
            );
        }

    }
    // Apply ordinary filters
    for(Filter* filter : OrdinaryFilters) {
        filter->apply();
        imagec = filter->getResult();
    }
    // return the result
    result = imagec;
}
void FilterApplier::reset() {
    // remove all filters
    filters.clear();
}