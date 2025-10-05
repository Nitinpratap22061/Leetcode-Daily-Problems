// Last updated: 10/5/2025, 9:00:50 AM
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

          *returnSize=2;
   int *array=malloc(2*sizeof(int));

   int low=0;
   int high= (numbersSize)-1;
   while(low<high){
       if(numbers[low]+numbers[high]==target){
           array[0]=low+1;
           array[1]=high+1;
           break;
       }
       else if(numbers[low]+numbers[high]>target){
           high--;
       }
       else{
           low++;
       }
   }
   return array;    
              
              
              
              
              
             
             
              
              
            
              
                
             
}                