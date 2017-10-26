// Heapsort implementation and timing test driver
// Basic Heapsort version

// Heap class
template <typename E> class heap {
private:
	E* Heap;          // Pointer to the heap array
	int maxsize;         // Maximum size of the heap
	int n;               // Number of elements now in the heap
						 // Helper function to put element in its correct place
	inline void siftdown(int pos) {
		while (!(pos >= n / 2) && (pos < n)) { // Stop if pos is a leaf
			int j = 2 * pos + 1;
			int rc = 2 * pos + 2;
			if ((rc < n) && Heap[j] < Heap[rc])
				j = rc;            // Set j to greater child's value
			if (Heap[j] < Heap[pos]) return; // Done
			E temp = Heap[pos];
			Heap[pos] = Heap[j];
			Heap[j] = temp;
			pos = j;             // Move down
		}
	}

public:
	heap(E* h, int num, int max)     // Constructor
	{
		Heap = h;
		n = num;
		maxsize = max;
		for (int i = n / 2 - 1; i >= 0; i--)	// Heapify contents of Heap
		{
			siftdown(i);
		}
	}

	// Remove first value
	inline E removefirst() {
		E temp = Heap[0];	// Swap first with last value
		Heap[0] = Heap[--n];
		Heap[n] = temp;
 
		if (n != 0)
		{
			siftdown(0);  // Siftdown new root val
		}
			
		return Heap[n];             // Return deleted value
	}
};

// Standard heapsort implementation
template <typename E>
void heapsort(E A[], int n) { // Heapsort
  E maxval;
  heap<E> H(A, n, n);    // Build the heap
  for (int i=0; i<n; i++)        // Now sort
    maxval = H.removefirst();    // Place maxval at end
}