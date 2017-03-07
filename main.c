#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
SYSTEMTIME string_time;


int main()
{
    FILE *datafile;
    int reminder;
    char answer;
//I could find a way for auto running the program other than putting it on the startup folder (I think It'd be nice to have it ran verytime the computer wakes up from sleep. Finally,


    if((datafile = fopen("reminder.txt", "r+")) == NULL){
       printf("Error while opening file! \n");
       exit(1);

    }

    fseek(datafile, 0, SEEK_SET);
    fscanf(datafile, "%d", &reminder);

    time();


    if(reminder==1 && string_time.wDay>=3 && string_time.wDay<=9){
        printf("I need to give the kW readout to the utility company!\nDo you want to postpone to the next month? Enter y for yes and n for no\n");
        answer=getchar();
                if(answer=='y'){
                    printf("Postponing!\n");
                    reminder=0;

                }
                else{printf("No postponing then!\n");
                     reminder=1; }

            }

   if(string_time.wDay<=2 || string_time.wDay>=10){
            printf("No need to give the readout yet!\n");
            reminder=1;

    }

    if(reminder==0 && (string_time.wDay>=3 && string_time.wDay<=9)){
        printf("According to my notes, you already gave the readout this month!\n");
    }

    fseek(datafile, 0, SEEK_SET);
    fprintf(datafile, "%d", reminder);
    fclose(datafile);

    printf("Program will end!\n");
}


int time(){

    GetSystemTime(&string_time);
    printf("Day: %d \n", string_time.wDay);

    return(string_time.wDay);
    }
