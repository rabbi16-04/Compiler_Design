#include<stdio.h>
#include<string.h>
char str[10][10]={"auto","break","for","while","case","char","int","do","case","void"};
int main()
{
    char ch[10000];

    while(gets(ch))
    {
        int c=0,keyword=0,Int=0,Float=0,Air=0;
        for(int i = 0; i < 10; i++) {
               if(strcmp(ch, str[i]) == 0) {
                        keyword=1;
                        break;
               }
        }
        if(keyword==1) printf("Keyword\n");
        else {
            int len=strlen(ch);
            for(int i=0;i<len;i++)
            {
                if(ch[i]=='+' || ch[i]=='-'|| ch[i]=='*' || ch[i]=='/' || ch[i]=='%') Air++;
                if((ch[i]>='0' && ch[i]<='9') || ch[i]=='.' ) Float++;
                if((ch[i]>='0' && ch[i]<='9')  ) Int++;
            }

            if(Int==len) printf("Integer\n");
            else if(Float==len) printf("Float\n");
            else if(Air==len) printf("Airthmetic Operator\n");
            else{
                printf("Identifer\n");
            }

        }

    }

}
