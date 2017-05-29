/*
  Copyright (C) 2017 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/*! \file
 *  \brief Esempio di utilizzo di dweet.io per memorizzare dati nel cloud
 *  Viene utilizzato curl per fare il lavoro vero, quindi bisogna assicurarsi
 *  che sia installato oppure che si trovi fianco a fianco con l'eseguibile
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione  26/05/2017
 *  \date  Ultima modifica 26/05/2017
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid_option(char s[])
{
    return  !strcmp(s, "-i") ||
            !strcmp(s, "-g") ||
            !strcmp(s, "-p");
}

int main(int argc, char *argv[])
{
    char thing[256];
    char action[16];
    char command[512];
    char name[64];
    char value[64];
    char file[64];
    /**
    *   Ci sono tre modalità: interattiva, per spedire un dato (post)
    *   o per ricevere un dato (get)
    */
    //Modalità interattiva
    if (argc == 2 && strcmp(argv[1], "-i") == 0  || argc == 1)
    {
        printf("Interactive mode\n");
        printf("Thing name: ");
        fgets(thing, 256, stdin);
        printf("Action [p]ost/[g]et: ");
        fgets(action, 16, stdin);
        if (action[0] == 'p')
        {
            printf("Parameter name: ");
            fgets(name, 64, stdin);
            printf("Parameter value: ");
            fgets(value, 64, stdin);
            strncpy(command, "curl https://dweet.io/dweet/for/", 512);
            strncat(command, thing,512);
            command[strcspn(command, "\r\n")] = 0;
            strncat(command, "?",512);
            strncat(command, name,512);
            command[strcspn(command, "\r\n")] = 0;
            strncat(command, "=",512);
            strncat(command, value,512);
            command[strcspn(command, "\r\n")] = 0;
        }
        else if (action[0] == 'g')
        {
            printf("Output file (default stdout): ");
            fgets(file, 64, stdin);
            strncpy(command, "curl https://dweet.io/get/latest/dweet/for/", 512);
            strncat(command, thing,512);
            command[strcspn(command, "\r\n")] = 0;
            if (strlen(file) > 1){
                strncat(command, " > ",512);
                strncat(command, file,512);
                command[strcspn(command, "\r\n")] = 0;
            }
        }
        else
        {
            printf("Not a valid option [p/g]\n");
            return 1;
        }

    }
    //Modalità get
    else if (argc == 3 && strcmp(argv[1], "-g") == 0)
    {
        strncpy(command, "curl https://dweet.io/get/latest/dweet/for/", 512);
        strncat(command, argv[2], 512);
        command[strcspn(command, "\r\n")] = 0;
    }
    //Modalità post
    else if (argc == 5 && strcmp(argv[1], "-p") == 0)
    {

        strncpy(command, "curl https://dweet.io/dweet/for/", 512);
        strncat(command, argv[2], 512);
        command[strcspn(command, "\r\n")] = 0;
        strncat(command, "?",512);
        strncat(command, argv[3], 512);
        command[strcspn(command, "\r\n")] = 0;
        strncat(command, "=",512);
        strncat(command, argv[4], 512);
        command[strcspn(command, "\r\n")] = 0;
    }

    else
    {
        printf("dweet_client usage: dweet_client OPTIONS \n");
        printf("OPTIONS:\n");
        printf("-i: interactive mode\n");
        printf("-p: post a value to dweet.io\n");
        printf("\tExample:\n");
        printf("\t dweet_client -p thing_name name value\n");
        printf("-g: get values from dweet.io and output them\n");
        printf("\tExample:\n");
        printf("\t dweet_client -g thing_name\n");
        return 1;
    }
    printf("%s\n",command);
    system(command);
    return 0;
}
