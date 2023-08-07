#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>


using namespace std;


class HashTable
{
  public:
  //Constante para las tablas
  int constante =0;
  //Números de espacios en las subtablas
  int espacios = 0;
  //Dirección de memoria
  int brinco = 0;
  //Definción de la palabra
  string palabra;

  

};

//Variables globales
HashTable tablahash[500];
//Número de colisiones
int colisiones[101];
//salto para el siguiente espacio de memoria
int offset = 0;

//Función hash de Horner
int HashFunctionHorner (string key, int c, int n)
{
    //K -> key en valor entero
    double k=0;
    double ks=0;

    // = a0 + a1*128 + a2*128^2 + ... + an*128^n
    for (int i=0; key[i]; i++){

        ks = static_cast<int>(key[i]);
        k += (ks * pow(128, i)) ;
    }
    
                // =((kc) % p) % m
    int index = fmod(fmod((k*c) , 227) ,  n);

    
    //Se regresa el index para la posición de la tabla
    return index;
  
}

//Función para calcular el número de colisiones
void Contador(string key)
{
  //Se checa en donde caería con la llave en la tabla hash
  int index = HashFunctionHorner(key, 46, 100);
  colisiones[index] += 1;
  
}

//
void Insercion(string key, string definition)

{
  //Se genera el index de la posición de la palabra
  unsigned int index = HashFunctionHorner(key, 46, 100);
  
  
      //En el caso donde ya hubiera una dirección de memeoria en ese espacio solo se va a ese espacio y se inserta los datos
      if(tablahash[index].brinco !=0)
      {
        int ubi = 0;
        ubi = tablahash[index].brinco;
        
        
        
        int newindex = HashFunctionHorner(key, tablahash[ubi].constante, tablahash[ubi+1].espacios);
        
        tablahash[ubi+2+newindex].palabra = definition;
        
        
      }
      //Caso contrario es el primer dato que va a ir en ese espacio
      else{
      
        tablahash[index].brinco = 101 + offset;

        tablahash[101+offset].constante =  std::rand()%(277);
        
        tablahash[102+offset].espacios = pow(colisiones[index], 2);
        
        int newindex = HashFunctionHorner(key, tablahash[101+offset].constante, tablahash[102+offset].espacios);

        tablahash[103+offset+newindex].palabra = definition;

        offset += tablahash[102+offset].espacios +3;
        
      }
    
    
}

void Buscar(string key)
{
  int index = HashFunctionHorner(key, 46, 100);
  int index_2 = tablahash[index].brinco;
  int index_3 = index_2 + 2 + HashFunctionHorner(key, tablahash[index_2].constante, tablahash[index_2 + 1].espacios);
  
  cout << "---------------------------------------------------------------" << endl;
  cout <<"Palabra: " << key << endl;
  cout <<"Definción: " << tablahash[index_3].palabra << endl;
  cout << "---------------------------------------------------------------" << endl;
  cout << endl;
  
  
  
}

