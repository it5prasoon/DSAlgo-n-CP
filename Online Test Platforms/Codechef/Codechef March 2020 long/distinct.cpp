 sort(arr, arr + n); 
  
    // Traverse the sorted array 
    int res = 0; 
    for (int i = 0; i < n; i++) { 
  
        // Move the index ahead while 
        // there are duplicates 
        while (i < n - 1 && arr[i] == arr[i + 1]) 
            i++; 
  
        res++; 
    } 

   // int res = 1; 
  
 // for (int i = 1; i < n; i++) { 
  //      int j = 0; 
  //      for (j = 0; j < i; j++) 
    //        if (f[i] == f[j]) 
    //            break; 
    //      if (i == j) 
     //       res++; 
   // }  

     int min = ar[0];
for(int i=1;i<=m;i++){
  if(ar[i]<min)
    min=ar[i];
  //  cout<<min<<" ";
}