#include <stdio.h>

void next_fit(int bin_capacity, int items[], int num_items) {
    int bins[num_items];
    int bin_count = 0;
    int current_bin_capacity = bin_capacity;

    for (int i = 0; i < num_items; i++) {
        if (items[i] <= current_bin_capacity) {
            current_bin_capacity -= items[i];
            bins[bin_count] = items[i];
        } else {
            printf("Bin %d: %d\n", bin_count + 1, bins[bin_count]);
            bin_count++;
            current_bin_capacity = bin_capacity - items[i];
            bins[bin_count] = items[i];
        }
    }

    // Print the items in the last bin
    printf("Bin %d: ", bin_count + 1);
    for (int i = 0; i <= bin_count; i++) {
        printf("%d ", bins[i]);
    }
    printf("\n");
}

int main() {
    int bin_capacity = 10;
    int items[] = {2, 5, 4, 7, 3, 1, 6};
    int num_items = sizeof(items) / sizeof(items[0]);

    next_fit(bin_capacity, items, num_items);

    return 0;
}
