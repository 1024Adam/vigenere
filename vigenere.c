#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * cipherString(char * keyword, char * text);
char * decipherString(char * keyword, char * text);

int main(int argc, char * * argv)
{
    char * cipherText = NULL;
    
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

char * cipherString(char * keyword, char * text)
{
    int i = 0;
    int j = 0;
    int counter = strlen(keyword);
    int len = strlen(text);
    int move = 0;    
    char * cipherText = malloc(sizeof(char) * (len + 1));
    char newChar = '0';
    
    j = 0;
    for(i = 0; i < len; i++)
    {
        move = keyword[j] - 'a';
        /*printf("move - %d\n", move);*/
        newChar = text[i] + move;
        /*printf("newChar = %c\n", newChar);*/
        if((text[i] >= 'a' && text[i] <= 'z') && (newChar > 'z'))
        {
            newChar = newChar - 26;
        }
        else
        {
            if((text[i] >= 'A' && text[i] <= 'Z') && newChar > 'Z')
            {
                newChar = newChar - 26;
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
    char newChar = '0';
    
    j = 0;
    for(i = 0; i < len; i++)
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
