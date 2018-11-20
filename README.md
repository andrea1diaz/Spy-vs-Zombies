# Spy-vs-Zombies
El juego es un saltador simple, trata que el personaje principal (the spy) trata de sobrevivir a los zombies saltando.

## Instalación de la libreria SDL2 en windows
Siga este tutorial de Lazy Foo
  http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/index.php
  
## Instalación de la libreria SDL2 en Mac
http://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/index.php
  **todavia no funciona bien en XCode 10 (19-11-2018)
  
## Instalación de la libreria SDL2_image en windows
Todas las librerias necesarias estan en la carpeta Frameworks
http://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/windows/msvsnet2010u/index.php

## Instalación de la libreria SDL2_image en Mac
Entrar a terminal y poner lo siguiente
```
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" < /dev/null 2> /dev/null
```
presionar enter
```
brew install sdl2_image
```
al descargar si entras al archivo GAME.xcodeproj los frameworks ya estaran linkeados al proyecto.
