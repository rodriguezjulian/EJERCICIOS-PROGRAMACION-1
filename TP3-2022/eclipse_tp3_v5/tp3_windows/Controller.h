int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);

int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* listaJugadoresBinario,LinkedList* pArrayListSeleccion);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);



int controller_agregarJugador(LinkedList* pArrayListJugador, int* idMax);
int controller_editarJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int controller_listarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);



int controller_listar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);


int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);




int controller_editarSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);


void jug_MostrarNacionalidades(void);


int jug_guardarJugadores(LinkedList* pArrayListSeleccion, char* nombreConfederacion, LinkedList* pArrayListJugador, char* path);



int controller_guardarMaxId(char* path, int maxId);

int controller_Salir(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador ,LinkedList* pArrayListJugadorOriginal, int idMax);
//int controller_Salir(LinkedList* pArrayListSeleccion ,LinkedList* pArrayListJugador);
