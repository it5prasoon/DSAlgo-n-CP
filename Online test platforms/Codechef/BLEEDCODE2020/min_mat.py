MAX = 100
def smallestInRow(mat, n, m): 
    print("{", end = "") 
    for i in range(n):  
        minm = mat[i][0] 
  
        for j in range(1, m, 1): 
              
            if (mat[i][j] < minm): 
                minm = mat[i][j] 
           
        print(minm, end = ",") 
  
    print("}") 

  
# Driver code 
if __name__ == '__main__': 
    r = int(input(""))
    c= int(input(""))
    mat1 = []
    for i in range(r):           
        a =[] 
        for j in range(c):   
            a.append(int(input())) 
        mat1.append(a) 
    smallestInRow(mat1, r, c) 
  