#include<stdio.h>
#include<string.h>
#include<stdint.h>

#define SP 0 //mem addr of the first cmd

#define NOP  0x00
#define ADD  0x01
#define ADDI 0x02
#define SUB  0x03

void write_bit(uint32_t,int);
uint32_t regn(char *);

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

  uint32_t l;
  char *label_set[0xFF];
  uint32_t laddr[0xFF];
  int p = 0;
  

   /*get input file discripter*/
  fd = fopen(argv[1],"rt");
  if(fd == NULL){
    perror(argv[2]);
    return;
  }


  while( fgets(buf,255,fd) != NULL ){

    tok = strtok(buf," \n");

     /*label*/
    if ( tok[strlen(tok)-1] == ':' ){

      label_set[p] = tok;
      laddr[p] = SP + l;
      p++;

      
    }

     /*cmd*/
     else if( strcmp(tok,"nop") == 0 ) {
        write_bit(NOP,32);
        printf("\n");
      }else if( strcmp(tok,"add") == 0 ){
        rs = strtok(NULL," ");
        rt = strtok(NULL," ");
        rd = strtok(NULL," \n");

        write_bit(ADD,6);
        write_bit(regn(rs),5);
        write_bit(regn(rt),5);
        write_bit(regn(rd),5);
        write_bit(0,11);
        printf("\n");
      }else if( strcmp(tok,"addi") == 0  ){
        rs = strtok(NULL," ");
        rd = strtok(NULL," ");
        imm = strtok(NULL," \n");

        write_bit(ADDI,6);
        write_bit(regn(rs),5);
        write_bit(regn(rd),5);
        write_bit(atoi(&imm[1]),16);
        printf("\n");
      }else if( strcmp(tok,"sub") == 0  ){
        rs = strtok(NULL," ");
        rt = strtok(NULL," ");
        rd = strtok(NULL," \n");

        write_bit(SUB,6);
        write_bit(regn(rs),5);
        write_bit(regn(rt),5);
        write_bit(regn(rd),5);
        write_bit(0,11);
        printf("\n");
      }

    l+=4;
  }

  close(fd);
  return;



}


void write_bit(uint32_t a,int n)
{
  int c;
  unsigned int bit = (1 << (n - 1));

  for ( c=0; c<n; c++,bit>>=1 ){
  if ( a&bit ){
    putchar('1');
  }
  else{
    putchar('0');
  }}


  return;
}

uint32_t regn(char *r)
{


  if(strcmp(r,"%ra") == 0){
    return 31;
  }else {
    return atoi(&r[2]);
  }

}
