#include "ConvexHull.h"
#include <algorithm>



static Point* base;



static bool cmp(const Point& const a, const Point& const b)
{
	auto x1 = a.x - base->x, y1 = a.y - base->y;
	auto x2 = b.x - base->x, y2 = b.y - base->y;
	// Colinear case
	if (x2 * y1 == x1 * y2) {
		if (x1 >= 0)  return y1 < y2 || x1 < x2;
		return y1 > y2;
	}
	// Regularly base on -1/tan(x), which monotonic increases as x increases
	return x2 * y1 < x1 * y2;
}



uint GrahamScan(Point* p, uint n)
{
	uint cnt = 1;
	// Make p[0] the bottom-leftmost point as the base point
	base = p;
	for (uint i = 1; i < n; i++)
		if (p[i].y == base->y && p[i].x < base->x || p[i].y < base->y)  base = (p + i);
	swap(p[0], *base);
	// Sort the other points based on their horizontal angles
	base = p;
	std::sort(p + 1, p + n, cmp);
	// Run the Graham Scan algorithm
	for (uint i = 2; i < n;) {
		auto x1 = p[cnt].x - p[cnt - 1].x, y1 = p[cnt].y - p[cnt - 1].y;
		auto x2 = p[i].x - p[cnt].x, y2 = p[i].y - p[cnt].y;
		// Determinant not negative, add it to the convex hull
		if (x1 * y2 >= x2 * y1)  p[++cnt] = p[i++];
		// Otherwise step back and check again
		else  p[cnt--] = p[i];
	}
	return cnt + 1;
}