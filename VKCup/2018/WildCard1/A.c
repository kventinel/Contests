#include <stdio.h>

int main() {
   int arr1[100000];
   int arr2[100000];
   int first1 = 0;
   int last1 = 1;
   int first2 = 0;
   int last2 = 0;
   arr1[0] = 1;
   int l, r;
   scanf(%d, &l);
   scanf(%d, &r);
   int k = 0;
   int u = 0;
   while (last1 > first1 || last2 > first2) {
       if (last1 > first1 && last2 > first2 && arr1[first1] == arr2[first2]) {
          ++first2;
       } else if (last1 > first1 && last2 > first2) {
           if (arr1[first1] < arr2[first2]) {
               if (arr1[first1] >= l && arr1[first1] <= r) {
                   ++k;
               }
               if (arr1[first1] <= r / 2) {
                   arr1[last1] = arr1[first1] * 2;
                   ++last1;
               }
               if (arr1[first1] <= r / 3) {
                   arr2[last2] = arr1[first1] * 3;
                   ++last2;
               }
               ++first1;
           } else {
               if (arr2[first2] >= l && arr2[first2] <= r) {
                   ++k;
               }
               if (arr2[first2] <= r / 2) {
                   arr1[last1] = arr2[first2] * 2;
                   ++last1;
               }
               if (arr2[first2] <= r / 3) {
                   arr2[last2] = arr2[first2] * 3;
                   ++last2;
               }
               ++first2;
           }
       } else if (last1 > first1) {
            if (arr1[first1] >= l && arr1[first1] <= r) {
               ++k;
            }
            if (arr1[first1] <= r / 2) {
               arr1[last1] = arr1[first1] * 2;
               ++last1;
            }
            if (arr1[first1] <= r / 3) {
               arr2[last2] = arr1[first1] * 3;
               ++last2;
            }
            ++first1;
       } else {
           if (arr2[first2] >= l && arr2[first2] <= r) {
               ++k;
           }
           if (arr2[first2] <= r / 2) {
               arr1[last1] = arr2[first2] * 2;
               ++last1;
           }
           if (arr2[first2] <= r / 3) {
               arr2[last2] = arr2[first2] * 3;
               ++last2;
           }
           ++first2;
       }
   }
   printf(%d, k);
}
