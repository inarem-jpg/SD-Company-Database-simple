# P8-Ficheros

Fecha: 2024/2025.

Autora: Contreras Mateos, Henar.

Objetivo: Resolución de la ultima práctica de diseño software.

Resumen: implementar el uso de ficheros para guardar los usuarios que hacen login.

  Una práctica relativamente sencilla dentro de lo que cabe, código corto y 
  gracias al uso de ficheros binarios, más corto todavía, solo ha sido necesario
  modificar el main para añadir las dos funciones de guardado y cargado de
  usuarios, los errores del código se mantienen como en la practica anterior,
  principalmente en la visualización de datos de los sensores.

  Todo eso dicho, el código se raya cuendo intentas añadir un usuario que no es
  administrador, no entiendo porqué, pero lo hace, actua como cuando se mete
  una letra en el menu. Lo he intentado corregir pero genuinamente no se donde
  puede estar el fallo.

  He usado un template para las opciones de leer y escribir el fichero, ya que
  si no se usaben el código quedaba muy aparatoso y repetitivo

  Por ejemplo, he cambiado:

```
    outputFile.write(reinterpret_cast<const char*>(&isAdmin), sizeof(isAdmin));
```
  Por:

```
  writeToFile(outputFile, isAdmin);
```
  añadiendo al principio:
```
template <typename T>
void writeToFile(std::ofstream& file, const T& data) {
    file.write(reinterpret_cast<const char*>(&data), sizeof(T));
```

  Saque la idea de guardar el tamaño del nombre del fichero randomFiles1, para
  saber hasta donde leer el nombre.

  He tenido que crear el codigo create.cpp para crear users.dat con dos usuarios  
  iniciales para que fuencione el código, este sólo se ha de ejecutar una vez, 
  por ello está fuera de la carpeta de archivos de código.


