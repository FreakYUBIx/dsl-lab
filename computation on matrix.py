
def accept(M):
  r=int(input("\nEnter number of rows : "))
  c=int(input("\nEnter number of coulumns : "))
  
  for i in range(r):
    row=[]
    for j in range(c):
      value = int(input("\nEnter the value of matrix : "))
      row.append(value)
    M.append(row)

def display(M):
  r=len(M)
  c=len(M[0])
  for i in range(r):
    for j in range(c):
      print(M[i][j],end="  ")
    print("\n")

def Addition(M1,M2):
  r1=len(M1)
  r2=len(M2)
  c1=len(M1[0])
  c2=len(M2[0])
  if(r1==r2 and c1==c2):
    M3=[]
    for i in range(r1):
      A=[]
      for j in range(c1):
        A.append(M1[i][j]+M2[i][j])
      M3.append(A)
    display(M3)
  else:
    print("\nNumber of rows and columns are different.")
    
def Subtraction(M1,M2):
  r1=len(M1)
  r2=len(M2)
  c1=len(M1[0])
  c2=len(M2[0])
  if(r1==r2 and c1==c2):
    M3=[]
    for i in range(r1):
      A=[]
      for j in range(c1):
        A.append(M1[i][j]-M2[i][j])
      M3.append(A)
    display(M3)
  else:
    print("\nNumber of rows and columns are different.")
    
def Transpose(M):
  r=len(M)
  c=len(M[0])
  T=[]
  for i in range(c):
    A=[]
    for j in range(r):
      A.append(M[j][i])
    T.append(A)
  display(T)

def Multiplication(M1,M2):
  M3=[]
  r1=len(M1)
  c1=len(M1[0])
  r2=len(M2)
  c2=len(M2[0])
  for i in range(r1):
    row=[]
    for j in range(c2):
      sum=0
      for k in range(c1):
        sum=sum+M1[i][k]*M2[k][j]
      row.append(sum)
    M3.append(row)
  display(M3)
    
def main():

  matrix1 = []
  matrix2 = []
  
  while True:
    print("\n1.Addition of two matrix.")
    print("\n2.Subtraction of two matrix.")
    print("\n3.Multiplication of two matrix.")
    print("\n4.Transpose of Matrix.")
    print("\n5.Exit.")
  
    ch = int(input("\nEnter your choice(1 to 5) : "))
    
    if(ch==1):
      print("\nEnter Matrix 1 : ")
      accept(matrix1)
      print("\nEnter Matrix 2 : ")
      accept(matrix2)
      print("\nAddition is : ")
      Addition(matrix1,matrix2)
      
    elif(ch==2):
      print("\nEnter Matrix 1 : ")
      accept(matrix1)
      print("\nEnter Matrix 2 : ")
      accept(matrix2)
      print("\nSubtraction is : ")
      Subtraction(matrix1,matrix2)
      
    elif(ch==3):
      print("\nEnter Matrix 1 : ")
      accept(matrix1)
      print("\nEnter Matrix 2 : ")
      accept(matrix2)
      print("\nMultiplication is : ")
      Multiplication(matrix1,matrix2)
      
    elif(ch==4):
      print("\nEnter matrix : ")
      accept(matrix1)
      print("\nTranspose is : ")
      Transpose(matrix1)
      
    elif(ch==5):
      print("\nEnd of Program.")
      break
    else:
      print("\nYou entered a wrong choice.")
    
main()