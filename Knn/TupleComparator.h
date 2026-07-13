#ifndef TUPLE_COMPARATOR_H_
#define TUPLE_COMPARATOR_H_

#include <tuple>
#include "InfoVector.h"

struct TupleComparator
{
    // Declare the operator() function. This is the inline function that will be defined in the
    // TupleComparator.cpp file.
    bool operator()(const tuple<double, InfoVector> &a, const tuple<double, InfoVector> &b) const;
};

#endif /* TUPLE_COMPARATOR_H_ */
