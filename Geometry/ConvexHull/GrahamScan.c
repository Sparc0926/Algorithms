#include <stdlib.h>
#include "ConvexHull.h"



static Point* base;



static int cmp(const void* a, const void* b)
{
	auto x1 = ((Point*)a)->x - base->x, y1 = ((Point*)a)->y - base->y;
	auto x2 = ((Point*)b)->x - base->x, y2 = ((Point*)b)->y - base->y;
	// Colinear case
	if (x2 * y1 == x1 * y2) {
		if (x1 >= 0)  return -(y1 < y2 || x1 < x2);
		return -(y1 > y2);
	}
	// Regularly base on -1/tan(x), which monotonic increases as x increases
	return -(x2 * y1 < x1 * y2);
}



unsigned int GrahamScan(Point* p, unsigned int n)
{
	unsigned int cnt = 1;
	// Make p[0] the bottom-leftmost point as the base point
	base = p;
	for (int i = 1; i < n; i++)
		if (p[i].y == base->y && p[i].x < base->x || p[i].y < base->y)  base = (p + i);
	SWAP_POINT_PTR(p, base);
	// Sort the other points based on their horizontal angles
	base = p;
	qsort(p + 1, n - 1, sizeof(Point), cmp);
	// Run the Graham Scan algorithm
	for (int i = 2; i < n;) {
		auto x1 = p[cnt].x - p[cnt - 1].x, y1 = p[cnt].y - p[cnt - 1].y;
		auto x2 = p[i].x - p[cnt].x, y2 = p[i].y - p[cnt].y;
		// Determinant not negative, add it to the convex hull
		if (x1 * y2 >= x2 * y1)  p[++cnt] = p[i++];
		// Otherwise step back and check again
		else  p[cnt--] = p[i];
	}
	return cnt + 1;
}