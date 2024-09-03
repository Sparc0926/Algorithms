#pragma once

/* The list of points stored in each
*/

typedef unsigned int uint;

typedef struct { float x, y; } Point;

void swap(Point& const a, Point& const b);

uint JarvisMarch(Point* p, uint n);  // O(nh)
uint GrahamScan(Point* p, uint n);  // O(nlogn)