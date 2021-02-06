#include "calgos/quicksort.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>

/**
 * https://en.wikipedia.org/wiki/Quicksort
 */

static void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

static int partition(int xs[], int lo, int hi)
{
	// KISS -- choose the last element as pivot.
    int pivot = xs[hi];
    int i = lo;
    int j = lo;

    while (j < hi) {
        if (xs[j] < pivot) {
            swap(&xs[i], &xs[j]);
            i += 1;
        }
		j += 1;
    }

	swap(&xs[i], &xs[hi]);

    return i;
}

void quicksort(int xs[], int lo, int hi)
{
    if (lo < hi) {
        int p = partition(xs, lo, hi);
        quicksort(xs, lo, fmin(p, p - 1));
        quicksort(xs, p + 1, hi);
    }
}

int main(int argc, char *argv[])
{
    int xs[] = { 5, 3, 4, 1, 2 };

	printf("before: ");
	for (int i = 0; i < 5; ++i) {
		printf("%d ", xs[i]);
	}
	printf("\n");

    quicksort(xs, 0, 4);

	printf("after: ");
	for (int i = 0; i < 5; ++i) {
		printf("%d ", xs[i]);
	}
	printf("\n");

	int current = xs[0];
	for (int i = 1; i < 5; ++i) {
		assert (current <= xs[i]);
		current = xs[i];
	}

	return 0;
}
