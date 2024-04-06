#include "Iterator.h"

int Iterator::next() {
    return data[index++];
}

bool Iterator::hasNext() const {
    return data.size() < index;
}
