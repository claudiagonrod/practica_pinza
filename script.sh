#!/bin/bash

echo "Ejecutando programa..."

./pinza &

PID=$!

echo "Proceso lanzado con PID: $PID"

wait $PID

echo "Proceso terminado"

#Comprobar si sigue activo
if ps -p $PID > /dev/null
then 
	echo "El proceso sigue activo. Finalizando..."
	kill $PID
else
	echo "El proceso ya ha finalizado correctamente"
fi

