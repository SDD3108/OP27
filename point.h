struct Point {
    int x;
    int y;

    // todo: перегрузить оператор == для сравнения двух точек (игрок наступил на врага/сундук)
    int operator==(const Point& other){
        return x == other.x && y == other.y;
    }
};
