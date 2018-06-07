'''
	kth smallest element in the array
	kth smallest element in the array is the same as n-k+1 th largest element in the array

	we first create a heap of the first n-k+1 elements
'''
from arrayHeap import heap 

#input the values
arr=[int(i) for i in input().split()]
n=len(arr)

#kth smallest : n-k+1th largest
k=n-int(input())+1

#new heap of those many elements
heapArr=heap(k)

#inserting first n-k+1 elements in to the array
for i in range(0,k):
	heapArr.insert(arr[i])

#traversing the elements after the ones added to the hea[]
#if the heap root is greater than the element currently traversed, replace and heapify
#in the end the heap will have n-k+1 largest elements with the n-k+1th at the root-> this is the kth smallest element in the heap
for i in range(k,n):
	if(arr[i]>heapArr.arr[0]):
		heapArr.arr[0]=arr[i]
		heapArr.heapify(0)
		print(heapArr.arr)
	else:
		pass
#printing
print(heapArr.arr[0])