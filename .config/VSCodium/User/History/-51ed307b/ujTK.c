void find_two_largest(const int *a, int n, int *largest, int *second_largest){
    *largest = *a;
    *second_largest = *(a+1);
    for ( int i = 0; i < n ; i++){
        if (*largest < *(a+i)) {
            *second_largest = *largest;
            *largest = *(a+i);
        }
    
    }
}