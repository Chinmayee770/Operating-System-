#include<stdio.h>

#define MAX_FRAMES 3

void printFrames(int frames[], int n){
    for(int i = 0; i < n; i++){
        if(frames[i] == -1){
            printf("Empty ");
        }else{
            printf("%d ", frames[i]);
        }
    }
    printf("\n");
}

int isPageInFrames(int frames[], int n, int page){
    for(int i = 0; i < n; i++){
        if(frames[i] == page){
            return 1;
        }
    }
    return 0;
}

int getLRUIndex(int counter[], int n){
    int min = counter[0];
    int index = 0;

    for(int i = 1; i < n; i++){
        if(counter[i] < min){
            min = counter[i];
            index = i;
        }
    }

    return index;
}

void lruPageReplacement(int pages[], int numPages){
    int frames[MAX_FRAMES];
    int counter[MAX_FRAMES];

    for(int i = 0; i < MAX_FRAMES; i++){
        frames[i] = -1;
        counter[i] = 0;
    }

    int pageFaults = 0;

    for(int i = 0; i < numPages; i++){
        printf("Page %d: ", pages[i]);
        printFrames(frames, MAX_FRAMES);

        if(!isPageInFrames(frames, MAX_FRAMES, pages[i])){
            int lruIndex = getLRUIndex(counter, MAX_FRAMES);
            frames[lruIndex] = pages[i];
            counter[lruIndex] = 0;
            pageFaults++;
        }

        for(int j = 0; j < MAX_FRAMES; j++){
            if(frames[j] != -1){
                counter[j]++;
            }
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main(){
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int numPages = sizeof(pages) / sizeof(pages[0]);

    lruPageReplacement(pages, numPages);

    return 0;
}
