//
// Created by Михаил on 2019-03-07.
//

#ifndef PARTICLEDISTINGUISHER_FILTERAPPLIER_H
#define PARTICLEDISTINGUISHER_FILTERAPPLIER_H


#include <opencv2/core/core.hpp>
#include "Filter.h"
#include <vector>
#include <map>
#include "TYPES.h"

namespace mbtsky {
    using namespace mbtsky;

    class FilterApplier {
        //*********************************************************************
        // filters is used for storing filters =)
        //*********************************************************************
        std::vector<Filter*> filters;

    public:
        //*********************************************************************
        // Default constructor
        //*********************************************************************
        FilterApplier() = default;

        //*********************************************************************
        // Copy constructor
        //*********************************************************************
        FilterApplier(FilterApplier&filterApplier) {
                filters = filterApplier.filters;
        }

        //*********************************************************************
        // applyFilters
        // @param source - source image
        // @param output - image used for storing result
        // can be the same image.
        //*********************************************************************
        void applyFilters(const cv::Mat & source, cv::Mat &output);

        //*********************************************************************
        // addFilter
        // @param filter
        // append filter for processing
        //*********************************************************************
        void addFilter(Filter *filter);

        //*********************************************************************
        // addFilters
        // @param filters - array of filters
        // append several filters
        //*********************************************************************
        void addFilters(std::vector<Filter *>filters);

        //*********************************************************************
        // deleteFilter
        // @param filter - filter to be removed from filter list
        // delete specified filter
        // @return - returns true on success
        //*********************************************************************
        bool deleteFilter(Filter *filter);

        //*********************************************************************
        // reset
        // remove all stored filters
        //*********************************************************************
        void reset();
    };
}

#endif //PARTICLEDISTINGUISHER_FILTERAPPLIER_H
