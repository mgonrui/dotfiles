#!/usr/bin/sh

# Verificar el diseño actual del teclado
current_layout=$(setxkbmap -query | grep layout | awk '{print $2}')

# Definir el diseño opuesto
opposite_layout="us"
if [ "$current_layout" == "us" ]; then
    opposite_layout="es"
fi

# Cambiar el diseño del teclado
setxkbmap $opposite_layout

# echo "Se ha cambiado el diseño del teclado a $opposite_layout"
