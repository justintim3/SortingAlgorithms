// Selection sort implementation
template <typename E>
void selsort(E A[], int n)
{ // Selection Sort
	for (int i=0; i<n-1; i++)
	{   // Select i'th record
		int lowindex = i;           // Remember its index
		for (int j = n - 1; j > i; j--)   // Find the least value
		{
			if (A[lowindex] > A[j])
			{ 
				lowindex = j;           // Put it in place
			}
		}
		E temp = A[i];
		A[i] = A[lowindex];
		A[lowindex] = temp;
	}
}