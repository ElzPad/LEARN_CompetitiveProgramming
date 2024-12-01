void visit(int** rooms, int* roomsColSize, bool *visited, int roomId, int *visitedAmnt) {
    if (visited[roomId])    return;

    visited[roomId] = true;
    *visitedAmnt = *visitedAmnt+1;

    for (int i=0; i<roomsColSize[roomId]; i++)
        visit(rooms, roomsColSize, visited, rooms[roomId][i], visitedAmnt);
    return;
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];
    int visitedAmnt = 0;
    for (int i=0; i<roomsSize; i++) visited[i] = false;

    visit(rooms, roomsColSize, visited, 0, &visitedAmnt);
    return visitedAmnt == roomsSize;
}