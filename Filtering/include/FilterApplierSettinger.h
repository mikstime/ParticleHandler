//
// Created by Михаил on 2019-03-25.
//

#ifndef PARTICLEHANDLER_FILTERAPPLIERSETTINGER_H
#define PARTICLEHANDLER_FILTERAPPLIERSETTINGER_H


#include "Filter.h"
#include "FilterApplier.h"
#include "Settinger.h"
class FilterApplierSettinger: public Settinger {
    
public:
    void setFilter(FilterApplier*, Filter*);
    void addFilter(FilterApplier*, Filter*);
    void addFilters(FilterApplier*, std::vector<Filter*>);
    int deleteFilter(FilterApplier*, Filter*);
    void deleteFilters(FilterApplier*);
};


#endif //PARTICLEHANDLER_FILTERAPPLIERSETTINGER_H
