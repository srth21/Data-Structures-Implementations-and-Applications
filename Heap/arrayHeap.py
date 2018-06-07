'''
1. complete except for the last level
2. max or min heap
3. root at arr[0]
4. for the ith node : 
	arr[(i-1)/2]-> parent
	arr[2*i+1]-> left child
	arr[2*i+2]-> right child

Operations ( Min heap )
	1. getMinimum() : O(1)
	2. extractMinimum : removes the minimum element from the heap
		needs to call heapify. O(logN)
	3. decreaseKey : decrease the value and then maybe heapify O(logN)
	4. insert() : O(logN)
	5. delete(k) : O(logN)
		decrease key(k,-inf)
		heapify()
		extractMin()
'''

class heap:
	def __init__(self,n):
		self.size=n
		arr=[float('inf')]*n
		self.arr=arr
		self.currSize=0
	
	def leftChild(self,i):
		return (2*i)+1
	def rightChild(self,i):
		return (2*i)+2
	def parent(self,i):
		return (i-1)//2

	def getMinimum(self):
		return self.arr[0]

	def heapify(self,i):
		l=self.leftChild(i)
		r=self.rightChild(i)
		#print(l,r)
		#print("here")
		#print(self.arr[l],self.arr[r])
		smallest=i
		if(l<self.size and self.arr[l]<self.arr[i]):
			smallest=l
		if(r<self.size and self.arr[r]<self.arr[smallest]):
			smallest=r 
		if(smallest!=i):
			temp=self.arr[i]
			self.arr[i]=self.arr[smallest]
			self.arr[smallest]=temp
			self.heapify(smallest)

	def insert(self,key):
		if(self.currSize==self.size):
			print("heap full.")
		else:
			self.arr[self.currSize]=key
			self.currSize+=1
			i=self.currSize-1
			while(i!=0 and self.arr[self.parent(i)]>self.arr[i]):
				temp=self.arr[i]
				self.arr[i]=self.arr[self.parent(i)]
				self.arr[self.parent(i)]=temp
				i=self.parent(i)
	
	def decreaseKey(self,i,newVal):
		self.arr[i]=newVal
		#print(self.arr)
		while(i!=0 and self.arr[self.parent(i)]>self.arr[i]):
				temp=self.arr[i]
				self.arr[i]=self.arr[self.parent(i)]
				self.arr[self.parent(i)]=temp
				i=self.parent(i)
		#print(self.arr)
	
	def extractMin(self):
		#print(self.arr,self.currSize)
		if(self.currSize==0):
			print("heap empty.")
			return
		if(self.currSize==1):
			self.currSize-=1
			return self.arr[0]
		#print("here")
		#print(self.arr,self.currSize)
		root=self.arr[0]
		self.arr[0]=self.arr[self.currSize-1]
		self.arr[self.currSize-1]=float('inf')
		self.currSize-=1
		#print(self.arr)
		#print("calling heapify")
		self.heapify(0)
		return root

	def delete(self,i):
		self.decreaseKey(i,-1000000)
		#print(self.arr)
		self.extractMin()
		#print(self.arr)
	def replaceMin(self,key):
		root=self.arr[0]
		self.arr[0]=key
		if(root<key):
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
print(heap.getMinimum())
heap.delete(0)
print(heap.arr)
print(heap.getMinimum())
heap.insert(10)
heap.insert(12)
heap.insert(11)
heap.insert(9)
heap.insert(18)
heap.insert(4)
heap.insert(100)
print(heap.arr,heap.currSize)'''