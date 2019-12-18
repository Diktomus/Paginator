#pragma once

#include "iterator_range.h"

template<typename It>
struct IteratorRange {
  IteratorRange(It begin, It end)
  : first(begin)
  , last(end)
  {
  }
  It first, last;

  It begin() const {
    return first;
  }

  It end() const {
    return last;
  }

  size_t size() const {
    size_t count = 0;
    for(It iter = first; iter != last; iter++) {
      count++;
    }
    return count;
  }
};

template<typename I>
auto makeRange(I begin, I end)
{
  return IteratorRange<I>(begin, end);
}