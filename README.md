# webcam_capture
Just webcam capture

## Tips
https://wiki.archlinux.org/index.php/webcam_setup

http://www.linuxintro.org/wiki/Set_up_a_Webcam_with_Linux




1. Fork del repositori al nostre espai de GitHub
2. Clone del repositori. Dins trobem l'arxiu CMakelists.txt, on es defineixen els paràmetres necesaaris per poder compilar, llibreries associades, nom de l'executable que es generarà, etc.
3. Dins del repo, afegim el directori "build" (mkdir build) i a l'interior executem "cmake .." (els ".." son per indicar que l'arxiu de config "CMakelists.txt" es troba al directori superior)
4. Seguidament dins de /build executem "make" per que es el compili el script en .cpp que es troba al directori /src. Obtenim un executable
5. Ja podem fer anar l'executable (./exe). Per fer anar l'executable cal estar dins del direcori on es troba. Si es fa al algún canvi al script cal tornar a repetir el proces per generar un nou executable.

