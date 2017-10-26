// Optimized Shell sort implementation, uses "division by 3's"
// to determine growth in list sizes
// Modified version of Insertion Sort for varying increments
template <typename E>
inline void inssort3(E A[], int n, int incr) {
    for (int i=incr; i<n; i+=incr)
		for (int j = i; (j >= incr) && A[j] < (A[j - incr]); j -= incr)
		{
			E temp = A[j];
			A[j] = A[j - incr];
			A[j - incr] = temp;
		}
}

template <typename E>
void shellsortO(E A[], int n) {
  int firstincr;
  for (firstincr = 1; firstincr <= n; firstincr = firstincr * 3 + 1);
  for (int i=firstincr/3; i>2; i/=3)
    for (int j=0; j<i; j++)
      inssort3<E>(&A[j], n-j, i);
  inssort3<E>(A, n, 1);    // Could call regular inssort
}