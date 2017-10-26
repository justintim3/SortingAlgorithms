extern int	THRESHOLD1;

extern int pow2[9];

template <typename E>
void rsort(E A[], E B[], int n, int k, int r, int cnt[]) {
  // cnt[i] stores number of records in bin[i]
  int j;

  for (int i=0, rtoi=1; i<k; i++, rtoi*=r) { // For k digits
    for (j=0; j<r; j++) cnt[j] = 0;        // Initialize cnt

    // Count the number of records for each bin on this pass
    for (j=0; j<n; j++) cnt[(A[j]/rtoi)%r]++;

    // Index B: cnt[j] will be index for last slot of bin j.
    for (j=1; j<r; j++) cnt[j] = cnt[j-1] + cnt[j];

    // Put records into bins, work from bottom of each bin.
    // Since bins fill from bottom, j counts downwards
    for (j=n-1; j>=0; j--)
      B[--cnt[(A[j]/rtoi)%r]] = A[j];

    for (j=0; j<n; j++) A[j] = B[j];    // Copy B back to A
  }
}

// Radix sort implementation. THRESHOLD1 is the number of bits done each pass
template <typename E>
void radixsort(E* array, int n) {
  E* temp = 0;
  int* cnt = 0;
  
  if (temp == 0) temp = new E[n];  // Declare temp array
  if (cnt == 0) cnt = new int[pow2[THRESHOLD1]];  // Declare temp array
  rsort<E>(array, temp, n, (sizeof(E) * 8)/THRESHOLD1,
                   pow2[THRESHOLD1], cnt);
}