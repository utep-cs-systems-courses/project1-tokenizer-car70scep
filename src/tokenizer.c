#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c){
  if (c == ' ' || c == '\t'){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c != ' ' || c != '\t'){
    return 1;
  }
  return 0;
}




char *word_start(char *str){
  while(space_char(*str)){
    str++;
  }
  return str;
}

char *word_terminator(char *word){
  while (non_space_char(*str)){
    str++;
  }
  return str;
}

int count_words(char *str){
  int temp = 0;
  char *start;
  char *end;
  while(*str != '\0'){
    start = word_start(str);
    end = word_terminator(start);
    str = end;//starts new word 
    str++;
    temp++;
  }
  return temp;
}

char *copy_str(char *inStr, short len){

  char *newStr = (char*)malloc((len) * sizeof(char));
  //allocates memory using the size of a char * len
  for(int i = 0; i < len; i++){
    newStr[i] = inStr[i];//Creates the new String 
  }
  return newStr;
}

char **tokenize(char* str){
  char +start,*end;
  int totalW = count_words(str);
  char **tokens = (char**) malloc (sizeof(char*) * (totalW));

  for (int i = 0; i<totalW; i++){
    start = word_start(str);
    end = word_terminator(start);
    len = end - start;
    tokens[i] = copy_str(start,len);
    str = end;
    str++;
  }
  tokens[i] = '\0';
  return tokens
 }

void print_tokens(char **tokens){
  while(*tokens != 0){
    printf("%s ", *tokens);
    tokens++;
  }
}

void free_tokens (char **tokens){
  while (*tokens != 0){
    free(*tokens);
    tokens++;
  }
}






  



  
