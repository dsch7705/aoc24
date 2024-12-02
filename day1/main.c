#include "input.h"
#include <math.h>


int compare_int(const int* a, const int* b)
{
    return *a - *b;
}
int main(int argc, char** argv)
{
    int left[1000];
    int right[1000];
    fetch_input(1000, "i   i", left, right);
    qsort(left, 1000, sizeof(int), compare_int);
    qsort(right, 1000, sizeof(int), compare_int);
    
    int part_one = 0;
    for (int i = 0; i < 1000; i++)
        part_one += abs(left[i] - right[i]);

    int part_two = 0;
    for (int i = 0; i < 1000; i++)
    {
        int n = left[i];
        int c = 0;
        for (int j = 0; j < 1000; j++)
        {
            if (right[j] == n)
                c++;
        }

        part_two += n * c;
    }

    printf("Part one: %d\nPart two: %d\n", part_one, part_two);
    return 0;
}