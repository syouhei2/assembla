#include<stdio.h>
#include<math.h>
#include<stdlib.h>

main(int argc, char **argv)
{

  /*argment error*/
  if(argc != 2){
    printf("usage: .txt\n");
    return;
  }

  FILE *fd;
  int c,v;

   /*get input file discripter*/
  fd = fopen(argv[1],"rt");
  if(fd == NULL){
    perror(argv[2]);
    return;
  }

  int cnt = 0;
  int i,j;
  while(1){
    for(i=0;i<4;i++){
      v = 0;

      for(j=0;j<8;j++){
        c = fgetc(fd);
        if(c == EOF) break;
        else if(c == 49) v += (int)pow(2,(double) (7 - j));
      }
      if(c == EOF) break;
      printf("0x%02X ",v);
    }
    if(c == EOF) break;
    printf("\n");
  }
  fclose(fd);
  return;
}
