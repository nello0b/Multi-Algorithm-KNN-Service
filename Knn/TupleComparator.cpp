#include "TupleComparator.h"
#include <tuple>

bool TupleComparator::operator()(const tuple<double, InfoVector> &a, const tuple<double, InfoVector> &b) const
{
    // Compare the double values in the tuples and return true if the double value in tuple a
    // is less than the double value in tuple b. This will cause the priority queue to sort the
    // tuple objects in ascending order based on the double value in the tuple.
    return get<0>(a) < get<0>(b);
}
