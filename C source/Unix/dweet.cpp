/**

    Probably you don't need this file! 
    This file writes on dweet all the data you need
    dweet.io is a cute site when you can share your data and, using freeboard.io, you
    can do some cute things
    If you want to give a look at this project freeboard: 
    https://freeboard.io/board/nuSYkN
    As you can see, if you run this program it will send to dweet.io your pc's latitude,
    longitude and the sensor value. On freeboard, you can see a gauge that shows the detector
    value and a map with your current position (very approximatively, sadly).
    And now you are asking yourself: "What the f*ck, why should I need a map?"
    Oh, well, think one minute what would happen if in every home of a city there was one smoke 
    detector and the fire station has a webpage like my freeboard to monitor every fire
    in the city. 
    Sadly, this isn't very powerful, so now we send all this data to firebase using the other
    file in this directory.

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

const int soglia = 400;
const char fileC[] = "Coordinates.txt";

void dweet(char key[], char value[])
{
    const char nomeDweet[] = "Alternanza_Brozzoni_Brunelli_Trevisan";
    
    char command[512];
    strncpy(command,"curl https://dweet.io/dweet/for/",512);
    strncat(command,nomeDweet,512);
    strncat(command,"?",512);
    strncat(command,key,512);
    strncat(command,"=",512);
    strncat(command,value,512);
    system(command);
    usleep(1000);
    //printf("%s\n", command);
}

void position()
{
    char control[512];
    strncpy(control,"curl -s http://freegeoip.net/json/ | jq -r '\"\\(.latitude) \\(.longitude)\"'",512);
    strncat(control, " > ", 512);
    strncat(control, fileC, 512);
    system(control);
    //printf("%s", control);
}

int main()
{
    FILE *file;
    file = freopen("/dev/cu.usbmodem1421","r", stdin);  //Opening device file
    int i = 0;
    position();
    
    FILE *in;
    in = fopen(fileC, "r");

    float x, y;
    fscanf(in, "%f %f", &x, &y);
    fclose(in);

    char Password[512];
    int password;
    scanf("%s", Password);
    
    while(strcmp(Password, "Password:") != 0)
    {
        scanf("%s", Password); 
        //printf("LOL");
    }
    scanf("%d", &password);
    printf("OK!\n");
    
    while(1)
    {
        char buffer[32];
        //snprintf(buffer, 32, "%f", x);
        //dweet("Latitude",buffer);
        //snprintf(buffer, 32, "%f", y);
        //dweet("Longitude",buffer);
        int n;
        scanf("%d", &n);
        snprintf(buffer,32, "%d", n);
        dweet("Smoke",buffer);

    }
    fclose(file);
    
}