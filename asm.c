#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define SP 0 //mem addr of the first cmd (/4)


main(int argc, char **argv)
{

  /*argment error*/
  if(argc != 2){
    printf("usage: .txt\n");
    return;
  }

  FILE *fd;
  char buf[256];
  char *tok;
  char *rs,*rt,*rd,*imm;
  char *br;

  uint32_t l;

  char label_set[255][255];
  uint32_t laddr[0xFF];
  int p = 0;
  int addr;

  

   /*get input file discripter*/
  fd = fopen(argv[1],"rt");
  if(fd == NULL){
    perror(argv[2]);
    return;
  }


  /*label sakiyomi*/
  while( fgets(buf,255,fd) != NULL ){
    tok = strtok(buf," \n");

    if ( tok[strlen(tok)-1] == ':' ){
      tok[strlen(tok)-1] = '\0';
      strcpy(label_set[p],tok);
      laddr[p] = SP + l;
      p++;
    } else { 
      l += 1;
    }
  }



  close(fd);

  fd = fopen(argv[1],"rt");
  if(fd == NULL){
    perror(argv[2]);
    return;
  }



  while( fgets(buf,255,fd) != NULL ){

    tok = strtok(buf," \n");

     /*label*/
    if ( tok[strlen(tok)-1] == ':' ){ 
    }
     /*cmd*/
     else if( strcmp(tok,"nop") == 0 ) {
        nop();
      }else if( strcmp(tok,"add") == 0 ){
        add();
      }else if( strcmp(tok,"addi") == 0  ){
        addi();
      }else if( strcmp(tok,"sub") == 0  ){
        sub();
      }else if( strcmp(tok,"j") == 0 ){
        addr = laddr [ mysearch( strtok(NULL,"\n"), label_set, p) ];
        j(addr);
      }
  }

  close(fd);
  return;



}

