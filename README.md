webcam_capture

Repositori original: https://github.com/beta-robots/webcam_capture

S'hafegeixesn a l'script original canvis per modificar la imatge webcam que es mostra en pantalla en temps real. Es modifica la intesitat de diferents pixels per mostrar una creu entorn al pìxel central de la imatge. La mida i el color de la creu son triades per l'usuari.

Un cop l'usuari escull el color i la mida de la creu,a la terminal es mostra el valor d'intensitat, captat per la webcam, del píxel central seguint el codi RGB. 

Podria ser una mena de sensor de colors..? (



Instrucions per generar l'executable

1. Fork del repositori al nostre espai de GitHub
2. Clone del repositori. Dins trobem l'arxiu CMakelists.txt, on es defineixen els paràmetres necesaaris per poder compilar, llibreries associades, nom de l'executable que es generarà, etc.
3. Dins del repo, afegim el directori "build" (mkdir build) i a l'interior executem "cmake .." (els ".." son per indicar que l'arxiu de config "CMakelists.txt" es troba al directori superior)
4. Seguidament dins de /build executem "make" per que es el compili el script en .cpp que es troba al directori /src. Obtenim un executable
5. Ja podem fer anar l'executable (./exe). Per fer anar l'executable cal estar dins del direcori on es troba. Si es fa al algún canvi al script cal tornar a repetir el proces per generar un nou executable.

