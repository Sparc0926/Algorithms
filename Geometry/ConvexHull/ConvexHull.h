#pragma once

typedef struct { float x, y; } Point;

#define SWAP_POINT_PTR(A, B) {\
	Point temp;\
	temp = *(A), *(A) = *(B), *(B) = temp;\
}

unsigned int JarvisMarch(Point* p, unsigned int n);  // O(nh)
unsigned int GrahamScan(Point* p, unsigned int n);  // O(nlogn)