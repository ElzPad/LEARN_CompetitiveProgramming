int minCostClimbingStairs(int* cost, int costSize) {
    int skipOne=0, skipTwo=0;
    int memCost[costSize];

    memCost[costSize-1] = cost[costSize-1];
    memCost[costSize-2] = cost[costSize-2];
    
    for (int i=costSize-3; i>=0; i--) {
        memCost[i] = cost[i];
        memCost[i] += (memCost[i+1]<=memCost[i+2] ? memCost[i+1] : memCost[i+2]); 
    }
    return memCost[0]<=memCost[1] ? memCost[0] : memCost[1];
}