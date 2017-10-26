// Mergesort implementation and timing test driver
// Basic Mergesort version

// Basic mergesort implementation
template <typename E>
void mergesort(E A[], E temp[], int left, int right)
{
	if (left == right)
	{
		return;        // List of one element
	}
	int mid = (left+right)/2;
	mergesort<E>(A, temp, left, mid);
	mergesort<E>(A, temp, mid+1, right);
	for (int i = left; i <= right; i++)   // Copy subarray to temp
	{
		temp[i] = A[i];
	}
	// Do the merge operation back to A
	int i1 = left;
	int i2 = mid + 1;

	for (int curr = left; curr <= right; curr++)
	{
		if (i1 == mid + 1) {     // Left sublist exhausted
			A[curr] = temp[i2++];
		} else if (i2 > right) { // Right sublist exhausted
			A[curr] = temp[i1++];
		} else if (temp[i2] > temp[i1]) {
			A[curr] = temp[i1++];
		} else {
			A[curr] = temp[i2++];
		}
	}
}

template <typename E>
void mrgsort(E* array, int n)
{
	E* temp = new E[n];

	mergesort<E>(array, temp, 0, n-1);
}