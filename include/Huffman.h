#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @file huffman.c
 * @brief Implementation of Huffman coding using a min-heap.
 */

/**
 * @struct MinHeapNode
 * @brief Represents a node in the min-heap.
 */
typedef struct MinHeapNode
{
    char data;                      ///< The data stored in the node.
    unsigned freq;                  ///< The frequency of the data.
    struct MinHeapNode *left;       ///< Pointer to the left child node.
    struct MinHeapNode *right;      ///< Pointer to the right child node.
} MinHeapNode;

/**
 * @struct MinHeap
 * @brief Represents a min-heap.
 */
typedef struct MinHeap
{
    unsigned size;                  ///< The current size of the heap.
    unsigned capacity;              ///< The maximum capacity of the heap.
    MinHeapNode **array;            ///< The array representing the heap.
} MinHeap;

/**
 * @brief Creates a new node with the given data and frequency.
 *
 * @data The data to store in the node.
 * @freq The frequency of the data.
 * @return A pointer to the newly created node.
 */
MinHeapNode* newNode(char data, unsigned freq)
{
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

/**
 * @brief Creates a new MinHeap with the given capacity.
 *
 * @capacity The capacity of the MinHeap.
 * @return A pointer to the newly created MinHeap.
 */
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void encoding(const char *inputfilename,const char *outputfilename);
void decodefile(const char *inputfilename, const char *outputfilename);
void countfrequency(const char *data,int *arr)


#endif // HUFFMAN_H
