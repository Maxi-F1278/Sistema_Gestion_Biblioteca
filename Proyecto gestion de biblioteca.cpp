//LIBRERIAS
#include <iostream>
#include <string>
using namespace std;
 
//CONSTANTES
const int N = 500;
 
//ESTRUCTURAS
struct Categoria{
    int CodCat;
    string DC;};
struct Prestatario{
    int CodPre;
    string Apellidos;
    string Nombres;};
struct Prestamo{
    int CodCat;
    int CodPre;
    string DP;
    bool Estado=true;};
struct NodoPrestamo{
    Prestamo dato;
    NodoPrestamo* siguiente;};
 
//FUNCIONES AUXILIARES
/*PROPOSITO: Realizar el Switch de las Categoria
PARAMETROS:
    AC: Parametro que representa al Arreglo de Categorias en su totalidad
    dlc: Entero vinculado al valor de la dimension logica del Arreglo de Categorias
    caracter: un caracter que es tomado por referencia para editarlo en la funcion invocadora
RETORNO: Void*/
void Switch_Categoria(Categoria AC[N], int dlc){
    /*VARIABLES*/
    char caracter='V'; 
    /*INICIO DEL PROGRAMA*/
    while(caracter!='s' && caracter!='n'){
        cout<<"¿Desea ver las categorias existentes?(S/N)\n";
        cin>>caracter;
        caracter=tolower(caracter);
        switch(caracter){
            case 's':
                cout<<"codigo / descripcion\n";
                for(int i=0;i<dlc;i++){cout<<AC[i].CodCat<<" / "<<AC[i].DC<<endl;};
                break;
            case 'n':
                break;
            default:
                cout<<"Error. el caracter ingresado difiere de S o N. Intente nuevamente.\n";};};
    /*pide al usuario un caracter y realiza un switch cuyos caracteres validos son unicamente s o n, en caso de ser ingresada una s
    realiza un listado de los elementos de la estructura "Categoria" de cada elemento de su arreglo vinculado, de elegirse una n
    simplemente acaba la ejecucion, de no elegirse ninguna de estas 2 opciones procede a tirar un error*/
}
/*PROPOSITO: Realizar el Switch de los Prestatarios
PARAMETROS:
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
    caracter: un caracter que es tomado por referencia para editarlo en la funcion invocadora
RETORNO: Void*/
void Switch_Prestatario(Prestatario AP[N], int dlp){
    /*VARIABLES*/
    char caracter='V'; 
    /*INICIO DEL PROGRAMA*/
    while(caracter!='s' && caracter!='n'){
        cout<<"¿Desea ver los prestatarios existentes?(S/N)\n";
        cin>>caracter;
        caracter=tolower(caracter);
        switch(caracter){
            case 's':
                cout<<"codigo / Nombre/s / Aprellido/s\n";
                for(int i=0;i<dlp;i++){cout<<AP[i].CodPre<<" / "<<AP[i].Nombres<<" / "<<AP[i].Apellidos<<endl;};
                break;
            case 'n':
                break;
            default:
                cout<<"Error. el caracter ingresado difiere de S o N. Intente nuevamente.\n";};};
    /*pide al usuario un caracter y realiza un switch cuyos caracteres validos son unicamente s o n, en caso de ser ingresada una s
    realiza un listado de los elementos de la estructura "Prestatario" de cada elemento de su arreglo vinculado, de elegirse una n
    simplemente acaba la ejecucion, de no elegirse ninguna de estas 2 opciones procede a tirar un error*/
}
/*PROPOSITO: Reescribir a notacion camello
PARAMETROS:
    cadena: es el string original el cual esta funcion reescribe
RETORNO: Void*/
void Reescribir(string &cadena){
    cadena[0]=toupper(cadena[0]);
    for(int i=1;i<cadena.length();i++){
        if(cadena[i-1]==' '){cadena[i]=toupper(cadena[i]);}
        else{cadena[i]=tolower(cadena[i]);};};
    /*Reescribe un string a notacion camello*/
}
 
