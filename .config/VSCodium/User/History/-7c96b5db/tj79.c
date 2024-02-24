

int main (void){
    int temperature_readings[29] [23];  
    int totalhours,
        day,
        hour,
        avrg_temp;

    for (day = 0; day < 30; day++ ){
        for (hour = 0; hour < 24; hour++ ){
            totalhours += temperature_readings[day] [hour];
        }
    }
    avrg_temp = totalhours / (30 * 24);
    
}