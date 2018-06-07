'''
1. complete except for the last level
2. max or min heap
3. root at arr[0]
4. for the ith node : 
	arr[(i-1)/2]-> parent
	arr[2*i+1]-> left child
	arr[2*i+2]-> right child

Operations ( Max heap )
	1. getMaximum() : O(1)
	2. extractMaximum : removes the maximum element from the heap
		needs to call heapify. O(logN)
	3. increaseKey : increase the value and then maybe heapify O(logN)
	4. insert() : O(logN)
	5. delete(k) : O(logN)
		increase key(k,inf)
		heapify()
		extractMax()
'''

class heap:
	def __init__(self,n):
		self.size=n
		arr=[float('-inf')]*n
		self.arr=arr
		val=[-1]*n
		self.val=val
		self.currSize=0
	
	def leftChild(self,i):
		return (2*i)+1
	def rightChild(self,i):
		return (2*i)+2
	def parent(self,i):
		return (i-1)//2

	def getMaximumPriorityFromHeap(self):
		return self.arr[0]
	def getMaximumValue(self):
		return self.val[0]
	def heapify(self,i):
		l=self.leftChild(i)
		r=self.rightChild(i)
		#print(l,r)
		#print("here")
		#print(self.arr[l],self.arr[r])
		largest=i
		if(l<self.size and self.arr[l]>self.arr[i]):
			largest=l
		if(r<self.size and self.arr[r]>self.arr[largest]):
			largest=r 
		if(largest!=i):
			temp=self.arr[i]
			self.arr[i]=self.arr[largest]
			self.arr[largest]=temp
			tempVal=self.val[i]
			self.val[i]=self.val[largest]
			self.val[largest]=tempVal
			self.heapify(largest)

	def insert(self,key,val):
		if(self.currSize==self.size):
			print("heap full.")
		else:
			#print("inserting ele : ",val," with priority : ",key)
			#print("current size : ",self.currSize)
			#print(self.arr)
			self.arr[self.currSize]=key
			self.val[self.currSize]=val
			#print(self.arr)
			self.currSize+=1
			i=self.currSize-1
			#print("i : ",i)
			#print("check for swap : ",self.arr[self.parent(i)],self.arr[i])
			while(i!=0 and self.arr[self.parent(i)]<self.arr[i]):
				#print("swapping : ",self.arr[self.parent(i)],self.arr[i])
				temp=self.arr[i]
				self.arr[i]=self.arr[self.parent(i)]
				self.arr[self.parent(i)]=temp
				tempVal=self.val[i]
				self.val[i]=self.val[self.parent(i)]
				self.val[self.parent(i)]=tempVal
				i=self.parent(i)

	def increaseKey(self,i,newVal):
		self.arr[i]=newVal
		#print(self.arr)
		while(i!=0 and self.arr[self.parent(i)]<self.arr[i]):
				temp=self.arr[i]
				self.arr[i]=self.arr[self.parent(i)]
				self.arr[self.parent(i)]=temp
				i=self.parent(i)
				tempVal=self.val[i]
				self.val[i]=self.val[self.parent(i)]
				self.val[self.parent(i)]=tempVal
		#print(self.arr)
	
	def extractMax(self):
		#print(self.arr,self.currSize)
		if(self.currSize==0):
			print("heap empty.")
			return 
		if(self.currSize==1):
			self.currSize-=1
			temp=self.arr[0]
			self.arr[0]=float('-inf')
			self.val[0]=-1
			return temp
		#print("here")
		#print(self.arr,self.currSize)
		root=self.arr[0]
		self.arr[0]=self.arr[self.currSize-1]
		self.arr[self.currSize-1]=float('-inf')
		rootVal=self.val[0]
		self.val[0]=self.val[self.currSize-1]
		self.val[self.currSize-1]=-1
		self.currSize-=1
		#print(self.arr)
		#print(self.val)
		#print("calling heapify")
		self.heapify(0)
		return root

	def delete(self,i):
		self.increaseKey(i,1000000)
		#print(self.arr)
		self.extractMax()
		#print(self.arr)
	def replaceMax(self,key,val):
		root=self.arr[0]
		self.arr[0]=key
		self.val[0]=val
		if(root>key):
			self.heapify(0)
		return root
'''
heap=heap(10)
#print(heap.currSize,heap.size)
heap.insert(10)
heap.insert(12)
heap.insert(11)
heap.insert(9)
heap.insert(18)
heap.insert(4)
print(heap.arr,heap.currSize)
heap.delete(0)
print(heap.arr,heap.currSize)
print(heap.getMaximum())
heap.delete(0)
print(heap.arr)
print(heap.getMaximum())
heap.insert(10)
print(heap.arr)
heap.insert(12)
#heap.insert(11)
#heap.insert(9)
#heap.insert(18)
heap.insert(4)
heap.insert(100)
print(heap.arr,heap.currSize)'''