#input being taken
k=int(input())
n=int(input())
arr=[]
for i in range(k):
	arr.append([])
	arr[i]=[int(m) for m in input().split()]

from arrayHeapModified import heap

'''
heap.arrayIndex[i] stores the array index from which heap.arr[i] was taken
so when we extract an element from heap, we can extract the next element from the same array

we are deleting the element from the array as and when we add it to the heap
so the next element from the array will always be at arr[0]

'''
heap=heap(k)
output=[]

#add the min from each array
for i in range(0,k):
	heap.insert(arr[i][0])
	arr[i]=arr[i][1:]
	heap.arrayIndex[i]=i

#for the remaining elements
for i in range(n*k):
	#get minimum and add to output
	root=heap.getMinimum()
	output.append(root)
	#get array from which min was extracted
	arrayIndex=heap.arrayIndex[0]
	
	#take the next element from that array
	#if empty add inf else add the next corresponding element
	if(arr[arrayIndex]!=[]):
		root=arr[arrayIndex][0]
		arr[arrayIndex]=arr[arrayIndex][1:]
	else:
		root=float('inf')
	#replace the extracted element with the next corresponding element from the array
	heap.replaceMin(root)

print(output)