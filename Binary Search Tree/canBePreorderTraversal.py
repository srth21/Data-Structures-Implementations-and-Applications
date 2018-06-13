'''
Given an array of numbers, return true if given array can represent preorder traversal of a Binary Search Tree, 
else return false. Expected time complexity is O(n).

Examples:

Input:  pre[] = {2, 4, 3}
Output: true
Given array can represent preorder traversal
of below tree
    2
     
      4
     /
    3

Input:  pre[] = {2, 4, 1}
Output: false
Given array cannot represent preorder traversal
of a Binary Search Tree.

Input:  pre[] = {40, 30, 35, 80, 100}
Output: true
Given array can represent preorder traversal
of below tree
     40
   /   
 30    80 
        
  35     100 


Input:  pre[] = {40, 30, 35, 20, 80, 100}
Output: false
Given array cannot represent preorder traversal
of a Binary Search Tree.

Algo :
1) Create an empty stack.
2) Initialize root as INT_MIN.
3) Do following for every element pre[i]
     a) If pre[i] is smaller than current root, return false.
     b) Keep removing elements from stack while pre[i] is greater
        then stack top. Make the last removed item as new root (to
        be compared next).
        At this point, pre[i] is greater than the removed root
        (That is why if we see a smaller element in step a), we 
        return false)
     c) push pre[i] to stack (All elements in stack are in decreasing
        order)  
'''

def check(arr,n):
	stack=[]

	currRoot=-10000000

	for i in range(n):
		print(arr[i],stack)
		ele=arr[i]
		if(ele<currRoot):
			return False
		j=len(stack)-1
		last=-1
		while(len(stack)>0 and stack[j]<ele):
			last=stack[j]
			stack=stack[0:j-1]
			j-=1
			print(stack)
		currRoot=last
		stack.append(ele)
		print(stack)
	return True

print(check([40 , 30 , 35 , 80 , 100],5))
print(check([40 , 30 , 35 ,20, 80 , 100],6))
