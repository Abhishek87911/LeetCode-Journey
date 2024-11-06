class Solution {
public:
    bool canSortArray(vector<int>& arr) {
       int n = arr.size();
        bool swapped;
        for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                if(__builtin_popcount(arr[j]) == __builtin_popcount(arr[j+1])) swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        
        if (swapped == false)
            break;
    }
     
        for(int i=1;i<n;i++) if(arr[i]<arr[i-1]) return false;
        return true;
        
    }
};