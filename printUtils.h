//
// Created by Christian Ledgard on 21/06/21.
//

#ifndef LAB5_PRINTUTILS_H
#define LAB5_PRINTUTILS_H

#include <iomanip>

const char separator    = ' ';
const int nameWidth     = 20;
const int numWidth      = 8;

template<typename T> void printElem(T t, const int& width)
{
    cout << left << setw(width) << setfill(separator) << t;
}


#endif //LAB5_PRINTUTILS_H
