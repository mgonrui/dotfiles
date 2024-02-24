#include <stdio.h>

void find_closest_flight(int desired_time, 
                         int *departure_time, 
                         int *arrival_time);

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time){
    int d1 = 480,
        d2 = 583,
        d3 = 679,
        d4 = 767,
        d5 = 840,
        d6 = 945,
        d7 = 1140,
        d8 = 1305;

    if (desired_time <= d1 + (d2 - d1) / 2){
        *departure_time = d1;
        *arrival_time = 10 * 60 + 16;
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    }
    else if (desired_time < d2 + (d3 - d2) / 2){
        *departure_time = d2;
        *arrival_time = 11 * 60 + 52;
        printf("9:43 a.m., arriving at 11:52 a.m.\n");
    }
    else if (desired_time < d3 + (d4 - d3) / 2){
        *departure_time = d3;
        *arrival_time = 13 * 60 + 31;
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
    }
    else if (desired_time < d4 + (d5 - d4) / 2){
        *departure_time = d4;
        *arrival_time = 15 * 60 + 0;
        printf("12:47 p.m., arriving at 3:00 p.m.\n");
    }
    else if (desired_time < d5 + (d6 - d5) / 2){
        *departure_time = d5;
        *arrival_time = 16 * 60 + 8;
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
    }
    else if (desired_time < d6 + (d7 - d6) / 2){
        *departure_time = d6;
        *arrival_time = 17 * 60 + 55;
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
    }
    else if (desired_time < d7 + (d8 - d7) / 2){
        *departure_time = d7;
        *arrival_time = 21 * 60 + 20;
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
    }
    else{
        *departure_time = d8;
        *arrival_time = 23 * 60 + 58;
        printf("9:45 p.m., arriving at 11:58 p.m.\n");
    }

}

int main(void) {

    int user_time,
        hour,
        minute,
        departure, 
        arrival,
        d1 = 480,
        d2 = 583,
        d3 = 679,
        d4 = 767,
        d5 = 840,
        d6 = 945,
        d7 = 1140,
        d8 = 1305;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);
    user_time = hour * 60 + minute;
    find_closest_flight(user_time, &departure, &arrival);


    // printf("Closest departure time is ");

    // if (user_time <= d1 + (d2 - d1) / 2)
    //     printf("8:00 a.m., arriving at 10:16 a.m.\n");
    // else if (user_time < d2 + (d3 - d2) / 2)
    //     printf("9:43 a.m., arriving at 11:52 a.m.\n");
    // else if (user_time < d3 + (d4 - d3) / 2)
    //     printf("11:19 a.m., arriving at 1:31 p.m.\n");
    // else if (user_time < d4 + (d5 - d4) / 2)
    //     printf("12:47 p.m., arriving at 3:00 p.m.\n");
    // else if (user_time < d5 + (d6 - d5) / 2)
    //     printf("2:00 p.m., arriving at 4:08 p.m.\n");
    // else if (user_time < d6 + (d7 - d6) / 2)
    //     printf("3:45 p.m., arriving at 5:55 p.m.\n");
    // else if (user_time < d7 + (d8 - d7) / 2)
    //     printf("7:00 p.m., arriving at 9:20 p.m.\n");
    // else
    //     printf("9:45 p.m., arriving at 11:58 p.m.\n");

    return 0;
}