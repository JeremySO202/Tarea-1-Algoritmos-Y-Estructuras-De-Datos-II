## Generar archivos ejecutables
Para esto debe abrir la consola de comandos en la carpeta donde se encuentren los archivos .cpp
ejecutar el comando `g++ -o generator generator.cpp` y `g++ -o sorter sorter.cpp`

## Uso del Generator
Para esto debe abrir la consola de comandos en la carpeta donde se encuentren los archivos .cpp
ejecutar el comando `generator -size <SIZE> -output<OUTPUT>`, donde `<SIZE>` puede ser SMALL para 512 MB, MEDIUM para 1GB y LARGE para 2GB. 
El `<OUTPUT>` es la ruta donde desea que se genere el archivo.

## Uso del Sorter
Para esto debe abrir la consola de comandos en la carpeta donde se encuentren los archivos .cpp
ejecutar el comando `sorter -input <INPUT> -output <OUTPUT> -alg <ALG>`, donde `<alg>` puede ser `QS` para Quick sort, `IS` para Insertion sort y `BS` para bubble sort. 
El `<INPUT>` es la ruta donde se encuentra el archivo a ordenar.
El `<OUTPUT>` es la ruta donde desea que se genere el archivo. Este debe de ir sin extension ya que generara un .bin y un .csv con el nombre solicitado.
