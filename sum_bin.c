/* find the even number sum in the binary form*/


#include <stdio.h> 
#include<stdlib.h>
int countOne(int n) 
{ 
    int count = 0; 
    while (n) 
	{ 
        n = n & (n - 1); 
        count++; 
    } 
    if (count % 2 == 0) 
        return 1; 
    else
        return 0; 
} 
int sumDigits(int n) 
{ 
    int sum = 0; 
    while (n != 0) 
	{ 
        sum += n % 10; 
        n /= 10; 
    }   
    return sum; 
} 
int main() 
{ 
	int i;
    int arr[] = { 4, 9, 15 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int total_sum = 0; 
    for(i = 0; i < n; i++) 
	{ 
        if (countOne(arr[i])) 
            total_sum += sumDigits(arr[i]); 
    } 
    printf("the total is %d\n",total_sum); 
      
    return 0; 
}
