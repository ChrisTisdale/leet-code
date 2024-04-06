#include "PeekingIterator.h"

int PeekingIterator::peek() {
    if (!hasPeeked) {
        hasPeeked = true;
        value = Iterator::next();
    }

    return value;
}

int PeekingIterator::next() {
    if (hasPeeked) {
        hasPeeked = false;
        return value;
    }

    return Iterator::next();
}

bool PeekingIterator::hasNext() const {
    return Iterator::hasNext() || hasPeeked;
}
