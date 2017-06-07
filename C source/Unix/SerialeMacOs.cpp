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
    Then, you have to create your own firebase directory (I use my user directory, where I 
    run my code, if you run it in a different directory (for example in a Codeblock's project
    directory) you have to move to your firebase directory by using bash command like
    cd)

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
    out = fopen("documents/firebase/output.txt", "w");
    fprintf(out,"{ \n \"%s\": \"%d\" \n}", key, value);
    fclose(out);
    char control[1024];
    //system("cd Documents/firebase");
    //system("cd firebase");
    strncpy(control, "firebase database:set --confirm /Alternanza", 1024);
    //strncat(control, key, 1024);
    strncat(control, " documents/firebase/output.txt", 1024);
    //printf("MA IO BOH");
    //printf("%s\n", control);
    system(control);

}

int main()
{
    FILE *file;
    file = freopen("/dev/cu.usbmodem1421","r", stdin);  //Opening device file
    int i = 0;

    char Password[512];
    int password;

    scanf("%s", Password);
    //printf("%d", password);
    while(strcmp(Password, "Password:") != 0)
    {
        scanf("%s", Password); 
        //printf("LOL");
    }
    scanf("%d", &password);
    printf("OK!\n");
    firebase(password, "Password");
    //printf("%d", password); 
    usleep(10000);
    //firebase(0, "Alternanza");
    int flag = 0;

   while(1)
    {
        int n;
        scanf("%d", &n);
        i++;
        printf("%d\n", n);
        
        if((n > 400 && flag == 0) || (i%20 == 0))
            firebase(n, "Alternanza"), flag = 1;

        if(n < 400)
            flag = 0;
    }
    fclose(file);
    
}
