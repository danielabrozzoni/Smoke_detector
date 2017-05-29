/*
  Copyright (C) 2010 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

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
 *  \brief Esempio di utilizzo della porta seriale per la lettura
 *  Questa versione non è portabile ed è relativa unicamente al S.O. Windows.
 *  Riferimenti: Serial port programming in Windows and linux, Maxwell Walter, 2003
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione  26/05/2010
 *  \date  Ultima modifica 26/05/2010
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SIZE 1024

char dataIn[SIZE];


void dweet(int key, int dato)
{
    const char nomeDweet[] = "Alternanza_Brozzoni_Brunelli_Trevisan";
    char buffer[32];
    char command[512];
    strncpy(command,"curl https://dweet.io/dweet/for/",512);
    strncat(command,nomeDweet,512);
    strncat(command,"?",512);
    itoa(key,buffer,10);
    strncat(command,buffer,512);
    strncat(command,"=",512);
    itoa(dato,buffer,10);
    strncat(command,buffer,512);
    system(command);
    printf("%s\n", command);
}

int main()
{
    FILE *out;
    out = freopen("dati.txt", "w", stdout);
    HANDLE com;
    com = COM_open(3, '0', 9600, 'n', 8, 1, 'n');
    if (com == -1)
    {
        printf("Apertura della seriale fallita\n");
        return 1;
    }
    int read, i=0;
    while(1)
    {
        read = COM_read(com,dataIn,100);
        if (read != -1)
        {
            dataIn[read]='\0';
            //printf("%d byte letti\n%s \n",read,dataIn);
            //printf("%s",dataIn);
            int n = atoi(dataIn);
            //printf("%d\n", n);
            i++;
            dweet(i,n);
            //delay(1000);

        }
        else
            printf("Timeout\n");
        read = 0;
    }
    COM_close(com);
    return 0;

}
