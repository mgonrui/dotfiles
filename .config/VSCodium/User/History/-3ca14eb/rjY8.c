int ft_iterative_power(int nb, int power){

    int result = nb;
    int i = 0;
    while ( i < power) {
        result *= nb;
        i++;
    }
    return result;
}