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
void FilterApplier::deleteFilters() {
    // Remove all filters
    filters.clear();
}
void FilterApplier::setFilter(Filter *filter_) {
    // Delete all filters and add specific one
    deleteFilters();
    addFilter(filter_);
}
void FilterApplier::addFilters(std::vector<Filter *> filters_) {
    // Concat two vectors
    for(Filter* filter : filters_)
        addFilter(filter);
}

cv::Mat FilterApplier::applyFilters(cv::Mat image_) {
    // If filter has an atomic operation use it
    // If not just apply it
    std::vector<Filter*> AtomicFilters;
    std::vector<Filter*> OrdinaryFilters;
    // Set image for each filter and split filters
    for(Filter* filter : filters) {
        filter->setImage(&image_);
        if(filter->hasAtomic())
            AtomicFilters.push_back(filter);
        else
            OrdinaryFilters.push_back(filter);
    }
    // apply atomic filters
    if(!AtomicFilters.empty()) {
        image_.forEach<Pixel>(
                [&](Pixel& pixel, const int* position) -> void {
                    for(Filter* filter : AtomicFilters) {
                        filter->applyAtomic(pixel, position);

                    }
                }
        );
    }
    // Apply ordinary filters
    for(Filter* filter : OrdinaryFilters) {
        filter->apply();
        image_ = *filter->getResult();
    }
    // return the result
    return image_;
}
void FilterApplier::reset() {
    // remove all filters
    filters.clear();
}