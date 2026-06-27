#include <stdio.h>
#include <stdlib.h>

#define MAX_EVENTS 100000

// Function to compare two events for sorting
int compareEvents(const void* a, const void* b) {
    const int* eventA = *(const int**)a;
    const int* eventB = *(const int**)b;
    if (eventA[0] != eventB[0])
        return eventA[0] - eventB[0]; // Sort by start day
    return eventA[1] - eventB[1];     // If start days are equal, sort by end day
}

// Min-heap utility functions
void heapifyUp(int* heap, int size) {
    int i = size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i])
            break;
        // Swap parent and child
        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;
        i = parent;
    }
}

void heapifyDown(int* heap, int size) {
    int i = 0;
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        // Swap parent with smallest child
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        i = smallest;
    }
}

void pushHeap(int* heap, int* size, int value) {
    heap[(*size)++] = value;
    heapifyUp(heap, *size);
}

int popHeap(int* heap, int* size) {
    int top = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size);
    return top;
}

int maxEvents(int events[][2], int eventsSize) {
    int ans = 0;
    int d = 0;  // The current day
    int i = 0;  // Events' index
    int minHeap[MAX_EVENTS];
    int heapSize = 0;

    // Convert the array of arrays into a sortable array of pointers
    int* eventPtrs[MAX_EVENTS];
    for (int j = 0; j < eventsSize; ++j)
        eventPtrs[j] = events[j];

    // Sort events by start day
    qsort(eventPtrs, eventsSize, sizeof(int*), compareEvents);

    while (heapSize > 0 || i < eventsSize) {
        // If no events are available to attend today, move to the next event's start day
        if (heapSize == 0)
            d = eventPtrs[i][0];

        // Push all events that start today into the heap
        while (i < eventsSize && eventPtrs[i][0] == d)
            pushHeap(minHeap, &heapSize, eventPtrs[i++][1]);

        // Attend the event that ends the earliest
        popHeap(minHeap, &heapSize);
        ++ans;
        ++d;

        // Remove events that have already ended
        while (heapSize > 0 && minHeap[0] < d)
            popHeap(minHeap, &heapSize);
    }

    return ans;
}

int main() {
    int events[][2] = {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    int eventsSize = sizeof(events) / sizeof(events[0]);

    int result = maxEvents(events, eventsSize);
    printf("Maximum number of events attended: %d\n", result);

    return 0;
}
