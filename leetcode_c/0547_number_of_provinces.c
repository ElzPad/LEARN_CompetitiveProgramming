void findCircleNumDFS(int** isConnected, int isConnectedSize, int* isConnectedColSize, int index) {
    // isConnected[index][index] = 0 meaning that the node has already been visited
    isConnected[index][index] = 0;

    for (int i=0; i<isConnectedColSize[index]; i++) {
        if (isConnected[index][i] && isConnected[i][i])
            findCircleNumDFS(isConnected, isConnectedSize, isConnectedColSize, i);
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int res = 0;

    for (int i=0; i<isConnectedSize; i++) {
        if (!isConnected[i][i]) {
            continue;
        }        
        res += 1;
        findCircleNumDFS(isConnected, isConnectedSize, isConnectedColSize, i);
    }

    return res;
}