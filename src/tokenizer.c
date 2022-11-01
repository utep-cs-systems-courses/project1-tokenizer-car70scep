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


char *word_start(char *str){
  while(space_char(*str)){
    str++;
  }
  return str;
}

char *word_terminator(char *word){
  while (non_space_char(*word)){
    word++;
   
  }
  return word;
}

int count_words(char *str){
  int totalW = 0;
  for (int i =0; str !=word_terminator(str);i++){
    totalW++;
    str = word_terminator(str);
  }
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
  char **tokens = malloc (sizeof(char*) * (totalW));
  char *start = word_start(str);
  char *end = word_terminator(str);
  int i;
  for (i = 0; i<totalW; i++){
    tokens[i] = copy_str(start,end-start);
    start = word_start(end);
    end = word_terminator(start);
  }
  tokens[i] = 0;
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






  



  
