int findDuplicate(int* nums, int numsSize){
    int p = nums[0], q = nums[0];
    do{
        p = nums[p];
        q = nums[q];
        q = nums[q];
    }while( p != q);
    q = nums[0];
    while(p != q) {
        p = nums[p];
        q= nums[q];
    }
    return q;
}
