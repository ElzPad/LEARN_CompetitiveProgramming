bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int plantable = 0;
    for (int i=0; i<flowerbedSize; i++) {
        if ( !flowerbed[i] && (i==0 || !flowerbed[i-1]) && (i==flowerbedSize-1 || !flowerbed[i+1]) ) {
            plantable += 1;
            flowerbed[i] = 1;
        }
    }
    return plantable >= n;
}