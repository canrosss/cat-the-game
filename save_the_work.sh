#!/bin/bash

echo "Añadiendo todos los archivos al repo!\n"
git add .
echo "¿De que se trata tu commit?"
read commit
git commit -m "$commit"
echo "Enviando al mundo el trabajo"
git push -u origin master
