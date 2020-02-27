int next (int n) {
    int temp = 0;
    while(n) {
        temp += (n % 10) * (n % 10);
        n /= 10;
    }
    return temp;
}
bool isHappy(int n){
int p = n, q = n;
while(q != 1) {
    p = next(p);
    q = next(next(q));
    if(p == q) break;
}
return q == 1;
}
