int gcd(int m, int n) {
    int t = 1;
    while(t != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}
bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity){
    if(jug1Capacity==targetCapacity || jug2Capacity==targetCapacity){
        return true;
    }
    if(jug1Capacity+jug2Capacity == targetCapacity){
        return true;
    }
    if(jug1Capacity+jug2Capacity < targetCapacity){
        return false;
    }
    return targetCapacity % gcd(jug2Capacity,jug1Capacity)==0;
}