//FUNCIONES TERCIARIAS
//Administrar Y Consultar Categorias Y Prestatarios
/*PROPOSITO: Agregar una Categoria
PARAMETROS:
    AC: Parametro que representa al Arreglo de Categorias en su totalidad
    dlc: Entero vinculado al valor de la dimension logica del Arreglo de Categorias
RETORNO: Void*/
void Agregar_una_Categoria(Categoria AC[N], int &dlc){
    /*ASIGNACION DE DESCRIPCION*/
        cout<<"Ingrese la descripcion de la nueva categoria:\n";
        getline(cin>>ws,AC[dlc].DC);
    /*ASIGNACION DEL CODIGO DE CATEGORIA*/
        if(dlc==0){AC[dlc].CodCat=0;}
        else{AC[dlc].CodCat=AC[dlc-1].CodCat+1;};
    /*INCREMENTO DE LA DIMENSION LOGICA*/
        dlc++;
        /*la funcion agrega una categoria insertando un parametro a la vez para luego subir la dimension logica*/
}
/*PROPOSITO: Modificar Categoria
PARAMETROS:
    AC: Parametro que representa al Arreglo de Categorias en su totalidad
    dlc: Entero vinculado al valor de la dimension logica del Arreglo de Categorias
RETORNO: Void*/
void Modificar_Categoria(Categoria AC[N], int dlc){
    /*VARIBLES*/
        int cod; //CODIGO DE CATEGORIA QUE INGRESA EL USUARIO
        bool val=true; //BOOLEANO UTILIZADO EN LA VALIDACION DEL CODIGO INGRESADO POR EL USUARIO
    /*INICIO DEL PROGRAMA*/
        do{
    /*MUESTREO DE CATEGORIAS EXISTENTES*/
        Switch_Categoria(AC, dlc);
        cout<<"ingrese el codigo de la categoria a modificar:";
        cin>>cod;
    /*VALIDACION*/
        for(int i=0;i<dlc;i++){
            if(cod==AC[i].CodCat){
                cod=i;
                val=false;
                break;};};
        if(val){cout<<"\nError: el codigo de categoria ingresado no corresponde a ninguna categoria\n";}
        else{
    /*MODIFICACION*/
            cout<<"\ningrese la nueva descripcion para la categoria:";
            getline(cin>>ws,AC[cod].DC);};
        }while(val);
        /*la funcion le da la opcion al usuario de elegir si desea ver los datos de las categorias existentes, para luego de recibir
        una s o una n proceda a pedir que el usuario ingrese el codigo de la categoria que desea modificar. al validar la opcion esta
        guarda la posicion en el arreglo de la categoria elegida y le pide al usuario que ingrese la nueva descripcion, impidiendo que
        esta pueda quedar vacia*/
}
/*PROPOSITO: Eliminar Categoria
PARAMETROS:
    Listado: Lista de prestamos 
    AC: Parametro que representa al Arreglo de Categorias en su totalidad
    dlc: Entero vinculado al valor de la dimension logica del Arreglo de Categorias
RETORNO: Void*/
void Eliminar_Categoria(NodoPrestamo* Listado, Categoria AC[N], int &dlc){
    /*VARIBLES*/
        int cod; //CODIGO DE CATEGORIA QUE INGRESA EL USUARIO
        bool val=true; //BOOLEANO UTILIZADO EN LA VALIDACION DEL CODIGO CATEGORIA INGRESADO POR EL USUARIO
        bool val2=true; //BOOLEANO UTILIZADO EN LA VALIDACION ENTRE CODIGO CATEGORIA EN EL ARREGLO Y EL INGRESADO POR EL USUARIO
    /*INICIO DEL PROGRAMA*/
        do{
        Switch_Categoria(AC, dlc);
        cout<<"ingrese el codigo de la categoria a eliminar:";
        cin>>cod;
    /*VALIDACION*/
        for(int i=0;i<dlc;i++){
            if(AC[i].CodCat==cod){
                val=false;cod=i;
                break;};};
        if(val){cout<<"\nError: el codigo de categoria ingresado no corresponde a ninguna categoria\n";}
        else{
    /*ELIMINACION*/        
            while(Listado!=nullptr){
                if(AC[cod].CodCat==Listado->dato.CodCat){
                    cout<<"\nLa categoría no puede eliminarse debido a que tiene préstamos vinculados\n";val2=false;break;};
                Listado=Listado->siguiente;};
            if(val2){
                for(int i=cod;i<dlc-1;i++){
                    AC[i]=AC[i+1];};
            /*DECREMENTO DE LA DIMENSION LOGICA*/
                dlc--;};};
        }while(val);
    /*la funcion le pregunta al usuario si desea ver un listado de las categorias existentes para que, despues de que resiva una s o una n
    proceda a pedirle el codigo de la categoria que desea eliminar, el programa valida el numero y de ser correcto y de no tener Prestamos
    vincluados procede a eliminarlo para finalizar reduciendo la dimension logica*/
}
/*PROPOSITO: Agregar Prestatario
PARAMETROS:
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
RETORNO: Void*/
void Agregar_Prestatario(Prestatario AP[N], int &dlp){
    /*AGREGADO DE NOMBRES*/
        cout<<"Ingrese el/los nombre/s del nuevo prestatario:\n";
        getline(cin>>ws,AP[dlp].Nombres);
        Reescribir(AP[dlp].Nombres);
    /*AGREGADO DE APELLIDOS*/    
        cout<<"Ingrese el/los apellido/s del nuevo prestatario:\n";
        getline(cin>>ws,AP[dlp].Apellidos);
        Reescribir(AP[dlp].Apellidos);
    /*AGREGADO DE CODIGO DE PRESTATARIO*/    
        if(dlp==0){
            AP[0].CodPre=0;}
        else{
            AP[dlp].CodPre=AP[dlp-1].CodPre+1;};
    /*INCREMENTO DE LA DIMENSION LOGICA PRESTATARIO*/
        dlp++;
        /*la funcion le pide al usuario los nombres y apellidos del nuevo prestatario y utiliza una funcion auxiliar para reescribirlos
        en notacion camello para despues asignar el codigo de prestatario en base al anterior (o cero de ser el primer elemento) y
        aumentar la dimension logica*/
}
/*PROPOSITO: Modificar Prestatario
PARAMETROS:
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
RETORNO: Void*/
void Modificar_Prestatario(Prestatario AP[N], int dlp){
    /*VARIBLES*/
        int cod; //CODIGO DE PRESTATARIO QUE INGRESA EL USUARIO
        bool val=true; //BOOLEANO UTILIZADO EN LA VALIDACION DEL CODIGO INGRESADO POR EL USUARIO
    /*INICIO DEL PROGRAMA*/
        do{
        Switch_Prestatario(AP, dlp);
        cout<<"ingrese el codigo del prestatario a modificar:";
        cin>>cod;
    /*VALIDACION*/
        for(int i=0;i<dlp;i++){
            if(AP[i].CodPre==cod){
                cod=i;
                val=false;
                break;};};
        if(val){cout<<"\nError: el codigo de prestatario ingresado no corresponde a ningun prestatario\n";}
        else{
    /*MODIFICACION DEL PRESTATARIO*/
            cout<<"\ningrese el/los nombre/s del prestatario:";
            getline(cin>>ws,AP[cod].Nombres);
            Reescribir(AP[cod].Nombres);
            cout<<"\ningrese el/los apellido/s del prestatario:";
            getline(cin>>ws,AP[cod].Apellidos);
            Reescribir(AP[cod].Apellidos);};
        }while(val);
    /*la funcion pregunta al usuario si desea ver un listado de prestatarios actuales para que despues de que responda "s o n" proceda a
    pedirle el codigo del prestatario a modificar para luego de validarlo proceda a pedirle los nuevos nombres y apellidos, usando una
    funcion auxiliar para reescribirlos en notacion camello*/
}
/*PROPOSITO: Eliminar Prestatario
PARAMETROS:
    Listado: Lista de prestamos 
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
RETORNO: Void*/
void Eliminar_Prestatario(NodoPrestamo* Listado, Prestatario AP[N], int &dlp){
    /*VARIBLES*/
        int cod; //CODIGO DE PRESTATARIO QUE INGRESA EL USUARIO
        bool val=true; //BOOLEANO UTILIZADO EN LA VALIDACION DEL CODIGO INGRESADO POR EL USUARIO
        int val2=true; //BOOLEANO UTILIZADO EN LA VALIDACION ENTRE CODIGO PRESTATARIO EN EL ARREGLO Y EL INGRESADO POR EL USUARIO
    /*INICIO DEL PROGRAMA*/
        do{
    /*MUESTREO DE PRESTATARIOS*/
        Switch_Prestatario(AP, dlp);
        cout<<"ingrese el codigo del prestatario a eliminar:";
        cin>>cod;
    /*VALIDACION*/
        for(int i=0;i<dlp;i++){if(AP[i].CodPre==cod){
            cod=i;val=false;
            break;};};
        if(val){
            cout<<"\nError: el codigo de prestatario ingresado no corresponde a ningun prestatario\n";}
        else{
    /*ELIMINACION DE PRESTATARIO*/
            while(Listado!=nullptr){
                if(AP[cod].CodPre==Listado->dato.CodPre){
                    cout<<"\nEl prestatario no puede eliminarse debido a que tiene préstamos vinculados\n";val2=false;break;};
                Listado=Listado->siguiente;};
            if(val2){
                for(int i=cod;i<dlp-1;i++){
                    AP[i]=AP[i+1];};
    /*DECREMENTO DE LA DIMENSION LOGICA*/            
                dlp--;};};
        }while(val);
    /*la funcion pregunta al usuario si desea ver un listado de prestatarios actuales para que despues de que responda "s o n" proceda a
    pedirle el codigo del prestatario a eliminar para que luego de validarlo y de revisar que dicho prestatario no tenga prestamos pendientes
    proceda a eliminarlo y a reducir la dimension logica*/
}
//Administrar Prestamos
/*PROPOSITO: Agregar Prestamo
PARAMETROS:
    Listado: Lista de prestamos 
    AC: Parametro que representa al Arreglo de Categorias en su totalidad
    dlc: Entero vinculado al valor de la dimension logica del Arreglo de Categorias
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
RETORNO: Void*/
void Agregar_Prestamo(NodoPrestamo*&Listado, Categoria AC[N], int dlc, Prestatario AP[N], int dlp){
    /*VARIABLES*/
        int cod; //CODIGO DE CATEGORIA QUE INGRESA EL USUARIO
        bool val=true; //BOOLEANO UTILIZADO EN LA VALIDACION DEL CODIGO INGRESADO POR EL USUARIO
    /*INICIO DEL PROGRAMA*/
        NodoPrestamo* nuevo= new NodoPrestamo;
        nuevo->siguiente= Listado;
        Listado=nuevo;
        do{
    /*MUESTREO DE LAS CATEGORIAS*/
        Switch_Categoria(AC, dlc);
        cout<<"ingrese el codigo de la categoria a la cual pertenece el prestamo:";
        cin>>cod;
    /*VALIDACION*/
        for(int i=0;i<dlc;i++){
            if(AC[i].CodCat==cod){
                val=false;
                break;};};
        if(val){
            cout<<"\nError: el codigo de categoria ingresado no corresponde a ninguna categoria\n";}
        else{
        Listado->dato.CodCat=cod;};
        }while(val);
        do{
    /*MUESTREO DE LOS PRESTATARIOS*/
        Switch_Prestatario(AP, dlp);
        cout<<"ingrese el codigo del prestatario vinculado al prestamo:";
        cin>>cod;
    /*VALIDACION*/
        for(int i=0;i<dlp;i++){
            if(AP[i].CodPre==cod){
                val=true;
                break;};};
        if(!val){
            cout<<"\nError: el codigo de prestatario ingresado no corresponde a ningun prestatario\n";}
        else{
        Listado->dato.CodPre=cod;};
        }while(!val);
    /*AGREGAR DESCRIPCION DE PRESTAMO*/
        cout<<"Ingrese la descripcion del nuevo prestamo:\n";
        getline(cin>>ws,Listado->dato.DP);
    /*ASEGURADO DE ESTADO DE LA VARIABLE*/
        Listado->dato.Estado=true;
        /*utiliza 2 do-while para vincular los codigos de categoria y prestatario al nuevo prestamo, despues le pide al usuario la
        descripcion y asegura el estado del booleano*/
}
/*PROPOSITO: Modificar Prestamo
PARAMETROS:
    Listado: Lista de prestamos 
RETORNO: Void*/
void Modificar_Prestamo(NodoPrestamo* Listado){
    /*VARIBLES*/
        char caracter; //CARACTER PARA DECIDIR VER O NO PRESTAMOS EXISTENTES
        int cod; //NUMERO DEL PRESTAMO QUE INGRESA EL USUARIO
        int NumP; //NUMERO DE PRESTAMOS
        NodoPrestamo* Aux=Listado; //PUNTERO AUXILIAR
    /*INICIO DEL PROGRAMA*/
        do{
    /*MUESTREO DE LOS PRESTAMOS PENDIENTES EXISTENTES*/
        cout<<"¿Desea ver los prestamos existentes?(S/N)\n";
        cin>>caracter;
        caracter=tolower(caracter);
        switch(caracter){
            case 's':
                NumP=0;
                Aux=Listado;
                cout<<"numero de prestamo / descripcion\n";
                while(Aux!=nullptr){
                    cout<<NumP<<" / "<<Aux->dato.DP<<endl;
                    Aux=Aux->siguiente;
                    NumP++;};
                break;
            case 'n':
                NumP=0;
                Aux=Listado;
                while(Aux!=nullptr){
                    Aux=Aux->siguiente;
                    NumP++;};
                break;
            default:
                cout<<"Error. el caracter ingresado difiere de S o N. Intente nuevamente.\n";};
        if(caracter=='s' or caracter=='n'){
            cout<<"ingrese el numero del prestamo a modificar:";
            cin>>cod;
        /*VALIDACION*/
            if(cod>=NumP or cod<0){
                cout<<"\nError: el numero del prestamo ingresado no corresponde a ningun prestamo\n";}
            else{
        /*MODIFICACION DEL PRESTAMO*/
                cout<<"\ningrese la nueva descripcion para el prestamo:";
                for(int i=cod;i!=0;i--){
                    Listado=Listado->siguiente;};
                getline(cin>>ws,Listado->dato.DP);};};
        }while(caracter!='s' && caracter!='n' or cod>=NumP or cod<0);
        /*el programa le pregunta al usuario si desea ver un listado de los prestamos existentes para que luego de que responda "s o n"
        proceda a pedirle el numero del prestamo que desea editar. luego de validar dicho entero procede a pedirle que ingrese la nueva
        descripcion*/
}
/*PROPOSITO: Eliminar Prestamo
PARAMETROS:
    Listado: Lista de prestamos 
RETORNO: Void*/
void Eliminar_Prestamo(NodoPrestamo*&Listado){
    /*VARIBLES*/
        char caracter; //CARACTER PARA DECIDIR VER O NO PRESTAMOS DEVUELTOS EXISTENTES
        int cod; //NUMERO DE PRESTAMO A ELIMINAR QUE INGRESA EL USUARIO
        int salv=1; //VARIABLE UTILIZADA PARA GUARDAR LA POSICION DE MEMORIA DEL PRESTAMO ELEGIDO POR EL USUARIO PARA ELIMINAR 
        int cdpd=0;//CANTIDAD DE PRESTAMOS DEVUELTOS
        NodoPrestamo* Aux=Listado; //PUNTERO AUXILIAR
        NodoPrestamo* Aux2; //SEGUNDO PUNTERO AUXILIAR
    /*INICIO DEL PROGRAMA*/
        while(Aux!=nullptr){
            if(Aux->dato.Estado==false){
                cdpd++;};
            Aux=Aux->siguiente;};
        if(cdpd!=0){
        do{
        cdpd=0;
    /*MUESTREO DE PRESTAMOS DEVUELTOS EXISTENTES*/
        cout<<"¿Desea ver los prestamos devueltos existentes?(S/N)\n";
        cin>>caracter;
        caracter=tolower(caracter);
        switch(caracter){
            case 's':
                cout<<"numero de prestamo / descripcion\n";
                Aux=Listado;
                while(Aux!=nullptr){
                    if(Aux->dato.Estado==false){
                        cdpd++;
                        cout<<cdpd<<" / "<<Aux->dato.DP<<endl;};
                    Aux=Aux->siguiente;};
                break;
            case 'n':
                Aux=Listado;
                while(Aux!=nullptr){
                    if(Aux->dato.Estado==false){
                        cdpd++;};
                    Aux=Aux->siguiente;};
                break;
            default:
                cout<<"Error. el caracter ingresado difiere de S o N. Intente nuevamente.\n";};
        if(caracter=='s' or caracter=='n'){
            cout<<"ingrese el numero del prestamo a eliminar:";
            cin>>cod;
        /*VALIDACION*/
            if(cod<1 or cod>cdpd){
                cout<<"\nError: el numero del prestamo ingresado es invalido\n";}
            else{
        /*ELIMINACION DEL PRESTAMO*/
                Aux=Listado;
                if(cod==1 && Listado->dato.Estado==false){
                    Listado=Listado->siguiente;
                    delete Aux;}
                else{
                    while(salv!=cod or Aux->dato.Estado){
                        if(salv!=cod && Aux->dato.Estado==false){
                            salv++;};
                        Aux2=Aux;
                        Aux=Aux->siguiente;
                        if(salv==cod && Aux->dato.Estado==false){
                            Aux2->siguiente=Aux->siguiente;
                            delete Aux;
                            break;};};};};};
        }while(caracter!='s' && caracter!='n' or cod<1 or cod>cdpd);}else{cout<<"No hay prestamos devueltos que eliminar\n";};
    /*primero que nada el programa revisa que existan prestamos devueltos, despues le ofrece ver al usuario un listado de los mismos
    al cual debe responder explisitamente s o n para podes avanzar, luego pide el numero del prestamo que desea eliminar para que
    despues de validarlo proceda a borrar dicho prestamo y reducir al final la dimension logica*/
}
/*PROPOSITO: Devolver Prestamo
PARAMETROS:
    Listado: Lista de prestamos 
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
RETORNO: Void*/
void Devolver_Prestamo(NodoPrestamo* Listado, Prestatario AP[N], int dlp){
    /*VARIBLES*/
        char caracter;//CARACTER PARA DECIDIR VER O NO PRESTATARIOS CON PRESTAMOS EXISTENTES
        bool val=true;//BOOLEANO UTILIZADO EN LA VALIDACION DEL CODIGO INGRESADO POR EL USUARIO
        int cod;//CODIGO DE PRESTATARIO QUE INGRESA EL USUARIO
        int cod2;//NUMERO DE PRESTAMO QUE INGRESA EL USUARIO
        int num1=1;//NUMERADOR 1
        int num2=1;//NUMERADOR 2
        int cdpp=0;//CANTIDAD DE PRESTAMOS PENDIENTES
        NodoPrestamo* Aux=Listado; //PUNTERO AUXILIAR
    /*INICIO DEL PROGRAMA*/
        while(Aux!=nullptr){
            if(Aux->dato.Estado){
                cdpp++;};
            Aux=Aux->siguiente;};
        if(cdpp!=0){
        do{
        /*MUESTREO DE PRESTATARIOS CON PRESTAMOS PENDIENTES*/
        cout<<"¿Desea ver los prestatarios con prestamos pendientes?(S/N)\n";
        cin>>caracter;
        caracter=tolower(caracter);
        switch(caracter){
            case 's':
                cout<<"codigo / Nombre/s / Aprellido/s\n";
                for(int i=0;i<dlp;i++){
                    Aux=Listado;
                    while(Aux!=nullptr){
                        if(AP[i].CodPre==Aux->dato.CodPre && Aux->dato.Estado){
                            val=false;
                            break;}
                        Aux=Aux->siguiente;};
                    if(val==false){
                        cout<<AP[i].CodPre<<" / "<<AP[i].Nombres<<" / "<<AP[i].Apellidos<<endl;
                        val=true;};};
                break;
            case 'n':
                break;
            default:
                cout<<"Error. el caracter ingresado difiere de S o N. Intente nuevamente.\n";};
        if(caracter=='s' or caracter=='n'){
            cout<<"ingrese el codigo del prestatario del cual desea ver los prestamos pendientes:";
            cin>>cod;
        /*VALIDACION DEL CODIGO 1*/
            for(int i=0;i<dlp;i++){
                if(AP[i].CodPre==cod){
                    val=false;
                    break;};};
            if(val){cout<<"\nError: el codigo de prestatario ingresado no corresponde a ningun prestatario\n";}
            else{
                Aux=Listado;
                while(Aux!=nullptr){
                    if(cod==Aux->dato.CodPre && Aux->dato.Estado){
                        val=false;
                        break;}
                    else{
                        val=true;};
                    Aux=Aux->siguiente;};
                if(val){cout<<"\nEl prestatario ingresado no tiene ningun prestamo pendiente\n";}
                else{
                    Aux=Listado;
                    while(Aux!=nullptr){
                        if(cod==Aux->dato.CodPre && Aux->dato.Estado){
                            cout<<num1<<":"<<Aux->dato.DP<<endl;
                            num1++;}
                        Aux=Aux->siguiente;};
                    cout<<"\ningrese el numero del prestamo a devolver:\n";
                    cin>>cod2;
                /*VALIDACION DEL CODIGO 2*/
                    if(cod2<1 or cod2>=num1){
                        cout<<"\nError: el numero de prestamo ingresado no corresponde a ningun prestamo pendiente\n";
                        num1=0;}
                    else{
                /*DEVOLUCION DE PRESTAMO*/
                        Aux=Listado;
                        while(Aux!=nullptr){
                            if(cod==Aux->dato.CodPre && Aux->dato.Estado){
                                if(cod2==num2){
                                    Aux->dato.Estado=false;};
                                num2++;}
                            Aux=Aux->siguiente;};};};};};
        }while(caracter!='s' && caracter!='n' or val or cod2<1 or cod2>=num1);}
        else{cout<<"No hay prestamos pendientes para devolucion\n";};
    /*Primero revisa si hay prestamos pendientes registrados, de haberlos le pregunta al usuario de ver un listado de los prestatarios
     vinculados a dichos prestamos, al cual el usuario debe responder s o n, de lo contrario no lo dejara avanzar. luego de la eleccion
     le pide al usuario el codigo de el prestatario elegido para que despues de validarlo proceda a mostrar un listado de los prestamos
     pendientes del mismo. para finalizar el usuario debera ingresar el numero del prestamo que desea marcar como devuelto y la funcion
     procede a encontrarlo y marcarlo como tal*/
}
//Consultar Prestamos
/*PROPOSITO: Cantidad de Objetos Prestados por Categoria
PARAMETROS:
    Listado: Lista de prestamos 
    AC: Parametro que representa al Arreglo de Categorias en su totalidad
    dlc: Entero vinculado al valor de la dimension logica del Arreglo de Categorias
RETORNO: Void*/
void Cantidad_de_Objetos_Prestados_por_Categoria(NodoPrestamo* Listado, Categoria AC[N], int dlc){
    /*VARIBLES*/
    int m=0;//CONTADOR DE PRESTAMOS DE CADA CATEGORIA
    int j=0;//CONTADOR DEL TOTAL DE PRESTAMOS PENDIENTES
    NodoPrestamo* Aux; //PUNTERO AUXILIAR
    /*INICIO DEL PROGRAMA*/
    for(int i=0;i<dlc;i++){
        Aux=Listado;
        while(Aux!=nullptr){
            if(Aux->dato.CodCat==AC[i].CodCat){
                m++;
                if(Aux->dato.Estado){
                    j++;};};
            Aux=Aux->siguiente;};
    /*IMPRESION*/
        cout<<"Hay "<<m<<' '<<AC[i].DC<<" prestados\n";
        m=0;}
    cout<<"\nLa cantidad de prestamos pendientes total es:"<<j<<endl<<endl;
    /*Compara los codigos de categoria(CodCat) de cada elemento del Arreglo Categorico con cada codigo de categoria asociado
    a cada Prestamo del Listado de Prestamos y aumenta un contador en base a cada coincidencia para despues imprimirlo en
    pantalla junto el nombre de Categoria(DC) asociado con el Codigo que uso para comparar(CodCat). Luego recorre el arreglo
    de prestamos y cuenta cuantos prestamos pendientes quedan (Estado=true) para mostrarlo en pantalla*/
}
/*PROPOSITO: Listado de Prestamos por Categoria
PARAMETROS:
    Listado: Lista de prestamos 
    AC: Parametro que representa al Arreglo de Categorias en su totalidad
    dlc: Entero vinculado al valor de la dimension logica del Arreglo de Categorias
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
RETORNO: Void*/
void Listado_de_Prestamos_por_Categoria(NodoPrestamo* Listado, Categoria AC[N], int dlc, Prestatario AP[N], int dlp){
    /*VARIBLES*/
        int cod; //CODIGO DE CATEGORIA QUE INGRESA EL USUARIO
        bool val=true; //BOOLEANO UTILIZADO EN LA VALIDACION DEL CODIGO INGRESADO POR EL USUARIO
        bool m=true; //UTILIZADA PARA INFORMAR SI LA CATEGORIA ELEGIDA POR EL USUARIO NO CONTIENE PRESTAMOS PENDIENTES
    /*INICIO DEL PROGRAMA*/
        do{
        /*MUESTREO DE LAS CATEGORIAS*/
        Switch_Categoria(AC, dlc);
        /*SELECCION DE LA CATEGORIA*/
        cout<<"ingrese el codigo de la categoria de la cual quiera ver los prestamos pendientes:";
        cin>>cod;
        /*VALIDACION*/
        for(int i=0;i<dlc;i++){
            if(cod==AC[i].CodCat){
                cod=i;val=false;break;};};
        if(val){cout<<"\nError: el codigo de categoria ingresado no corresponde a ninguna categoria\n";}
        else{
            /*IMPRESION*/
            cout<<AC[cod].DC<<':'<<endl;
            while(Listado!=nullptr){
                if(AC[cod].CodCat==Listado->dato.CodCat && Listado->dato.Estado){
                    m=false;
                    cout<<Listado->dato.DP<<' ';
                    for(int n=0;n<dlp;n++){
                        if(Listado->dato.CodPre==AP[n].CodPre){
                            cout<<AP[n].Nombres<<' '<<AP[n].Apellidos<<endl;};};};
                Listado=Listado->siguiente;};
            if(m){cout<<"Esta categoria no contiene prestamos pendientes\n";};};
        }while(val);
    /*Lista las categorias con sus codigos respectivos para despues pedirle al usuario que ingrese el codigo de la categoria
    de la cual desee ver los prestamos pendientes. Luego de comprobar que el valor ingresado es valido el programa muestra
    la descripción del los prestamos pendientes junto con los datos del prestario*/
}
/*PROPOSITO: Listado de Prestamos ordenados por Categoria o Prestatario
PARAMETROS:
    Listado: Lista de prestamos 
    AC: Parametro que representa al Arreglo de Categorias en su totalidad
    dlc: Entero vinculado al valor de la dimension logica del Arreglo de Categorias
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
RETORNO: Void*/
void Listado_de_Prestamos_ordenados_por_Categoria_o_Prestatario(NodoPrestamo* Listado, Categoria AC[N], int dlc, Prestatario AP[N], int dlp){
    /*VARIABLES*/
        char caracter='N'; //VARIABLE UTILIZADA PARA EL WHILE/SWITCH
        bool bool1=false; //BOOLEANO UTILIZADO PARA CONFIRMAR SI UNA CATEGORIA O PRESTATARIO TIENE VINCULADOS PRESTAMOS PENDIENTES
        string men; //REPRESENTA AL STRING CON MENOR VALOR ALFABETICO POSIBLE EN SU ITERACION ACTUAL
        string ult; //REPRESENTA AL STRING CON MAYOR VALOR ALFABETICO POSIBLE
        string lim; //REPRESENTA AL STRING LIMITE AL CUAL EL "MENOR" DEBE OBLIGATORIAMENTE SUPERAR EN LA ITERACION ACTUAL
        int Dim; //REPRESENTA A LA POSICION EN EL ARREGLO DEL STRING "MENOR"
        NodoPrestamo* Aux=Listado; //PUNTERO AUXILIAR
    /*INICIO DEL PROGRAMA*/ 
        while(caracter!='c' && caracter!='p'){
            cout<<"¿Clasificar el listado por Categoría (C) o Prestatario (P)?"<<endl;
            cin>>caracter;
            caracter=tolower(caracter);
            switch(caracter){
                case 'c':
                /*DETERMINACION DEL STRING ULT*/
                    for(int i=0;i<dlc;i++){
                        if(ult<AC[i].DC){
                            ult=AC[i].DC;}}
                /*ITERACION SOBRE CATEGORIAS*/
                    for(int i=0;i<dlc;i++){
                    /*ACTUALIZACION DEL LIMITE Y REINICIO DEL STRING MEN*/
                        lim=men;
                        men=ult;
                    /*DETERMINACION DEL STRING MEN Y SU POSICION*/
                        for(int n=0;n<dlc;n++){
                            if(AC[n].DC>lim && AC[n].DC<=men){
                                men=AC[n].DC;
                                Dim=n;}}
                    /*COMPROBACION DE LA EXISTENCIA DE PRESTAMOS VINCULADOS A LA CATEGORIA*/
                        Aux=Listado;
                        while(Aux!=nullptr){
                            if(AC[Dim].CodCat==Aux->dato.CodCat && Aux->dato.Estado){
                                bool1=true;
                                break;};
                            Aux=Aux->siguiente;};
                    /*IMPRESION*/
                        if(bool1){
                            bool1=false;
                            cout<<"\n"<<men<<": \n";
                            Aux=Listado;
                            while(Aux!=nullptr){
                                if(AC[Dim].CodCat==Aux->dato.CodCat && Aux->dato.Estado){
                                    cout<<Aux->dato.DP<<' ';
                                    for(int m=0;m<dlp;m++){
                                        if(Aux->dato.CodPre==AP[m].CodPre){
                                            cout<<AP[m].Nombres<<' '<<AP[m].Apellidos<<endl;};};};
                                Aux=Aux->siguiente;};};};
                    break;
                case 'p':
                /*DETERMINACION DEL STRING ULT*/
                    for(int i=0;i<dlp;i++){
                        if(ult<AP[i].Nombres+' '+AP[i].Apellidos){
                            ult=AP[i].Nombres+' '+AP[i].Apellidos;}}
                /*ITERACION SOBRE PRESTATARIOS*/
                    for(int i=0;i<dlp;i++){
                    /*ACTUALIZACION DEL LIMITE Y REINICIO DEL STRING MEN*/
                        lim=men;
                        men=ult;
                    /*DETERMINACION DEL STRING MEN Y SU POSICION*/
                        for(int n=0;n<dlp;n++){
                            if(AP[n].Nombres+' '+AP[n].Apellidos>lim && AP[n].Nombres+' '+AP[n].Apellidos<=men){
                                men=AP[n].Nombres+' '+AP[n].Apellidos;
                                Dim=n;}}
                    /*COMPROBACION DE LA EXISTENCIA DE PRESTAMOS VINCULADOS AL PRESTATARIO*/
                        Aux=Listado;
                        while(Aux!=nullptr){
                            if(AP[Dim].CodPre==Aux->dato.CodPre && Aux->dato.Estado){
                                bool1=true;
                                break;};
                            Aux=Aux->siguiente;};
                    /*IMPRESION*/
                        if(bool1){
                            bool1=false;
                            cout<<"\n"<<men<<": \n";
                            Aux=Listado;
                            while(Aux!=nullptr){
                                if(AP[Dim].CodPre==Aux->dato.CodPre && Aux->dato.Estado){
                                    cout<<Aux->dato.DP<<' ';
                                    for(int m=0;m<dlc;m++){
                                        if(Aux->dato.CodCat==AC[m].CodCat){
                                            cout<<AC[m].DC<<endl;};};};
                                Aux=Aux->siguiente;};};};
                    break;
                default:
                    cout<<"Error. el caracter ingresado difiere de C o P. Intente nuevamente.\n";};}
    /*Se le preguntara al usuario como desea ver el listado, si por categoria ("C") o por Prestatario ("P") para Luego
    de que la opcion ingresada sea verificada como valida procedera a ordenar de forma alfabetica ascendente el listado.
    este mostrara la descripcion, categoria y datos de prestatario de todos los prestamos pendientes*/
}
/*PROPOSITO: Listar todos los Prestatarios que tienen al menos un Objeto Prestado
PARAMETROS:
    Listado: Lista de prestamos 
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
RETORNO: Void*/
void Listar_todos_los_Prestatarios_que_tienen_al_menos_un_Objeto_Prestado(NodoPrestamo* Listado, Prestatario AP[N], int dlp){
    /*VARIABLES*/
    int m=0; //CONTADOR QUE ALMACENA TODOS LOS PRESTATARIOS CON DEUDAS PENDIENTES
    NodoPrestamo* Aux; //PUNTERO AUXILIAR
    /*INICIO DEL PROGRAMA*/
    cout<<"\n---LISTADO DE PRESTATARIOS CON PRESTAMOS PENDIENTES---\n";
    cout<<"\n*Prestatario* : *Cantidad de prestamos pendientes*\n";
    /*RECORRIDO DEL ARREGLO PRESTATARIOS*/
    for(int i=0;i<dlp;i++){
        Aux=Listado;
        while(Aux!=nullptr){
    /*CONTADOR DEL TOTAL DE PRESTAMOS PENDIENTES POR PRESTATARIO*/
            if(AP[i].CodPre==Aux->dato.CodPre && Aux->dato.Estado){
                m++;};
            Aux=Aux->siguiente;};
        if(m!=0){
    /*LISTADO E IMPRESION*/
            cout<<AP[i].Nombres<<' '<<AP[i].Apellidos<<':'<<m<<endl;
            m=0;};};
    /*Compara los codigos de prestatario(CodPre) de cada elemento del Arreglo de Prestatarios con cada codigo de Prestatario
    asociado a cada Prestamo del Listado de Prestamos y muestra en pantalla el/los apellido/s y nombre/s de todos los Prestatarios
    que tienen prestamos pendientes (Estado=true) junto con la cantidad de dichos prestamos que el prestatario debe*/
}
 
