#include <dirent.h> 
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void ls(const char *dir,int a, int l){
  struct dirent *d;

  DIR *directory= opendir(dir);
  if (!directory){
    if (errno == ENOENT){
      perror("Ooops... Didn't find directory");
    }
    else{
      perror("Ooops... Didn't able to read directory");

    }
    exit(EXIT_FAILURE);
  }
 while(( d = readdir(directory))!= NULL){
   if (!a && d->d_name[0]=='.')
   continue;
   printf("\n%s ", d->d_name);
 }
}
int main(int tempC, const char *tempV[]){
  if(tempC == 1)
  ls(".",0,0);
  else if(tempC == 2){
    if (tempV[1][0] == '-'){
      int a = 0, l = 0;
      char *p = (char*)(tempV[1]+1);
      ls(".", a, l);
    }
  }
  return 0;
}