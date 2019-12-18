#pragma once

#include "test_runner.h"

#include <vector>
#include <iterator_range.h>

using namespace std;

template <typename Iterator>
class Paginator {
public:
  Paginator(Iterator begin, Iterator end, size_t page_size)
  : first(begin)
  , last(end)
  {
    IteratorRange<Iterator> containerRange(begin, end);
    size_t pagesCount = containerRange.size() / page_size;
    Iterator iter = begin;
    Iterator nextIter;
    while(pagesCount--) {
      nextIter = next(iter, page_size);
      IteratorRange<Iterator> pageRange(iter, nextIter);
      pages.push_back(pageRange);
      iter = nextIter;
    }
    size_t tail = containerRange.size() % page_size;
    if(tail != 0) {
      pages.push_back({iter, next(iter, tail)});
    }
  }

  size_t size() const {
    return pages.size();
  }

  const auto begin() const {
    return pages.begin();
  }

  const auto end() const {
    return pages.end();
  }

private:
  vector<IteratorRange<Iterator>> pages;
  Iterator first;
  Iterator last;
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
  return Paginator(c.begin(), c.end(), page_size);
}