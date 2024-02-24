

int main (void){
    int temperature_readings[30] [24];  
    int totalhours;
    int day;
    int hour;
    for (day = 0; day < 30; day++ ){
        for (hour = 0; hour < 24; hour++ ){
            totalhours += temperature_readings[day] [hour];
        }
    }
}