// Bubble Sort implementation and timing test driver
// Bubble sort implementation
template <typename E>
void bubsort(E A[], int n) { // Bubble Sort
	for (int i = 0; i<n - 1; i++)     // Bubble up i'th record
		for (int j = n - 1; j>i; j--)
			if (A[j - 1] > A[j])
			{
				E temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
}