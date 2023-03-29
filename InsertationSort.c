#include <stdio.h>

int main() {
int a[10], n, count;

printf("Enter the Size of an array");
scanf("%d" , &count);
printf("Enter the value of an array[]");
for ( n = 0; n < count; n++)
scanf("%d",&a[n]);
}
insertionSort(a){

int i, j, temp;
 for (i = 1; i < n; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= a[j])  /* Move the elements greater than temp to one position ahead from their current position*/  
        {    
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = temp;    
    
	}
	}  
printf("The Sorted array"); 
for (n = 0; n < count; n++)

printf("%d", &a[count]);

insertionSort(a)

return 0;
 }

