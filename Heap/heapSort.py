from arrayHeap import heap 

arr=[int(i) for i in input().split()]
n=len(arr)

heap=heap(n)
for i in range(0,n):
	heap.insert(arr[i])

for i in range(0,n):
	arr[i]=heap.extractMin()
print(arr)