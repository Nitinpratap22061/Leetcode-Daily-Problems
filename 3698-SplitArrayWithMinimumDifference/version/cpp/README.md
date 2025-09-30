You are given an integer array nums.

Split the array into exactly two subarrays, left and right, such that left is strictly increasing  and right is strictly decreasing.

Return the minimum possible absolute difference between the sums of left and right. If no valid split exists, return -1.

 
Example 1:


Input: nums = [1,3,2]

Output: 2

Explanation:

ileftrightValidityleft sumright sumAbsolute difference0[1][3, 2]Yes15|1 - 5| = 41[1, 3][2]Yes42|4 - 2| = 2

Thus, the minimum absolute difference is 2.


Example 2:


Input: nums = [1,2,4,3]

Output: 4

Explanation:

ileftrightValidityleft sumright sumAbsolute difference0[1][2, 4, 3]No19-1[1, 2][4, 3]Yes37|3 - 7| = 42[1, 2, 4][3]Yes73|7 - 3| = 4

Thus, the minimum absolute difference is 4.


Example 3:


Input: nums = [3,1,2]

Output: -1

Explanation:

No valid split exists, so the answer is -1.


 
Constraints:


	2 <= nums.length <= 105
	1 <= nums[i] <= 105

