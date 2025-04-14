#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Job {
    char id[5];
    int deadline;
    int profit;
};

// Comparator function for sorting by profit (descending)
int compare(const void *a, const void *b) {
    struct Job *job1 = (struct Job *)a;
    struct Job *job2 = (struct Job *)b;
    return job2->profit - job1->profit;
}

int findMaxDeadline(struct Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max)
            max = jobs[i].deadline;
    }
    return max;
}

void jobSequencing(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), compare);

    int maxDeadline = findMaxDeadline(jobs, n);
    int slot[MAX];
    char jobOrder[MAX][5];
    int totalProfit = 0;

    // Initialize all time slots to -1 (free)
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }

    // Try to schedule each job
    for (int i = 0; i < n; i++) {
        // Find a free slot from job's deadline to 0
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i; // Assign job i to slot j
                strcpy(jobOrder[j], jobs[i].id);
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print job sequence and total profit
    printf("\nSelected Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1)
            printf("%s ", jobOrder[i]);
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;
    struct Job jobs[MAX];

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter Job ID, Deadline, and Profit:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}
