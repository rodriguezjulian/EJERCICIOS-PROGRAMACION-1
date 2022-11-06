#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char lastName[51];
	float salary;
	int sector;
}ePractica;


int main(void) {
	setbuf(stdout, NULL);
	FILE *bin;
	ePractica* pPuntero;
	int cant;
	int r;
	char var1,var2,var3,var4;
	if ((bin=fopen("data - data.csv","r"))!=NULL)
	{
		while(!feof(bin))
		{
			//cant=fread(&pPuntero,sizeof(pPuntero),1,bin);
			if(cant!=1)
			{
				r = fscanf(bin,"%s[^,],%s[^,],%s[^,],%s[^\n]\n",var1,var2,var3,var4);
				if(r==4)
				{
					printf("Lei: %s %s %s %s\n",var1,var2,var3,var4);
				}

				//printf("\n%d\t%s\t%f\t%d\n",pPuntero->id,pPuntero->lastName,pPuntero->salary,pPuntero->sector);
			}
		}
		fclose(bin);
	}
	else
	{
		printf("No se pudo abrir el archivo");
		exit(1);
	}

	return 0;
}


