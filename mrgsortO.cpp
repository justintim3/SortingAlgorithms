// Mergesort implementation and timing test driver
// Mergesort implementation optimized to reverse the 2nd half,
// so that there is no need to test for exhausted sublists.
// Also, sublists of length <= THRESHOLD are sorted with insertion sort.

// Standard insertion sort implementation
template <typename E>
inline void inssort5(E A[], int n) { // Insertion Sort
	for (int i = 1; i<n; i++)       // Insert i'th record
		for (int j = i; (j > 0) && (A[j - 1] > A[j]); j--)
		{
			E temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
		}
}

extern int THRESHOLD2;

//Optimized mergesort implementation
template <typename E>
void mergesortO(E A[], E temp[], int left, int right) {
	if ((right - left) <= THRESHOLD2) { // Small list
		inssort5<E>(&A[left], right - left + 1);
		return;
	}
	int i, j, k, mid = (left + right) / 2;
	mergesortO<E>(A, temp, left, mid);
	mergesortO<E>(A, temp, mid + 1, right);
	// Do the merge operation.  First, copy 2 halves to temp.
	for (i = mid; i >= left; i--) temp[i] = A[i];
	for (j = 1; j <= right - mid; j++) temp[right - j + 1] = A[j + mid];
	// Merge sublists back to A
	for (i = left, j = right, k = left; k <= right; k++)
		if (temp[i] < temp[j]) A[k] = temp[i++];
		else A[k] = temp[j--];
}

template <typename E>
void mrgsortO(E* array, int n)
{
	E* temp = new E[n];
	mergesortO<E>(array, temp, 0, n-1);
}