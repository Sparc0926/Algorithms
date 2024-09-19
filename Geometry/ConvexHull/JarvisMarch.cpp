#include "ConvexHull.h"



void swap(Point& const a, Point& const b)
{
	Point temp;
	temp = a, a = b, b = temp;
}



uint JarvisMarch(Point* p, uint n)
{
	uint cnt = 1;
	for (uint i = 1; i < n; i++)
		if (p[i].x < p[0].x)  swap(p[0], p[i]);
	Point s = p[0];
	for (uint i = 2; i < n; i++) {
		auto x1 = p[1].x - p[0].x, y1 = p[1].y - p[0].y;
		auto x2 = p[i].x - p[0].x, y2 = p[i].y - p[0].y;
		// The determinant is positive
		if (x1 * y2 > x2 * y1)  swap(p[1], p[i]);
		else if (x1 * y2 == x2 * y1)
			if ((x2 <= 0 && x2 > x1) || (x2 >= 0 && x2 < x1))  swap(p[1], p[i]);
	}
	swap(p[0], p[1]);
	while (p[cnt - 1].x != s.x || p[cnt - 1].y != s.y) {
		for (uint j = cnt + 1; j < n; j++) {
			auto x1 = p[cnt].x - p[cnt - 1].x, y1 = p[cnt].y - p[cnt - 1].y;
			auto x2 = p[j].x - p[cnt - 1].x, y2 = p[j].y - p[cnt - 1].y;
			if (x1 * y2 > x2 * y1)  swap(p[cnt], p[j]);
			else if (x1 * y2 == x2 * y1)
				if ((x2 <= 0 && x2 > x1) || (x2 >= 0 && x2 < x1))  swap(p[cnt], p[j]);
		}
		cnt++;
	}
	return cnt;
}
