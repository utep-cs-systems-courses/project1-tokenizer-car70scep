#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c){
  if (c == ' ' || c == '\t'&& c != '\0' ){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c != ' ' && c != '\t'&& c == '\0'){
    return 1;
  }
  return 0;
}

char *word_start(char *str)

{

  while (*str != '\0') {

    if (non_space_char(*str))

      return str;

    str++;

  }

  return NULL;

}



char *word_terminator(char *word)

{

  while (*word != '\0') {

    if (space_char(*word))

      return word;

    word++;

  }

  return word;

}

int count_words(char *str){
  int totalW = 0;
  do{
    if(str=word_start(str)) totalW++;
    else break;
  } while(str=word_terminator(str));
  
  return totalW;
}

char *copy_str(char *inStr, short len){

  char *newStr = (char*)malloc((len+1) * sizeof(char));//+1 for the null terminator 
  //allocates memory using the size of a char * len
  int i;
  for( i = 0; i < len; i++){
    newStr[i] = inStr[i];//Creates the new String 
  }
  newStr[i] = '\0';
  //exactly what you did with tokens[i]='\0';
  return newStr;
}

char **tokenize(char *str){
  int totalW = count_words(str);
  char **tokens = (char **) malloc ((totalW + 1) * sizeof(char *));
  char *start = word_start(str);
  char *end;
  int i;
  for (i = 0; i<totalW; i++){
    end = word_terminator(str=word_start(str));
    tokens[i] = copy_str(start,end-str);
    str = end;
  }
  tokens[i] = NULL;
  return tokens;
 }

void print_tokens(char **tokens){
  int counter=0;
  while(tokens[counter] != 0){
    printf("[%d] %s\n", tokens[counter]);
    counter++;
  }
}

void free_tokens (char **tokens){
  while (*tokens != 0){
    free(*tokens);
    tokens++;
  }
  free(tokens);
}






  



  
