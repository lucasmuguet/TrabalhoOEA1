#include <stdio.h>
#include <string.h>

struct _Endereco{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};
typedef struct _Endereco Endereco;

int main(int argc, char**argv){.
	FILE *f;
	Endereco e;
	int i=0,c=0,fn,m;
  long t;
	if(argc != 2){
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}

	f = fopen("cep.dat","r");
	fseek(f,0,SEEK_END);
  t=ftell(f);
  fn=t/sizeof(Endereco);

	while(i<=fn){
		c++;
    m=(i+fn)/2;
    fseek(f,m*sizeof(Endereco),SEEK_SET);
    fread(&e, sizeof(Endereco),1,f);
    if(strncmp(argv[1],e.cep,8)==0){
      printf("Posição atual: %ld",ftell(f));
      return 1;
    }else{
      if(strncmp(argv[1],e.cep,8)<0){
        fn=m-1;
      }else{
        i=m+1;
      }
    }
	}
	printf("Total Lido: %d\n", c);
	fclose(f);
}