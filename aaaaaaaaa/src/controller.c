int controllerCargarArchivoDesdeTexto(LinkedList* listaDeCompras)
{
	int retorno=-1;
	//char nombreArchivo[200];
	FILE* pFile=NULL;

	//do
	//{
		//ingreseNombreArchivo("Ingrese nombre del archivo que desea cargar.\n", nombreArchivo);
		pFile=fopen("data.csv", "r");
		if(pFile!=NULL)
		{
			parserCompraDesdeTexto(pFile, listaDeCompras);
			if(parserCompraDesdeTexto(pFile, listaDeCompras)!=0)
			{

				printf("ERROR AL CARGAR EL ARCHIVO");
			}}
		}
		else
		{
				printf("<<<<<<<<< ARCHIVO CARGADO SATISFACTORIAMENTE >>>>>>>>>>\n");
				retorno=0;
		}


		if(retorno!=0)
		{
			printf("ERROR,Ingrese nombre de archivo valido.\n");
		}
		fclose(pFile);
	}while(retorno!=0);
	return retorno;
}
