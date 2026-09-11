class Solution {
   public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int successes = 0;
        long thresholdCalc = threshold * k;
        long sum = 0;

        for(int i = 0; i < k; i++){
            sum += arr[i];
        }

        if(sum >= thresholdCalc){
            successes++;
        }

        for(int i = k; i < arr.size(); i++){
            sum = sum - arr[i-k] + arr[i];
            if(sum >= thresholdCalc){
                successes++;
            }
        }
        return successes;
    }
};