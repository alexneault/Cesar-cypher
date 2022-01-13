#include "cesar.h"

// Implementation
// --------------

FILE *open_file(char *filename, char *mode){
    FILE *f;
    f = fopen(filename, mode);
    if(!f)
    {
        perror(filename);
        exit(EXIT_FAILURE);
    }
    return f;
}
void check_file(FILE *file){
   int count=0;
   int line=0;
   char c;
   while(!feof(file)){
      c=fgetc(file);
      count++;
      if(c=='\n'){
         line++;
         count=0;
      }
      if(count>80){
         printf("Une des lignes dépasse 80 caractères dans le fichier\n");
         exit(1);
      }  
   }
}


int store_file(FILE *file,char *lines[]){
   int i = 0;
   char buffer[80][CHAR_MAX];
   while(fgets(buffer[i],sizeof(buffer[i]),file)){ 
      lines[i]=buffer[i];
      i++;
   }
   return i;
}

void transform(char *lines[], int nb_element){
   for (int i=0;i<nb_element;i++){
      for (int j=0;j<strlen(lines[i]);j++){
         char temp_char=lines[i][j];
            if ((temp_char>='A'&& temp_char<='C')||(temp_char>='a'&& temp_char<='c'))
               lines[i][j]+=23;
            else if ((temp_char>='D'&& temp_char<='Z')||(temp_char>='d'&& temp_char<='z')){
               lines[i][j]-=3;
            }
        }
    }
}

void write_to_file(FILE *file, char *line[], int nb_element){
   for(int i =0;i<nb_element;i++){
      fprintf(file, "%s", line[i]);
   }
}
