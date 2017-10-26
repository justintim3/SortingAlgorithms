// Shell sort implementation
// Modified version of Insertion Sort for varying increments
template <typename E>
inline void inssort2(E A[], int n, int incr) {
	for (int i=incr; i<n; i+=incr)
		for (int j = i; (j >= incr) && A[j] < (A[j - incr]); j -= incr)
		{
			E temp = A[j];
			A[j] = A[j - incr];
			A[j - incr] = temp;
		}
}

template <typename E>
void shellsort(E A[], int n) { // Shellsort
  for (int i=n/2; i>2; i/=2)      // For each increment
    for (int j=0; j<i; j++)       // Sort each sublist
      inssort2<E>(&A[j], n-j, i);
  inssort2<E>(A, n, 1);
}