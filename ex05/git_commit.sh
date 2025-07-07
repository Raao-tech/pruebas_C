#!/bin/bash
# Define el número de commits a mostrar
NUM_COMMITS=5

# Ejecuta el comando git log para obtener los últimos commits
git log -n $NUM_COMMITS --oneline
