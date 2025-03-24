#include<stdio.h>

int isPageInFrames(int page, int frames[], int frameCount){
    for(int i = 0; i < frameCount; i++){
        if(frames[i] == page){
            return 1;
        }
    }
    return 0;
}

int main(){
    int frameCount, pageCount, pageFaults = 0;

    printf("Enter the number of available page frames: ");
    scanf("%d", &frameCount);

    int frames[frameCount];
    int pageQueue[frameCount];
    int front = 0, rear = -1;

    printf("Enter the total number of page references: ");
    scanf("%d", &pageCount);

    printf("Enter the page reference sequence: ");
    for(int i = 0; i < pageCount; i++){
        int page;
        scanf("%d", &page);

        if(!isPageInFrames(page, frames, frameCount)){
            if(rear < frameCount - 1){
                rear++;
            }else{
                front = (front + 1) % frameCount;
            }

            pageQueue[rear] = page;
            frames[(rear - front + frameCount) % frameCount] = page;

            pageFaults++;
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
