#include history.h
#include <stdio.h>
#include <stdlib>

List* init_history(){
  List *list = (List*) malloc (sizeof(List));
  list->root = NULL;
  return list;
}

