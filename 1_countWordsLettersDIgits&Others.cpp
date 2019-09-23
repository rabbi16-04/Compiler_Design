#include<stdio.h>
#include <string.h>

char str[1000],letter[1000],digit[1000];  //,others[1000];
int mark[300];

int is_digit(char ch){
    if(ch>='0'&&ch<='9') return 1;
    return 0;
}

int is_char(char ch){
    if(ch>='A'&&ch<='Z') return 1;
    if(ch>='a'&&ch<='z') return 1;
    return 0;
}

void Count()
{
    int word_count=1,letter_count=0,digit_count=0 ,others=0;;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==' '&&(is_char(str[i+1])||is_digit(str[i+1])))
        {
           word_count++;
        }
        if(is_char(str[i])) letter_count++;

        if(is_digit(str[i])) digit_count++;

        if(!is_char(str[i]) && !is_digit(str[i])) others++;
    }
    printf("Number of word : %d\n",word_count);
    printf("Number of letter : %d\n",letter_count);
    printf("Number of digit : %d\n",digit_count);
   // printf("Number of others letter : %d\n",others);
}

/*void  separates_letter()
{
    int init=0;
    for(int i=0;i<strlen(str);i++)
    {
        int x=str[i];
        if(is_char(str[i]) && mark[x]==0)
        {
            letter[init++]=str[i];
            mark[x]=1;
        }
    }

    printf("%s\n",letter);
}

void separates_digit()
{
    int init=0;
    for(int i=0;i<strlen(str);i++)
    {
        int x=str[i];
        if(is_digit(str[i]) && mark[x]==0)
        {
            digit[init++]=str[i];
            mark[x]=1;
        }
    }

    printf("%s\n",digit);
}

void separates_others()
{
    int init=0;
    for(int i=0;i<strlen(str);i++)
    {
        int x=str[i];
        if(!is_char(str[i])  && !is_digit(str[i]) && mark[x]==0)
        {
            others[init++]=str[i];
            mark[x]=1;
        }
    }

    printf("%s\n",others);
}*/

int main()
{
    scanf("%[^\n]",str);

    Count();

   /* printf("Separate letter : ");
    separates_letter();

    printf("Separate digit : ");
    separates_digit();

    printf("Separate others : ");
    separates_others();*/
}