//FUNCIONES SECUNDARIAS
/*PROPOSITO: Mostrar el Submenu 1:"Administrar y Consultar Categorias y Prestatarios" y pasar a sus subfunciones los parametros requeridos
PARAMETROS:
    Listado: Lista de prestamos 
    AC: Parametro que representa al Arreglo de Categorias en su totalidad
    dlc: Entero vinculado al valor de la dimension logica del Arreglo de Categorias
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
RETORNO: Void*/
void Administrar_Y_Consultar_Categorias_Y_Prestatarios(NodoPrestamo* Listado, Categoria AC[N], int &dlc, Prestatario AP[N], int &dlp){
    char caracter;
    do{
    cout<<"\nAdministrar y Consultar Categorias y Prestatarios\n";
    cout<<"A: Agregar Categoria\n";
    cout<<"B: Modificar Categoria\n";
    cout<<"C: Eliminar Categoria\n";
    cout<<"D: Agregar Prestatario\n";
    cout<<"E: Modificar Prestatario\n";
    cout<<"F: Eliminar Prestatario\n";
    cout<<"G: Volver\n\n";
    cin>>caracter;
    caracter=tolower(caracter);
    switch(caracter){
        case 'a':
            if(dlc==N){cout<<"no hay espacio para la nueva categoria.\n";}//verificacion de espacio para añadir una categoria
            else{Agregar_una_Categoria(AC, dlc);};
            break;
        case 'b':
            if(dlc==0){cout<<"No hay categorias que modificar\n";} //verifica si hay categorias para modificar
            else{Modificar_Categoria(AC, dlc);};
            break;
        case 'c':
            if(dlc==0){cout<<"No hay categorias que eliminar\n";} //verifica si hay categorias para eliminar
            else{Eliminar_Categoria(Listado, AC, dlc);};
            break;
        case 'd':
            if(dlp==N){cout<<"no hay espacio para el nuevo prestatario\n";} //verifica que haya espacio suficiente para agregar un prestatario
            else{Agregar_Prestatario(AP, dlp);};
            break;
        case 'e':
            if(dlp==0){cout<<"No hay prestatarios que modificar\n";} //verifica si hay prestatarios para modificar
            else{Modificar_Prestatario(AP, dlp);};
            break;
        case 'f':
            if(dlp==0){cout<<"No hay prestatarios que eliminar\n";} //verifica que haya prestatarios para eliminar
            else{Eliminar_Prestatario(Listado, AP, dlp);};
            break;
        case 'g':
            break;
        default:
            cout<<"Error. La opcion ingresada no corresponde a ninguna de las opciones validas ('a', 'b', 'c', 'd', 'e', 'f' o 'g')\n\n";}
    }while(caracter!='g');}
