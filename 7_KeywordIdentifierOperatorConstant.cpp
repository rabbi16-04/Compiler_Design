#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<fstream>
#include <ctype.h>

int isKeyword(char buffer[]){
    char keywords[63][20]={"asm","else", "new", "this", "auto", "enum", "operator", "throw", "bool", "explicit",
	                    "private",	"true", "break", "export", "protected", "try", "case", "extern", "public",
                        "typedef", "catch", "false", "register", "typeid", "char", "float", "reinterpret_cast",
                        "typename", "class", "for",	"return", "union", "const",	"friend", "short", "unsigned",
                        "const_cast", "goto", "signed", "using", "continue", "if", "sizeof", "virtual",
                        "default",	"inline",	"static",	"void", "delete",	"int",	"static_cast",	
                        "volatile", "do",	"long",	"struct",	"wchar_t", "double",	"mutable",	"switch",
                        "while", "dynamic_cast",	"namespace",	"template"}; 

    int i, flag = 0; 
    for(i = 0; i < 63;i++){
        if(strcmp(keywords[i],buffer) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

int isConst(char buffer[]){
    int i;
    int size_ = strlen(buffer);
    int count = 0;
    for(i = 0;i < size_; i++){
        count += isdigit(buffer[i]);
    }
    if(count == size_)
        return 1;
    else
        return 0;
}

int main(){
    char ch,buffer[20],operators[] = "+-*/%=";
    int i,j = 0;
    FILE *fp;
    fp = fopen("in.txt","r");

    if(fp == NULL){
		printf("error while opening the file\n");
		exit(0);
	}
    while((ch = fgetc(fp)) != EOF){
        for(i = 0;i<6;i++){
            if(ch == operators[i]){
                printf("%c is a operator\n",ch);
            }
        }
        if(isalnum(ch)){
            buffer[j++] = ch;
        }
        else if(ch == ' ' || ch == '\n' && j != 0){
            buffer[j] = '\0';
            j = 0;

            if(isKeyword(buffer)){
                printf("%s is a Keyword\n",buffer);
            }
            else{
                if(buffer[0] < '0' || buffer[0] > '9'){
                    printf("%s is a Identifier\n",buffer);
                }
                else{
                    if(isConst(buffer)){
                        printf("%s is Constant\n",buffer);    
                    }
                    else{
                        printf("%s is not determined by c++\n",buffer);
                    }
                }
            }
        }
    }
    fclose(fp);

    return 0;
}
