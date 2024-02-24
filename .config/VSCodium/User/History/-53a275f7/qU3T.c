
void swap(int *p, int *q);

void swap(int *p, int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int main (void){
    int i = 1;
    int j = 2;
    swap(&i, &j);    /* exchanges values of i and j */
    printf("i = %d\n", i);
    printf("j = %d\n", j);
}