/*PROPOSITO: Mostrar el Submenu 2:"Administrar Prestamos" y pasar a sus subfunciones los parametros requeridos
PARAMETROS:
    Listado: Lista de prestamos 
    AC: Parametro que representa al Arreglo de Categorias en su totalidad
    dlc: Entero vinculado al valor de la dimension logica del Arreglo de Categorias
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
RETORNO: Void*/
void Administrar_Prestamos(NodoPrestamo*&Listado, Categoria AC[N], int &dlc, Prestatario AP[N], int &dlp){
    char caracter;
    do{
    cout<<"\nAdministrar Prestamos\n";
    cout<<"A: Agregar Prestamo\n";
    cout<<"B: Modificar Prestamo\n";
    cout<<"C: Eliminar Prestamo\n";
    cout<<"D: Devolver Prestamo\n";
    cout<<"E: Volver\n\n";
    cin>>caracter;
    caracter=tolower(caracter);
    switch(caracter){
        case 'a':
            if(dlc==0){cout<<"Error:No hay categorias existentes a la cual vincular el nuevo prestamo\n";}//verifica si existe alguna categoria
            else{if(dlp==0){cout<<"Error:No hay prestatarios existentes a la cual vincular el nuevo prestamo\n";}//verifica si existe algun prestatario
            else{Agregar_Prestamo(Listado, AC, dlc, AP, dlp);}};
            break;
        case 'b':
            if(Listado==nullptr){cout<<"No hay prestamos que modificar\n";}//verifica si existe algun prestamo
            else{Modificar_Prestamo(Listado);};
            break;
        case 'c':
            if(Listado==nullptr){cout<<"No hay prestamos que eliminar\n";}//verifica si existe algun prestamo
            else{Eliminar_Prestamo(Listado);};
            break;
        case 'd':
            if(Listado==nullptr){cout<<"No hay prestamos registrados\n";}//verifica si existe algun prestamo
            else{Devolver_Prestamo(Listado, AP, dlp);};
            break;
        case'e':
            break;
        default:
            cout<<"Error. La opcion ingresada no corresponde a ninguna de las opciones validas ('a', 'b', 'c', 'd' o 'e')\n\n";}
    }while(caracter!='e');}
