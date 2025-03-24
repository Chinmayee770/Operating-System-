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

int getPageIndexToRemove(int pages[], int numPages, int frames[], int numFrames, int currentIndex){
    int result = -1;
    int farthest = currentIndex;
    
    for(int i = 0; i < numFrames; i++){
        int j;
        for(j = currentIndex + 1; j < numPages; j++){
            if(frames[i] == pages[j]){
                if(j > farthest){
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        
        if(j == numPages){
            return i;
        }
    }
    
    return result;
}

void optimalPageReplacement(int pages[], int numPages){
    int frames[MAX_FRAMES];

    for(int i = 0; i < MAX_FRAMES; i++){
        frames[i] = -1;
    }

    int pageFaults = 0;

    for(int i = 0; i < numPages; i++){
        printf("Page %d: ", pages[i]);
        printFrames(frames, MAX_FRAMES);

        if(!isPageInFrames(frames, MAX_FRAMES, pages[i])){
            int indexToRemove = getPageIndexToRemove(pages, numPages, frames, MAX_FRAMES, i);
            frames[indexToRemove] = pages[i];
            pageFaults++;
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main(){
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int numPages = sizeof(pages) / sizeof(pages[0]);

    optimalPageReplacement(pages, numPages);

    return 0;
}
