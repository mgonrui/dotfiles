bool search(const int a[], int n, int key) {

    const int *p;

    for (p = a; p < a + n; p++) {
        if (*p == key)
            return true;
    }
    return false;
}

int temperatures[7][24];

int main(void){
    int i = 0;
    search(temperatures, 24, 32);
    for
    return 0;
}