/*PROPOSITO: Mostrar el Submenu 3:"Consultar Prestamos" y pasar a sus subfunciones los parametros requeridos
PARAMETROS:
    Listado: Lista de prestamos 
    AC: Parametro que representa al Arreglo de Categorias en su totalidad
    dlc: Entero vinculado al valor de la dimension logica del Arreglo de Categorias
    AP: Parametro que representa al Arreglo de Prestatarios en su totalidad
    dlp: Entero vinculado al valor de la dimension logica del Arreglo de Prestatarios
RETORNO: Void*/
void Consultar_Prestamos(NodoPrestamo* Listado, Categoria AC[N], int &dlc, Prestatario AP[N], int &dlp){
    char caracter;
    do{
    cout<<"\nConsultar Prestamos\n";
    cout<<"A: Cantidad de Objetos Prestados por Categoria\n";
    cout<<"B: Listado de Prestamos por Categoria\n";
    cout<<"C: Listado de Prestamos ordenados por Categoria o Prestatario\n";
    cout<<"D: Listar todos los Prestatarios que tienen al menos un Objeto Prestado\n";
    cout<<"E: Volver\n\n";
    cin>>caracter;
    caracter=tolower(caracter);
    switch(caracter){
        case 'a':
            if(dlc==0){cout<<"\nno hay categorias registradas\n\n";}
            else{Cantidad_de_Objetos_Prestados_por_Categoria(Listado, AC, dlc);};
            break;
        case 'b':
            if(dlc==0){cout<<"\nno hay categorias registradas\n\n";}
            else{Listado_de_Prestamos_por_Categoria(Listado, AC, dlc, AP, dlp);};
            break;
        case 'c':
            if(dlc==0){cout<<"\nno hay categorias registradas\n\n";}
            else{if(dlp==0){cout<<"\nno hay prestatarios registrados\n\n";}
            else{Listado_de_Prestamos_ordenados_por_Categoria_o_Prestatario(Listado, AC, dlc, AP, dlp);};};
            break;
        case 'd':
            if(dlp==0){cout<<"\nno hay prestatarios registrados\n\n";}
            else{Listar_todos_los_Prestatarios_que_tienen_al_menos_un_Objeto_Prestado(Listado, AP, dlp);};
            break;
        case 'e':
            break;
        default:
            cout<<"Error. La opcion ingresada no corresponde a ninguna de las opciones validas ('a', 'b', 'c', 'd' o 'e')\n\n";}
    }while(caracter!='e');}
 
