/**

    I am writing on my Mac Book Air and I was trying to read what Arduino writes on
    serial port and I was like OMG IT WILL BE SO DIFFICULT I'M FUCKED UP
    OH YES
    15 LINES OF CODE
    THANK U UNIX I <3 U

    If you're using Windows this file isn't useful for u 
    I'm sorry but you'll have to use a file that is long and difficult but you use Windows,
    probably you deserve it
    Come to the Dark Side, we have sudo 


    I have just added a part to write on firebase.
    First of all, you have to install firebase CLI (https://github.com/firebase/firebase-tools)
    Then, you have to create your own firebase directory 

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

void firebase(int value, char key[])
{
    FILE *out;
    out = freopen("documents/firebase/output.txt", "w", stdout);
    printf("{ \n \"type\": \"%d\" \n}", value);
    fclose(out);
    char control[1024];
    //system("cd Documents/firebase");
    
    //system("cd firebase");
    strncpy(control, "firebase database:set --confirm /", 1024);
    strncat(control, key, 1024);
    strncat(control, " documents/firebase/output.txt", 1024);
    printf("%s\n", control);
    system(control);

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
    //firebase(x,"Latitude");
    //firebase(y,"Longitude");
    
    while(1)
    {
        int n;
        scanf("%d", &n);
        //printf("%d\n",n);
        char buffer[32];
        snprintf(buffer,32, "%d", n);
        //dweet("Smoke",buffer);
        i++;
        firebase(n, "value");

    }
    fclose(file);
    
}