class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        std::vector<int> flowers(flowerbed.size() + 2, 0);

        for(int i = 0; i < flowerbed.size(); i++){
            flowers[i + 1] = flowerbed[i];
        }
        int planted = 0;

        for(int i = 1; i < flowers.size() - 1; i++){
            if(!flowers[i-1] && !flowers[i] && !flowers[i+1]){
                flowers[i] = 1;
                planted++;
            }
        }
        return planted >= n;
    }
};