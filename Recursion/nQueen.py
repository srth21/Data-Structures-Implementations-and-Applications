def isSafe(board, row, col,N):

	# Check this row on left side
	for i in range(col):
		if board[row][i] == 1:
			return False

	# Check upper diagonal on left side
	for i,j in zip(range(row,-1,-1), range(col,-1,-1)):
		if board[i][j] == 1:
			return False

	# Check lower diagonal on left side
	for i,j in zip(range(row,N,1), range(col,-1,-1)):
		if board[i][j] == 1:
			return False

	return True
 

def printSolution(board,n):
	ans=[]
	for i in range(n):
		for j in range(n):
			if(board[i][j]==1):
				ans.append(j+1)
	return ans

def solve(board,n,column,answers):
	#print("col : ",column)
	#printSolution(board,n)
	if(column==n):
		ans=printSolution(board,n)
		answers.append(ans)
		return True
	res=False
	for i in range(n):
		if(isSafe(board,i,column,n)==True):
			#print("True at column : ",column," Row : ",i)
			board[i][column]=1
			#printSolution(board,n)
			#print("calling fun with col : ",column+1)
			res=solve(board,n,column+1,answers) or res
			#print("False at column : ",column," Row : ",i)	
			board[i][column]=0
	return res

def first(a):
	return a[0]
a=[]
n=int(input())
for i in range(n):
	answers=[]
	k=int(input())
	if(k==2 or k==3):
		answers=[-1]
		a.append(answers)
	else:
		board=[]
		for i in range(k):
			board.append([])
			for j in range(k):
				board[i].append(0)
		#board=[[0]*k]*k
		#board[2][2]=1
		#print(board)
		#printSolution(board,k)
		if(solve(board,k,0,answers)==False):
			pass
			#print("-1")
		else:
			a.append(answers)
d=""
for i in a:
	if(len(i)==1 and i[0][0]==-1):
		d+="-1"+"\n"
	else:
		i.sort()
		m=""
		#print(i)
		for j in i:
			st="["
			for s in j:
				st+=str(s)+" "
			st=st.rstrip()
			st+=" ]"
			m+=st+" "
		d+=m+"\n"
print(d)