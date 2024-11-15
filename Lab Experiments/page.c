#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 50

void fifo(int pages[], int n, int frames);
void lru(int pages[], int n, int frames);
void opt(int pages[], int n, int frames);

int main() {
    int choice, n, frames;
    int pages[MAX_PAGES];
   
    printf("Enter the total number of pages: ");
    scanf("%d", &n);
   
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
   
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
   
    do {
        printf("\nPage Replacement Algorithms\n");
        printf("1. FIFO\n");
        printf("2. LRU\n");
        printf("3. OPT\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
       
        switch (choice) {
            case 1:
                fifo(pages, n, frames);
                break;
            case 2:
                lru(pages, n, frames);
                break;
            case 3:
                opt(pages, n, frames);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
   
    return 0;
}

void fifo(int pages[], int n, int frames) {
    int frame[MAX_FRAMES] = {-1};
    int pageFaults = 0;
    int first = 0, last = 0;
   
    printf("\nPage Replacement Algorithm: FIFO\n");
   
    for (int i = 0; i < n; i++)
     {
        int currentPage = pages[i];
        int found = 0;
        for (int j = 0; j < frames; j++) 
        {
            if (frame[j] == currentPage) 
            {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            frame[last] = currentPage;
            last = (last + 1) % frames;
            pageFaults++;
        }
        printf("Page reference: %d -> [", currentPage);
        for (int j = 0; j < frames; j++) {
            if (frame[j] == -1) {
                printf(" - ");
            } else {
                printf(" %d ", frame[j]);
            }
        }
        printf("] -> ");
        if (found == 0) {
            printf("Page Fault\n");
        } else {
            printf("No Page Fault\n");
        } 
    }
    printf("Total page faults: %d\n", pageFaults);
}

void lru(int pages[], int n, int frames) {
    int frame[MAX_FRAMES] = {-1};
    int pageFaults = 0;
    int used[MAX_FRAMES] = {0};
    printf("\nPage Replacement Algorithm: LRU\n");
    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int found = 0; 
        for (int j = 0; j < frames; j++) {
            if (frame[j] == currentPage) {
                found = 1;
                used[j] = i;
                break;
            }
        }
        if (found == 0) {
            int leastUsed = 0;
           
            for (int j = 1; j < frames; j++) {
                if (used[j] < used[leastUsed]) {
                    leastUsed = j;
                }
            }
           
            frame[leastUsed] = currentPage;
            used[leastUsed] = i;
            pageFaults++;
        }
        printf("Page reference: %d -> [", currentPage);
        for (int j = 0; j < frames; j++) {
            if (frame[j] == -1) {
                printf(" - ");
            } else {
                printf(" %d ", frame[j]);
            }
        }
        printf("] -> ");
       
        if (found == 0) {
            printf("Page Fault\n");
        } else {
            printf("No Page Fault\n");
        }
    }
   
    printf("Total page faults: %d\n", pageFaults);
}

void opt(int pages[], int n, int frames) {
    int frame[MAX_FRAMES] = {-1};
    int pageFaults = 0;
    int nextIndex[MAX_FRAMES] = {0};
     printf("\nPage Replacement Algorithm: OPT\n");
    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == currentPage) {
                found = 1;
                break;
            }
        }
        if (found == 0) 
        {
            int farthest = 0;
            int replaceIndex = 0;
            for (int j = 0; j < frames; j++) 
            {
                int foundFlag = 0;
                for (int k = i + 1; k < n; k++) 
                {
                    if (frame[j] == pages[k]) 
                    {
                        nextIndex[j] = k;
                        foundFlag = 1;
                        break;
                    }
                }  
                if (foundFlag == 0) 
                {
                    replaceIndex = j;
                    break;
                } else 
                {
                    if (nextIndex[j] > farthest) 
                    {
                        farthest = nextIndex[j];
                        replaceIndex = j;
                    }
                }
            } 
            frame[replaceIndex] = currentPage;
            pageFaults++;
        }
        printf("Page reference: %d -> [", currentPage);
        for (int j = 0; j < frames; j++) {
            if (frame[j] == -1) {
                printf(" - ");
            } else {
                printf(" %d ", frame[j]);
            }
        }
        printf("] -> "); 
        if (found == 0) {
            printf("Page Fault\n");
        } else {
            printf("No Page Fault\n");
        }
    } 
    printf("Total page faults: %d\n", pageFaults);
}