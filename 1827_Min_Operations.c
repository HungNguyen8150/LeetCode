int minOperations(int* nums, int numsSize){
    int numSteps = 0;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= nums[i - 1]) {
            int stepsNeeded = nums[i - 1] + 1;
            numSteps += stepsNeeded - nums[i];
            nums[i] = stepsNeeded;
        }
    }
    
    return numSteps;
}
