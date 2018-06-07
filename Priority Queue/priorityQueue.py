'''

Priority Queue with the following Operations :
1.getHighestPriority() : O(1)
2.insert() : O(logN)
3.deleteHighestPriority : O(logN)

'''
from arrayMaxHeap import heap

def insert(heap,elements,priorities,n):
	for i in range(n):
		#print("before inserting : ",elements[i],heap.val,heap.arr)
		heap.insert(priorities[i],elements[i])
		#print("after inserting : ",elements[i],heap.val,heap.arr)

def getHighestPriority():
	priority=heap.getMaximumPriorityFromHeap()
	val=heap.getMaximumValue()
	print("Element with value of ",val," has the max priority of ",priority)

def deleteHighestPriority():
	root=heap.extractMax()
	if(root!=None):
		print("Element with priority ",root,"deleted.")

elements=[int(i) for i in input().split()]
priorities=[int(i) for i in input().split()]
n=len(elements)
heap=heap(n)

insert(heap,elements,priorities,n)
print(heap.arr)
print(heap.val)
getHighestPriority()
deleteHighestPriority()
print(heap.arr)
print(heap.val)
deleteHighestPriority()
deleteHighestPriority()
deleteHighestPriority()
deleteHighestPriority()
print(heap.arr,heap.val)