//MAIN
/*PROPOSITO: Punto de inicio del programa. Menu principal.
PARAMETROS:-
RETORNO: Entero que representa en que condiciones finalizo el programa*/
int main(){
    //VARIBLES
    int opcion;//Variable del switch
    NodoPrestamo* ListadoPrestamo=nullptr;
    int dlPrestatarios=0;//
    int dlCategorica=0;
    Categoria ArregloCategorico[N];
    Prestatario ArregloPrestatarios[N];
    //INTRODUCCION
    cout << "--== MENU DEL TRABAJO PRACTICO GRUPAL DE PI 2021 ==--\n\n| AUTOR : GRUPO 36 |BIENVENIDO!\n\n";
    //MENU PRINCIPAL
    do{
    cout<<"Selecciona una opcion por favor:\n";
    cout<<"1: Administrar y Consultar Categorias y Prestatarios\n";
    cout<<"2: Administrar Prestamos\n";
    cout<<"3: Consultar Prestamos\n";
    cout<<"4: Salir del Programa\n\n";
    cin>>opcion;
    switch(opcion){
        case 1:
            Administrar_Y_Consultar_Categorias_Y_Prestatarios(ListadoPrestamo, ArregloCategorico, dlCategorica, ArregloPrestatarios, dlPrestatarios);
            break;
        case 2:
            Administrar_Prestamos(ListadoPrestamo, ArregloCategorico, dlCategorica, ArregloPrestatarios, dlPrestatarios);
            break;
        case 3:
            Consultar_Prestamos(ListadoPrestamo, ArregloCategorico, dlCategorica, ArregloPrestatarios, dlPrestatarios);
            break;
        case 4:
            break;
        default:
            cout<<"Error. La opcion ingresada no corresponde al rango a ninguna de las opciones validas (1, 2, 3 o 4)\n\n";}
    }while(opcion!=4);
    //FINAL DEL MAIN
    return 0;}