/**
 * @file test_cesar.c
 * @author Alex Neault (NEAA02089809)
 * @brief Programme en C qui permet de faire le déchiffrement de césar
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "cesar.h"

int main(int argc, char *argv[]){
   int status=0;
   if(argc==1){
      printf("%s",USAGE);
      status=1;
   }
   else if (argc!=3){
      printf("Il doit y avoir exactement deux arguments\n");
      status=1;
   }
   else{
      FILE *file = open_file(argv[1],"r");
      char *lines[CHAR_MAX];
      check_file(file); 
      fclose(file);
      file = open_file(argv[1],"r");
      int nb_element=store_file(file,lines);
      transform(lines,nb_element);
      fclose(file);
      FILE *file_write = open_file(argv[2],"w");
      write_to_file(file_write,lines,nb_element);
      fclose(file_write);  
   }
   return status;
}