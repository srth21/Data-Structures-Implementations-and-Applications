from arrayMaxHeap import heap

n=int(input())
arr=[int(i) for i in input().split()]


heapArr=heap(n)
op=[-1,-1]
heapArr.insert(arr[0],-1)
heapArr.insert(arr[1],-1)
heapArr.insert(arr[2],-1)

for i in range(3,n):
	max1=heapArr.extractMax()
	max2=heapArr.extractMax()
	max3=heapArr.extractMax()
	op.append(max1*max2*max3)
	heapArr.insert(max1,-1)
	heapArr.insert(max2,-1)
	heapArr.insert(max3,-1)
	heapArr.insert(arr[i],-1)
print(op)