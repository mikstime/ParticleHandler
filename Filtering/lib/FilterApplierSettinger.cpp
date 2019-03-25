//
// Created by Михаил on 2019-03-25.
//

#include "FilterApplierSettinger.h"
void FilterApplierSettinger::addFilter(FilterApplier * filterApplier, Filter *filter) {
    filterApplier->addFilter(filter);
}
void FilterApplierSettinger::setFilter(FilterApplier *filterApplier, Filter *filter) {
    filterApplier->setFilter(filter);
}
void FilterApplierSettinger::addFilters(FilterApplier *filterApplier, std::vector<Filter *>filters) {
    filterApplier->addFilters(filters);
}
void FilterApplierSettinger::deleteFilters(FilterApplier * filterApplier) {
    filterApplier->deleteFilters();
}
int FilterApplierSettinger::deleteFilter(FilterApplier *filterApplier, Filter *filter) {
    return filterApplier->deleteFilter(filter);
}