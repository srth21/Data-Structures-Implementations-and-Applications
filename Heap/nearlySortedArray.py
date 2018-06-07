'''

each element in the array is atmost k elements away from its final position

create a heap of the first k+1 elements
for the remaining :
	assign arr[0->n] as :
		->for the first n-k elements : take from heap
		and repalace from the heap
		->for the rest : extractMin one by one from the heap


'''

from arrayHeap import heap

arr=[2, 6, 3, 12, 56, 8]
k=3
n=len(arr)
heap=heap(k+1)
for i in range(k+1):
	heap.insert(arr[i])

i=k+1
for ti in range(0,n):
	if(i<n):
		arr[ti]=heap.replaceMin(arr[i])
	else:
		arr[ti]=heap.extractMin()
	i+=1
print(arr)