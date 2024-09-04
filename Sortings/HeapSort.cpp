#include "Sortings.h"

#define SWAP(I,J) { int temp = q[I]; q[I] = q[J]; q[J] = temp; }



void HeapSort(int* p, uint n)
{
	int* const q = p - 1;
	for (uint i = 2u; i <= n; i++)
		for (uint j = i; q[j >> 1] < q[j] && j != 1u; j >>= 1)  SWAP(j >> 1, j);
	for (uint i = n; i; i--) {
		SWAP(1, i);
		for (uint j = 1u; j < ((i - 1) >> 1) + 1;) {
			uint max_i = j << 1;
			if (q[max_i + 1] > q[max_i] && max_i + 1 != i)  max_i++;
			if (q[max_i] > q[j])  SWAP(j, max_i);
			j = max_i;
		}
	}
}
