bool search(const int a[], int n, int key){
    const int *i;
    for (i = a; i < a + n - 1; i++){
        if ( key == *i){
            return true;
        }
        else {
            return false;
        }
    }
}