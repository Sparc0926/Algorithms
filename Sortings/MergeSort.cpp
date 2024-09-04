#include "Sortings.h"
#include <malloc.h>



void MergeSort(int* p, uint n)
{
	uint x = 0u, y = 0u, l = n >> 1, r = n + 1u >> 1;
	if (n != 1u) {
		MergeSort(p, l);
		MergeSort(p + l, r);
	}
	int* q = (int*)alloca(n * sizeof(int));
	while (x != l || y != r) {
		q[x + y - 1] = p[x] < p[l + y] ? p[x++] : p[l + y++];
		if (x == l)
			for (; y != r; y++)  q[x + y] = p[l + y];
		if (y == r)
			for (; x != l; x++)  q[x + y] = p[x];
	}
	for (uint i = 0; i < n; i++)  p[i] = q[i];
}
