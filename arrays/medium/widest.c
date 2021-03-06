/**
*
*   # 1637. Widest Vertical Area Between Two Points Containing No Points
*
*       Given n points on a 2D plane where points[i] = [xi, yi],
*       Return the widest vertical area between two points such
*       that no points are inside the area.
*
*       A vertical area is an area of fixed-width     extending
*       infinitely along the y-axis (i.e., infinite height). The
*       widest  vertical area is the one with the maximum width.
*
*       Note that points on the edge of a vertical area are not
*       considered included in the area.
*
*/


#include <stdio.h>
#include <stdlib.h>

int diff(const void* a, const void* b)
{
    int na = **(int**)a;
    int nb = **(int**)b;

    return (na-nb);
}


int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize)
{
    int max_val, i;
    *pointsColSize = pointsSize;
    qsort(points, pointsSize, sizeof(int*), diff);

    max_val = points[0][0] - points[1][0];

    for (i = 1; i < pointsSize; i++)
    {
        int difference = (points[i][0] - points[i-1][0]);
        if (difference > max_val)
        {
            max_val = difference;
        }
    }

    return max_val;

}

int main(void)
{
    int size, x, cols;

    int a[2] = {3, 1};
    int b[2] = {9, 0};
    int c[2] = {1, 0};
    int d[2] = {1, 4};
    int e[2] = {5, 3};
    int f[2] = {8, 8};

    size = 6;
    int **points = malloc(size*sizeof(int*));
    points[0] = a;
    points[1] = b;
    points[2] = c;
    points[3] = d;
    points[4] = e;
    points[5] = f;

    x = maxWidthOfVerticalArea(points, size, &cols);

    printf("%i\n", x);
    return 0;

}
