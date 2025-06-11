#include <stdio.h>

int main() {
    int totM, noPart, osM;
    int internalFragmentation = 0;

    printf("ENTER TOTAL MEMORY, NUMBER OF PARTITIONS, AND OS MEMORY:\n");
    scanf("%d %d %d", &totM, &noPart, &osM);

    int availableM = totM - osM;
    int sizePart = availableM / noPart;
    printf("Each partition size: %d\n", sizePart);

    for (int i = 0; i < noPart; i++) {
        int pNO, size;
        printf("ENTER PROCESS NO and SIZE for partition %d:\n", i + 1);
        scanf("%d %d", &pNO, &size);

        if (size <= sizePart) {
            printf("Process %d is allocated \n", pNO);
            internalFragmentation += (sizePart - size);
        } else {
            printf("PROCESS %d BLOCKED\n", pNO);
        }
    }

    printf("TOTAL INTERNAL FRAGMENTATION: %d\n", internalFragmentation);

    return 0;
}
