// Simple findpivot: Pick middle value in array
template <typename E>
inline int findpivot(E A[], int i, int j)
  { return (i+j)/2; }

// Partition the array
template <typename E>
inline int partition(E A[], int l, int r, E& pivot)
{
	do
	{             // Move the bounds inward until they meet
		while (pivot > A[++l]);  // Move l right and
		while ((l < r) && A[--r] > pivot); // r left
		{
			E temp = A[l];
			A[l] = A[r];
			A[r] = temp;
		}
	} while (l < r);              // Stop when they cross
  return l;      // Return first position in right partition
}

// qsort core function: Basic qsort
template <typename E>
void quicksort(E A[], int i, int j) { // Quicksort
  if (j <= i) return; // Don't sort 0 or 1 element
  int pivotindex = findpivot(A, i, j);
  E temp = A[pivotindex];
  A[pivotindex] = A[j];
  A[j] = temp;
  // k will be the first position in the right subarray
  int k = partition<E>(A, i-1, j, A[j]);
  temp = A[k];
  A[k] = A[j];
  A[j] = temp;
  quicksort<E>(A, i, k-1);
  quicksort<E>(A, k+1, j);
}

template <typename E>
void qsort(E* array, int n) {
  quicksort<E>(array, 0, n-1);
}