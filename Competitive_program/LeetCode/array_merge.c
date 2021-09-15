
int compare (int *a, int *b){
    
    return *a > *b;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

    int i;
    
    for(i = 0; i < n; i++){
        
        nums1[m + i] = nums2[i];
    }
    
    qsort(nums1, nums1Size, sizeof(int), compare);
}
