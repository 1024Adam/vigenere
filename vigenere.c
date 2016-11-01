#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * cipherString(char * keyword, char * text);
char * decipherString(char * keyword, char * text);

int main(int argc, char * * argv)
{
    char * cipherText = NULL;
    
    if(argc < 3 || (strcmp(argv[1], "-d") == 0 && argc < 4))
    {
        printf("Error: Invalid number of arguments. Please see documentation.\n");
    }    
    else
    {
        if(strcmp(argv[1], "-d") == 0)
        {
            cipherText = decipherString(argv[2], argv[3]);
            /*printf("%s\n", argv[3]);*/
        }
        else 
        {
            cipherText = cipherString(argv[1], argv[2]);
            /*printf("%s\n", argv[2]);*/
        }

        printf("%s\n", cipherText);

        free(cipherText);
    }
    return(0);
}

char * cipherString(char * keyword, char * text)
{
    int i = 0;
    int j = 0;
    int counter = strlen(keyword);
    int len = strlen(text);
    int move = 0;    
    char * cipherText = malloc(sizeof(char) * (len + 1));
    unsigned char newChar = '0';
    
    j = 0;
    for(i = 0; i < len; i++)
    {
        if(!((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')))
        {
           newChar = text[i];
        }
        else
        {
            move = keyword[j] - 'a';
            /*printf("move - %d\n", move);*/
            newChar = text[i] + move;
            /*printf("newChar = %c %d\n", newChar, newChar);*/
            if((text[i] >= 'a' && text[i] <= 'z') && (newChar > 'z'))
            {
                /*printf("%c 1\n", text[i]);*/
                newChar = newChar - 26;
            }
            else
            {
                if((text[i] >= 'A' && text[i] <= 'Z') && newChar > 'Z')
                {
                    /*printf("%c 2\n", text[i]);*/
                    newChar = newChar - 26;
                }
            }
        }
        cipherText[i] = newChar;
        j++;
        if(j >= counter)
        {
            j = 0;
        }    
    }
    cipherText[i] = '\0';

    return(cipherText);
}

char * decipherString(char * keyword, char * text)
{
    int i = 0;
    int j = 0;
    int counter = strlen(keyword);
    int len = strlen(text);
    int move = 0;    
    char * cipherText = malloc(sizeof(char) * (len + 1));
    unsigned char newChar = '0';
    
    j = 0;
    for(i = 0; i < len; i++)
    {
        if(!((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')))
        {
           newChar = text[i];
        }
        else
        {
            move = keyword[j] - 'a';
            /*printf("move - %d\n", move);*/
            newChar = text[i] - move;
            /*printf("newChar = %c\n", newChar);*/
            if((text[i] >= 'a' && text[i] <= 'z') && (newChar < 'a'))
            {
                newChar = newChar + 26;
            }
            else
            {
                if((text[i] >= 'A' && text[i] <= 'Z') && newChar < 'A')
                {
                    newChar = newChar + 26;
                }
            }
        }
        cipherText[i] = newChar;
        j++;
        if(j >= counter)
        {
            j = 0;
        }    
    }
    cipherText[i] = '\0';

    return(cipherText);
}
