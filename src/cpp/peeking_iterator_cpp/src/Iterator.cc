#include "Iterator.h"

int Iterator::next() {
    return *data++;
}

bool Iterator::hasNext() const {
    return data != end;
}
