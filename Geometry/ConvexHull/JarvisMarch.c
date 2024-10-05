#include "ConvexHull.h"



unsigned int JarvisMarch(Point* p, unsigned int n)
{
	unsigned int cnt = 1;
	{
		unsigned int si = 0;
		for (unsigned int i = 1; i < n; i++)
			if (p[i].x < p[si].x)  si = i;
		SWAP_POINT_PTR(p, p + si);
	}
	Point s = p[0];
	for (int i = 2; i < n; i++) {
		auto x1 = p[1].x - p[0].x, y1 = p[1].y - p[0].y;
		auto x2 = p[i].x - p[0].x, y2 = p[i].y - p[0].y;
		if (((x2 <= 0 && x2 > x1) || (x2 >= 0 && x2 < x1)) &&
			x1 * y2 == x2 * y1 || x1 * y2 > x2 * y1)  SWAP_POINT_PTR(p + 1, p + i);
	}
	SWAP_POINT_PTR(p, p + 1);
	while (p[cnt - 1].x != s.x || p[cnt - 1].y != s.y) {
		for (int j = cnt + 1; j < n; j++) {
			auto x1 = p[cnt].x - p[cnt - 1].x, y1 = p[cnt].y - p[cnt - 1].y;
			auto x2 = p[j].x - p[cnt - 1].x, y2 = p[j].y - p[cnt - 1].y;
			if (((x2 <= 0 && x2 > x1) || (x2 >= 0 && x2 < x1)) &&
				x1 * y2 == x2 * y1 || x1 * y2 > x2 * y1)  SWAP_POINT_PTR(p + cnt, p + j);
		}
		cnt++;
	}
	return cnt;
}