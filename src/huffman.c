#include "Huffman.h"
#include <stdlib.h>
#include <string.h>


/**
 * Counts the frequency of each character in the input string and stores
 * the frequencies in the provided array.
 *
 * @data The input string whose character frequencies are to be counted.
 * @arr  Pointer to an integer array where frequencies will be stored.
 */
void countfrequency(const char *data,int *arr)
{
    memset(arr , 0 ,sizeof(int) * 256);

    while(*data)
    {
        arr[(unsigned char)*data++];
        *data++;
    }
}