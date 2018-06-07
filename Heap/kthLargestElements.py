'''

to find the kth largest element in an array
create a min heap of first k elements
then for the remaining elements compare with the root of the heap
	if ele is greater than the root of the heap then replace and heapify
	else do nothing
at the end the root will be the kth largest element

'''
from arrayHeap import heap

arr=[1,4,2,6,9,3,7,5,8,0]
k=5
n=len(arr)
heap=heap(k)
for i in range(k):
	heap.insert(arr[i])

for j in range(k,n):
	if(arr[j]>heap.arr[0]):
		heap.arr[0]=arr[j]
		heap.heapify(0)
print(k,"th largest element is : ",heap.arr[0])