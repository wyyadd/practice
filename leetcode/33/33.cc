//主要思路： 找出将原数组旋转的点，以这个点为划分， 分别二分查找
class Solution {
public:
		int FIndIndex(vector<int>& nums){
			if(nums[0] < nums[nums.size() - 1] || nums.size() == 1)
				return 0;
			//初始化左右边界
     int left = 0, right = nums.size() - 1;
     //当左右边界不重合时
      while (left <= right)
      {
          //初始化边界的中点
          int middle = (left + right) / 2;
					if(middle == 0){
						if(nums[0] < nums[1])
							return 1;
						else 
							return 0;
					}
					//  3 4 5 6 1 2  
					//  1 2 3 4 5 6
					//  6 1 2 3 4 5
					//  2 3 4 5 6 1
					//  1 2
					//  2 1
          if (nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1])
          {
              return middle;
          }
          if (nums[middle] > nums[left])
          {
              left = middle + 1;
          }
          else{
              right = middle - 1;
          }
      }
			return 0;
		}

		int Search(vector<int>& array, int left, int right, int x){
      //当左右边界不重合时
      while (left <= right)
      {
          //初始化边界的中点
          int middle = (left + right) / 2;
          //判断所查找元素和当前中点元素是否相等，如果相等则返回中点元素所在的位置
          if (x == array[middle])
          {
              return middle;
          }
          else if (x > array[middle])
          {
              //如果所查找元素大于中点元素，则所查找元素在右部分，则将左边界向右移
              left = middle + 1;
          }
          else{
              //说明所查找元素小于中点元素，则所查找元素在做部分，则将右边界向左移
              right = middle - 1;
          }
      }
      //如果找不到，则返回-1
      return -1;
		}

    int search(vector<int>& nums, int target) {
			int index = FIndIndex(nums);
			int flag = Search(nums, 0, index, target);
			if(flag != -1)
				return flag;	
			flag = Search(nums, index + 1, nums.size() - 1, target);
			if(flag != -1)
				return flag;
			return -1;
    }
};

//主要思路：将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
//此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环. 
/*class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
*/
