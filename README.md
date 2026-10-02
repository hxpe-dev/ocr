Pour l'interface on utilise GTK

Pour compiler l'interface sur les PC de l'école : 
```
nix-shell -p pkg-config gtk3 zlib
```


Pour compiler l'interface : 
```
gcc -Wall -Wextra [FICHIER .c] -o [FICHIER SORTIE] $(pkg-config --cflags --libs gtk+-3.0)
```

```
