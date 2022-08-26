#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define Filename "hexfile.txt"
#define MAXLENGTH 300
#define HEXPERLINE 16

void printLine(char *strLine, int nLength);

int currentLine = 0, currentLineHexIndex = 0;

int main(int argc, char *argv[]) {
    FILE *fptr;
    char strLogFile[MAXLENGTH] = Filename;
    unsigned char strLine[MAXLENGTH];

    fptr = fopen(strLogFile, "r");
    if (fptr == NULL)
    {
        printf("Error opening file: %s", strLogFile);
        exit(1);
    }

    // display hex file to the screen
    while (fgets(strLine, MAXLENGTH, fptr) != NULL)
    {
        printLine(strLine, strlen(strLine));
    }
    fclose(fptr);
    return 0;
}

void printLine(char *strLineRaw, int strLineLength) {
    if (strLineRaw[0] != ':')
    {
        return;
    }
    currentLine++;
    unsigned char strLine[MAXLENGTH] = {};
    if (currentLine > 1)
    {
        char str2DOT[] = {'.', '.'};
        strcat(strLine, str2DOT);
    }
    strcat(strLine, strLineRaw);
    unsigned char strTemp[17];
    for (int i = 0; i < strLineLength - 1;)
    {
        strTemp[currentLineHexIndex + 1] = strLine[i];
        printf("%02x ", strLine[i++]);
        currentLineHexIndex++;
        if (currentLineHexIndex > 15)
        {
            printf("    ");
            for (int j = 1; j <= HEXPERLINE; j++)
            {
                printf("%c", strTemp[j]);
            }
            currentLineHexIndex = 0;
            printf("\n");
        }
    }
}
