// Insertion sort implementation
template <typename E>
void inssort(E A[], int n)
{ // Insertion Sort
	for (int i=1; i<n; i++)       // Insert i'th record
		for (int j = i; (j > 0) && (A[j - 1] > A[j]); j--)
		{
			E temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
		}
}