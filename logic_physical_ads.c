#include<stdio.h>
#include<stdlib.h>

#define PAGE_SIZE 4096
#define PAGE_TABLE_SIZE 256

typedef struct{
    int frameNumber;
    int valid;
} PageTableEntry;

int translateAddress(PageTableEntry pageTable[], int logicalAddress) {
    int pageNumber = logicalAddress / PAGE_SIZE;
    int offset = logicalAddress % PAGE_SIZE;

    if (pageTable[pageNumber].valid) {
        int frameNumber = pageTable[pageNumber].frameNumber;
        int physicalAddress = frameNumber * PAGE_SIZE + offset;
        return physicalAddress;
    } else {
        printf("Page Fault! Accessing invalid page: %d\n", pageNumber);
        return -1;
    }
}

int main() {
    PageTableEntry pageTable[PAGE_TABLE_SIZE];

    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        pageTable[i].frameNumber = i;
        pageTable[i].valid = 1;
    }

    int logicalAddress = 8192;
    int physicalAddress = translateAddress(pageTable, logicalAddress);

    if (physicalAddress != -1) {
        printf("Logical Address: %d\n", logicalAddress);
        printf("Physical Address: %d\n", physicalAddress);
    }

    return 0;
}
