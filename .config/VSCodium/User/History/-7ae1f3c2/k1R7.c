
int check (int x, int y, int n){
    if (x > 0 &&  x < n - 1  && y > 0 && y < n - 1){
        return 1;
    }
    return 0;

}

int main(void){
    check(1, 1, 1);
    return 0;
}