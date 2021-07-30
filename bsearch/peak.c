/*
 *                              162. Find Peak Element
 *
 *     A peak element is an element that is strictly greater than its neighbors.
 *
 *     Given an integer array nums, find a peak element, and return its index. If 
 *     the array contains multiple peaks, return the index to any of the peaks.  
 *     You may imagine that nums[-1] = nums[n] = -∞.
 *
 *     You must write an algorithm that runs in O(log n) time.
 *
 *
 */ 

int findPeakElement(int* nums, int numsSize)
{
    int start, end;

    for (start = 0, end = numsSize-1; start < end;)
    {
        int mid = (start+end)/2;

        if (nums[mid] > nums[mid+1])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }

    }

    return start;
}
