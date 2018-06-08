'''
	Given two equally sized arrays (A, B) and N (size of both arrays).
A sum combination is made by adding one element from array A and another element of array B. Display the maximum K valid sum combinations from all the possible sum combinations.

Examples:

Input :  A[] : {3, 2} 
         B[] : {1, 4}
         K : 2 [Number of maximum sum
               combinations to be printed]
Output : 7    // (A : 3) + (B : 4)
         6    // (A : 2) + (B : 4)

Input :  A[] : {4, 2, 5, 1}
         B[] : {8, 0, 3, 5}
         K : 3
Output : 13   // (A : 5) + (B : 8)
         12   // (A : 4) + (B :  8)
         10   // (A : 2) + (B : 8)
'''
from heapSort import *
from priorityQueue import *

a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
k=int(input())

a=sort(a,len(a))
b=sort(b,len(b))
#print(a)
#print(b)
pq=makeQueue(len(a)+len(b))
n=len(a)
pairs=[]

insert(pq,[[n-1,n-1]],[a[n-1]+b[n-1]],1)
pairs.append(([n-1,n-1]))
for i in range(k):
	pair,s=getHighestPriority(pq)
	print(s)
	#print(pair,s)
	deleteHighestPriority(pq)
	i=pair[0]
	j=pair[1]
	sum1=a[i-1]+b[j]

	if([i-1,j] not in pairs):
		insert(pq,[[i-1,j]],[sum1],1)
		pairs.append([i-1,j])

	sum2=a[i]+b[j-1]
	if([i,j-1] not in pairs):
		insert(pq,[[i,j-1]],[sum2],1)
		pairs.append([i,j-1])