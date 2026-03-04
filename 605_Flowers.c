bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int flowerCount = 0;
    bool leftEmpty, rightEmpty;
    for (int i = 0; i < flowerbedSize; i++){
        if (flowerbed[i] == 0){
            if (i == 0 || flowerbed[i-1] == 0){
                leftEmpty = true;
            }
            else leftEmpty = false;

            if (i == flowerbedSize - 1 || flowerbed[i+1] == 0){
                rightEmpty = true;
            }
            else rightEmpty = false;
        }


        if (leftEmpty && rightEmpty){
            flowerbed[i] = 1;
            flowerCount++;
            if (flowerCount >= n) return true;      
        }
    }
    if (flowerCount >= n){
        return true;
    }
    else return false;
}
