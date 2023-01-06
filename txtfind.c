#include <stdio.h>
#include <string.h>
#define LINE 256
#define ROW 250
#define WORD 30
int getline_1(char s[])
{
	char get='\0';
	int i=0, ret = 0;

	while (i < LINE)
	{
		ret = scanf("%c",&get);

		if (ret == -1)
		{
			*(s+i)='\0';
			break;
		}

        else if (get == '\n')
		{ 
			*(s+i) = '\0';
			break;
		}


        *(s+i) = get;
        i++;
	}

	return i;
}



int getword(char w[])
{
	char get='\0';
	int i=0, ret = 0;

	while (i < WORD)
	{
		ret = scanf("%c",&get);
		if (ret == -1)
		{
			*(w+i)='\0';
			break;
		}

		else if ((get == ' ') || (get == '\t') || (get == '\n'))
		{
			*(w+i)='\0';
			break;
		}

		*(w+i)=get;
		i++;
	}

	return i;
}



int substring (char * str1 , char * str2) {
    int bool = 1;
    int counter = 0;
    if (strlen(str2) > strlen(str1)) {
        return 0;
    }
    for (int i = 0; i < strlen(str1);i++) {
        if (*(str2 + counter) == *(str1 + i) && (bool == 1)) {
            counter++;
             if (counter == strlen(str2)) {
             return 1;
            }
        }
        else if (*(str2 + counter) == *(str1 + i) && (bool == 0)) {
            counter++;
            bool = 1;
        }
        else if (*(str2 + counter) != *(str1 + i)) {
            bool = 0;
            counter = 0;
        }
    }
   return 0;
}


int similar (char * s, char * t, int n){
    int j = 0;

    if (strlen(s) - strlen(t) != n) {
        return 0;
    }

    for (int i = 0 ; i < strlen(s) && j < strlen(t); i++) {
        if (*(s + i) == *(t + j)){
            j++;
        }
    }

    return j == strlen(t);
}


void print_lines(char * str)
{
    char s[LINE];

    while(getline_1(s))
    {
        if(substring(s,str))
        {
            printf("%s\n",s);
        }
    }
}


void print_similar_words(char * str)
{
    char s[WORD];

    while(getword(s))
    {
        if(similar(s,str,1) || similar(s,str,0))
        {
            printf("%s\n",s);
        }
    }
}



int main()
{   
    char word[WORD] = {0};
    char option = '\0';

    getword(word);
    scanf(" %c\n", &option);

    if(option=='a')
    {
        print_lines(word);
    }

    else
    {
        print_similar_words(word);
    }

   return 0;
}