int main()
{
  

Contador("3DNow");
Contador("Acceso Directo");
Contador("Acceso telefónico a redes");
Contador("Active Desktop");
Contador("Active X");
Contador("Actualizar");
Contador("ADC");
Contador("Add-ons");
Contador("ADSL");
Contador("AGP");
Contador("AIX");
Contador("Alfanumerico");
Contador("Algoritmo");
Contador("AMD");
Contador("Ancho de banda");
Contador("API");
Contador("Aplicación");
Contador("Applets");
Contador("Arbol");
Contador("Arcade");
Contador("Archivo");
Contador("Arquitectura");
Contador("Arrastrar");
Contador("ASCII");
Contador("Asistente");
Contador("Athlon");
Contador("ATM");
Contador("Audio-CD");
Contador("Autocompletar");
Contador("Autoedición");
Contador("Autoexec.bat");
Contador("Autopistas");
Contador("AVI");
Contador("Backbone");
Contador("Backup");
Contador("Bajar");
Contador("Barra de canales");
Contador("Barra de direcciones");
Contador("Barra de herramientas");
Contador("Barra de tareas");
Contador("Barra del explorador");
Contador("Base de datos");
Contador("Batch");
Contador("Baudio");
Contador("Beta");
Contador("Binario");
Contador("BIOS");
Contador("Bit");
Contador("BMP (Bitmap)");
Contador("Bookmark");
Contador("Botón Inicio");
Contador("Botón secundario");
Contador("Browser");
Contador("Buffer");
Contador("Bump mapping");
Contador("Bus");
Contador("Buscador");
Contador("Bus Serie Universal (USB)");
Contador("Byte");
Contador("Cache");
Contador("CAD");
Contador("CAM");
Contador("Canal");
Contador("Cancelmoose");
Contador("Carpeta");
Contador("Caudal");
Contador("CD");
Contador("CD-A");
Contador("CD-R");
Contador("CD-ROM");
Contador("CD-RW");
Contador("CD-Vídeo");
Contador("Celeron");
Contador("CGI");
Contador("Chat");
Contador("Chatear");
Contador("Cheat code");
Contador("Chip");
Contador("Chipset");
Contador("Chroma-key");
Contador("Ciberjuegos");
Contador("Cibernauta");
Contador("Cibernética");
Contador("Ciberocupas");
Contador("CISC");
Contador("Clic");
Contador("Cliente");
Contador("Coma flotante");
Contador("Comando");
Contador("Compresor");
Contador("Concept PC");
Contador("Controlador");
Contador("Controles");
Contador("Cookies");
Contador("Correo electrónico");
Contador("Cortafuegos");
Contador("CPU");
Contador("Crack");
Contador("Cracker");
Contador("Cuadro de diálogo");
Contador("Cursor");




Insercion("3DNow","Especificaciones multimedia para los procesadores de AMD.");
Insercion("Acceso Directo","Icono especial que representa a una carpeta o un archivo y que abre o ejecuta ésta de una forma cómoda y rápida.");
Insercion("Acceso telefónico a redes","Aplicación que permite utilizar una línea telefónica y un módem para conectarse a otro equipo");
Insercion("Active Desktop","Escritorio activo de Windows 98 que permite tener contenido activo en el Escritorio y poner como fondo o papel tapiz una página Web, un vídeo, un sonido, etc.");
Insercion("Active X","Tecnología de Microsoft que proporciona contenido multimedia (interactivo) a las páginas Web.");
Insercion("Actualizar","Volver a cargar o mostrar el contenido de una página Web o una ventana.");
Insercion("ADC","Circuito para convertir la señal analógica en digital, es decir, para digitalizar.");
Insercion("Add-ons","Añadidos o módulos que se incorporan a los que ya se tienen y que proporcionan nuevas funcionalidades.");
Insercion("ADSL","(Asymmetric Digital Subscriber Line - Línea Digital Asimétrica de Abonado): Sistema asimétrico de transmisión de datos sobre líneas telefónicas convencionales.");
Insercion("AGP","Puerto acelerador gráfico. Bus que mejora la reproducción de gráficos en el ordenador.");
Insercion("AIX","Versión del sistema operativo UNIX diseñada por IBM para estaciones de trabajo y grandes sistemas.");
Insercion("Alfanumerico","Cualquier combinación de números, letras y símbolos.");
Insercion("Algoritmo","Conjunto de instrucciones concretas y detalladas mediante el cual se consigue una acción determinada.");
Insercion("AMD","Empresa que fabrica los procesadores K6 o K6-2, competencia de Pentium y Pentium II.");
Insercion("Ancho de banda","Máxima cantidad de información simultánea que se puede transferir por una línea telefónica.");
Insercion("API","(Aplication Program Interface - Interfaz de Aplicación del Programa): Conjunto de rutinas del sistema que se pueden usar en un programa para la gestión de entrada-salida de ficheros, etc.");
Insercion("Aplicación","Programa que realiza una serie de funciones y con el cual trabajamos en el ordenador.");
Insercion("Applets","Programas desarrollados con Java para mejorar la presentación de las páginas Web que realizan animaciones, juegos e interacción con el usuario.");
Insercion("Arbol","Estructura de directorios o carpetas de un ordenador, del directorio raíz van partiendo diferentes ramas (subdirectorios o subcarpetas), donde se ubican los archivos.");
Insercion("Arcade","Programas de acción (videojuegos) donde las armas o la violencia juegan un papel importante.");
Insercion("Archivo","Documento generado con una aplicación que se almacena en una unidad.");
Insercion("Arquitectura","Término que se refiere al tipo de estructura hardware de la máquina y que también se aplica a la clasificación de los microprocesadores o el tipo de ranuras de expansión.");
Insercion("Arrastrar","Dícese del movimiento generado por una selección al hacer clic sobre ella y, sin soltar el botón del ratón, mover ésta hacia otro lugar.");
Insercion("ASCII","(American Standard Code of Information Interchange): Estándar reconocido que engloba un número de caracteres útiles.");
Insercion("Asistente","Herramienta que nos guía y ayuda a través de varios pasos a realizar una tarea para mayor comodidad y sencillez.");
Insercion("Athlon","Nombre del último procesador de AMD que puede funcionar a velocidades que oscilan desde los 500 a 700 MHz");
Insercion("ATM","(Asyncronous Transmision Mode): Sistema de transferencia de datos asíncrono que aprovecha al máximo la capacidad de una línea. Una de las tecnologías de red más punteras, pero también cara.");
Insercion("Audio-CD","Calidad de sonido equivalente a la que proporciona un compact-disc y que corresponde a 44 KHz a 16 bits en estéreo.");
Insercion("Autocompletar","Característica que funciona en distintas aplicaciones y que nos completa operaciones utilizadas frecuentemente.");
Insercion("Autoedición","Programas para la edición y maquetación electrónica de documentos que se han impuesto a los tradicionales sistemas de preimpresión. Permiten crear y diseñar periódicos, revistas y todo tipo de publicaciones (QuarkXPress, PageMaker...).");
Insercion("Autoexec.bat","Programa que carga automáticamente el sistema operativo al arrancar, el cual puede modificar el usuario para personalizar el ordenador al encenderlo.");
Insercion("Autopistas","Redes de comunicación global, como Internet, que constituyen los nuevos canales de la información y de la cultura.");
Insercion("AVI", "Formato de vídeo digital por excelencia en el mundo PC, desarrollado por Microsoft.");
Insercion("Backbone","La columna vertebral de la Red.");
Insercion("Backup","Aplicación de copia de seguridad de ficheros, carpetas o unidades completas que permite dividir la información o ficheros en varios disquetes y que además la comprime.");
Insercion("Bajar","Descargar o transferir a nuestro ordenador archivos de Internet.");
Insercion("Barra de canales", "Opción del Escritorio que proporciona una lista de los canales disponibles en su equipo.");
Insercion("Barra de direcciones","Forma rectangular que aparece en la parte superior de las ventanas y la cual nos informa en todo momento de la Path (trayectoria) donde nos encontramos posicionados dentro de una unidad. En Internet es el lugar donde hay que teclear la dirección de la página Web a la que deseamos acceder para que el ordenador la cargue y la muestre en pantalla.");
Insercion("Barra de herramientas","Conjunto de botones que representan las opciones de menú más comunes o las utilizadas con más frecuencia.");
Insercion("Barra de tareas","Forma rectangular gris que aparece nada más cargar Windows 98 en la parte inferior del Escritorio y la cual se divide en zona de control, el botón Inicio, alguna barra de herramientas y la zona de carga de carpetas y aplicaciones.");
Insercion("Barra del explorador","Panel que se abre en la parte izquierda de las ventanas.");
Insercion("Base de datos","Sistema de almacenamiento de datos muy flexible que permite organizar la información de forma muy eficiente.");
Insercion("Batch","Fichero de proceso por lotes, es un archivo que encadena comandos que son realizados por el PC cuando se le invoca.");
Insercion("Baudio","Unidad de medida. Número de cambios de estado de una señal por segundo.");
Insercion("Beta","Versión anterior a la Alfa y que puede ser la versión definitiva que se comercializará en un determinado tiempo.");
Insercion("Binario","Código básico de la informática que reduce todo tipo de información a cadenas de ceros y unos, que rigen las instrucciones y respuestas del microprocesador.");
Insercion("BIOS","Información básica grabada en un chip imborrable que hace que un ordenador pueda funcionar y arrancar.");
Insercion("Bit","(binary digit): Unidad básica de información representada por ceros y unos que se van sucediendo para conformar los distintos significados.");
Insercion("BMP (Bitmap)","Formato de fichero gráfico por excelencia de los ordenadores PC, inventado por Microsoft, que tiene mucha calidad y se lee rápidamente. En contra, no se puede comprimir de ninguna manera y, generalmente, no es reconocido por ningún ordenador que no sea PC.");
Insercion("Bookmark","Marca, anotación de una dirección Web oURL que queda archivada para su posterior uso.");
Insercion("Botón Inicio","Botón que se encuentra a la izquierda de la barra de tareas del escritorio y mediante el cual ejecutamos cualquier tarea (iniciar programas, abrir documentos, obtener ayuda, buscar archivos o carpetas, configurar el sistema o las impresoras...");
Insercion("Botón secundario","Botón derecho del ratón. Muestra un menú emergente o contextual.");
Insercion("Browser","Navegador para poder visualizar las páginas Web en Internet.");
Insercion("Buffer","Memoria intermedia que se utiliza en distintos periféricos.");
Insercion("Bump mapping","Técnica por la cual se consigue dotar a las texturas de un relieve simulado.");
Insercion("Bus","Especie de carretera por donde circulan los datos dentro del ordenador comunicando a los diferentes componentes de la placa base, que dependiendo de su tamaño harán que un ordenador tenga mayores o menores prestaciones, así como una mayor o menor capacidad de transferencia del ordenador.");
Insercion("Buscador","Servidor de Internet que organiza los ficheros por grupos temáticos y que permite la localización de páginas Web mediante unas palabras clave que introduce el usuario, sin necesidad de conocer las direcciones de las citadas páginas.");
Insercion("Bus Serie Universal (USB)","Estándar de hardware para la conexión de dispositivos externos, permite la instalación Plug and Play, de forma que puede agregar nuevos dispositivos al equipo sin tener que agregar ni tarjetas adaptadoras ni apagarlo.");
Insercion("Byte","Medida básica de capacidad en informática. Comprende 8 bits o interruptores, cada uno de los cuales puede conmutar en dos posiciones ON y OFF.");
Insercion("Cache","Carpeta o memoria intermedia que almacena temporalmente los archivos del equipo.");
Insercion("CAD","(Computer Aided Design): Diseño asistido por ordenador-");
Insercion("CAM","Fabricación asistida por ordenador.");
Insercion("Canal","Lugar Web que entrega el contenido de Internet en el ordenador. Los canales copian automáticamente el contenido desde Internet al sistema cuando nos suscribimos a un sitio.");
Insercion("Cancelmoose","Persona que declara la guerra al spamming.");
Insercion("Carpeta","Contenedor que sirve para almacenar archivos u otras carpetas.");
Insercion("Caudal","Cantidad de ocupación de un ancho de banda.");
Insercion("CD","Disco compacto óptico, de 12 cms. de diámetro, que se utiliza para almacenamiento binario.");
Insercion("CD-A","Compact-disc de música.");
Insercion("CD-R","Disco compacto sobre el que se puede escribir una sola vez.");
Insercion("CD-ROM","Disco compacto de sólo lectura, soporte de almacenamiento de datos de gran capacidad");
Insercion("CD-RW","Disco compacto regrabable, que se puede escribir, borrar y reescribir encima.");
Insercion("CD-Vídeo","Disco compacto que contiene imagen de vídeo, películas o clips musicales.");
Insercion("Celeron","Versión de Pentium II de gama baja sin memoria caché externa.");
Insercion("CGI","Programa que reside y se ejecuta en el servidor y que envía su salida al navegador de Internet del usuario, como, por ejemplo, un formulario de envío.");
Insercion("Chat","Servicio de Internet basado en la comunicación en tiempo real y mediante teclado entre personas.");
Insercion("Chatear","Función que permite conversar en tiempo real y dentro de Internet entre personas situadas en distintos puntos del planeta mediante la utilización del teclado.");
Insercion("Cheat code","Trucos para pasar los distintos niveles o pantallas de los videojuegos.");
Insercion("Chip","Circuito integrado y encapsulado.");
Insercion("Chipset","Conjunto de chips que complementan el rendimiento del procesador principal.");
Insercion("Chroma-key","Método de composición de vídeo que consiste en filmar actores sobre un fondo de cierto color y luego sustituir ese color por otra imagen.");
Insercion("Ciberjuegos","Juegos a los que se puede acceder por Internet y que pueden ser compartidos por los cibernautas.");
Insercion("Cibernauta","Internauta o navegante virtual que accede a cualquier tipo de información disponible en la World Wide Web.");
Insercion("Cibernética","Ciencia que estudia el diseño de máquinas automáticas o robots con objeto de dotarles de inteligencia humana.");
Insercion("Ciberocupas","Personas que registran el dominio (dirección de una página Web) de un producto o del nombre de una empresa ajena, antes de que la propia interesada lo haga, para después pedir a cambio una cantidad de dinero al dueño legítimo.");
Insercion("CISC", "Procesador u ordenador cuyo juego de instrucciones es complejo o amplio.");
Insercion("Clic", "Pulsar un botón del ratón.");
Insercion("Cliente", "Equipo que se conecta a otro equipo llamado servidor.");
Insercion("Coma flotante","Cálculo que realiza el procesador de operaciones con decimales.");
Insercion("Comando","Orden que se da al ordenador para ejecutar una función concreta o un programa.");
Insercion("Compresor","Programa que comprime ficheros, por muy grandes que éstos sean, genera un solo archivo con ellos, además de dividir la nformación y permitir guardarla en varios disketes.");
Insercion("Concept PC","Concepto que engloba la iniciativa Easy PC y las guías de implementación.");
Insercion("Controlador","Pequeño programa que sirve para reconocer y controlar un dispositivo de hardware específico.");
Insercion("Controles", "En Windows, dícese de los mecanismos que se encuentran en las ventanas, mediante los cuales ejercemos las órdenes oportunas a ejecutar.");
Insercion("Cookies","Mecanismos que permiten a los gestores de cada página web grabar las entradas y salidas de los usuarios que acceden a su servidor. Es como si dejáramos nuestra tarjeta de visita.");
Insercion("Correo electrónico","Mensajes, documentos, archivos que se envían personas a través de Internet o de una red.");
Insercion("Cortafuegos","Programa que protege a una red de otra red.");
Insercion("CPU","Carcasa donde van montados los principales componentes del ordenador. Puede ser de sobremesa, minitorre, semitorre y torre.");
Insercion("Crack","Modifica o salta la protección de la copia de una aplicación.");
Insercion("Cracker","El que comete delitos informáticos con afán de lucro.");
Insercion("Cuadro de diálogo","Ventana mediante la que debemos proporcionar información a una aplicación.");
Insercion("Cursor","Señalizador que se controla mediante el ratón o teclado y mediante el cual nos movemos por Windows y las aplicaciones.");


Buscar("Acceso telefónico a redes");
Buscar("Barra de herramientas");
Buscar("Acceso Directo");
Buscar("Alfanumerico");
Buscar("Algoritmo");
Buscar("ADSL");
Buscar("Backbone");
Buscar("3DNow");
Buscar("Cache");
Buscar("Cursor");
Buscar("Chat");



return 0;


}

