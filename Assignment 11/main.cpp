#include <iostream>
#include <vector>
#include <algorithm> // For copy

int mergeInv(std::vector<int>& nums, std::vector<int>& left, std::vector<int>& right) {
    // Your code here
    int inversions = 0;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    int leftSize = left.size();
    int rightSize = right.size();

    //Merge the two arrays together
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            nums[k] = left[i];
            i++;
        }
        else {
            nums[k] = right[j];
            j++;

            inversions = inversions + leftSize - i; // Count the number of inversions while merging
        }
        k++;
    }

    //Copy the remaining elements over from the left if any
    while (i < leftSize) {
        nums[k] = left[i];
        i++;
        k++;
    }

    //Copy the remaining elements over from the right of any
    while (j < rightSize) {
        nums[k] = right[j];
        j++;
        k++;
    }

    return inversions;
}

int countInv(std::vector<int>& nums) {
    // Base case - one element, nothing to sort

    if (nums.size() > 1) {
        int mid = nums.size() / 2;
        std::vector<int> left(mid);
        std::vector<int> right(nums.size() - mid);
        std::copy(nums.begin(), nums.begin() + mid, left.begin());
        std::copy(nums.begin() + mid, nums.end(), right.begin());
        int numInvLeft = countInv(left);
        int numInvRight = countInv(right);
        int numInvMerge = mergeInv(nums, left, right);
        return numInvLeft + numInvRight + numInvMerge;
    }
    return 0;
}

int main()
{
    int n;
    std::vector<int> numvec{ 4, 5, 6, 1, 2, 3 };
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl; // Should be 9

    numvec = { 1, 2, 3, 4, 5, 6 };
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl; // Should be 0

    numvec = { 6, 5, 4, 3, 2, 1 };
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl;  // Should be 15

    numvec = { 0, 0, 0, 0, 0, 0 };
    n = countInv(numvec);
    std::cout << "Number of inversions " << n << std::endl;;  // Should be 0
}