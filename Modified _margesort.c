/* Program to find the modified Marge sort*/

#include <stdio.h>
#include<stdlib.h>
void merge1(int gArray1[], int low1, int mid1,int mid2, int high1, int destArray1[])
{
   int i = low1, j = mid1, k = mid2, l = low1;
   while((i < mid1) && (j < mid2) && (k < high1))
   {
      if(gArray1[i] < gArray1[j])
	  {
         if(gArray1[i] < gArray1[k])
		 {
            destArray1[l++] = gArray1[i++];
         }
         else
		 {
               destArray1[l++] = gArray1[k++];
         }
      }
   else
   {
         if(gArray1[j] < gArray1[k])
		 {
            destArray1[l++] = gArray1[j++];
         }
   else
   {
         destArray1[l++] = gArray1[k++];
   }
   }
}
while((i < mid1) && (j < mid2))
{
   if(gArray1[i] < gArray1[j])
   {
      destArray1[l++] = gArray1[i++];
   }
   else
   {
      destArray1[l++] = gArray1[j++];
   }
}
while((j < mid2) && (k < high1))
{
   if(gArray1[j] < gArray1[k])
   {
   destArray1[l++] = gArray1[j++];
}
else
{
      destArray1[l++] = gArray1[k++];
   }
}
while((i < mid1) && (k < high1))
{
         if(gArray1[i] < gArray1[k])
		{
            destArray1[l++] = gArray1[i++];
         }
   else{
         destArray1[l++] = gArray1[k++];
      }
   }
   while(i < mid1)
   destArray1[l++] = gArray1[i++];
   while(j < mid2)
   destArray1[l++] = gArray1[j++];
   while(k < high1)
   destArray1[l++] = gArray1[k++];
}
void mergeSort3WayRec(int gArray1[], int low1,int high1, int destArray1[])
{
   if(high1 - low1 < 2)
   return;
   int mid1 = low1 + ((high1 - low1) / 3);
   int mid2 = low1 + 2 * ((high1 - low1) / 3) + 1;
   mergeSort3WayRec(destArray1, low1, mid1, gArray1);
   mergeSort3WayRec(destArray1, mid1, mid2, gArray1);
   mergeSort3WayRec(destArray1, mid2, high1, gArray1);
   merge1(destArray1, low1, mid1, mid2, high1, gArray1);
}
void mergeSort3Way(int gArray1[], int n1)
{
   if(n1 == 0)
   return;
   int i;
   int fArray1[n1];
   for(i = 0; i < n1; i++)
   fArray1[i] = gArray1[i];
   mergeSort3WayRec(fArray1, 0,n1, gArray1);
   for(i = 0; i < n1; i++)
   gArray1[i] = fArray1[i];
}

int main()
{
	int i;
   int data1[] = {106, -1, -44, 790, 310,-41, 111, 200, 740, 904};
   mergeSort3Way(data1,10);
	printf("after three way merge sort is:\n");
   for(i = 0; i < 10; i++)
   {
         printf("%d\t",data1[i]);
      }
   return 0;
}
