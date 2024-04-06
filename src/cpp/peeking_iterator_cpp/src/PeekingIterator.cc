#include "PeekingIterator.h"

int PeekingIterator::peek() {
    return Iterator(*this).next();
}
