#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Rary, because we have to run the script somehow with root anyway)
# Validacion de que debe ejecutarse como root
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

# validacion de que se le debe pasar un archivo .csv
file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con Nombres de grupo a ingresar..."
   exit 1
fi

# Del archivo con el listado de grupos a ingresar:
# Este es el formato:
# ejemplo
#    |   
#    f1  
#$f1 = nombreGrupo

crearGrupo(){
	#echo "----> Crear Grupo <----"
	eval nombreGrupo="$1"
	#echo "nombreGrupo 		  = ${nombreGrupo}"
	
	# como eval de errores se verifica la existencia previa de un grupo
	# el enunciado se lee como: SI grep (encuentra coincidencias)
	# con el nombre del grupo que se de, en el archivo group
	if grep -q ${nombreGrupo} /etc/group
	# entonces no agregues nada y manda un mensaje
	then
		echo "Grupo [${nombreGrupo}] No se pudo agregar..."
	# si no crea un nuevo grupo
	else
		groupadd "${nombreGrupo}"
		echo "Grupo [${nombreGrupo}] agregado correctamente..."
		# tambien guardalos en un archivo .csv para su registro
		echo "${nombreGrupo}" >>gruposCreados.csv

	fi
}

while IFS=: read -r f1
do
	crearGrupo "\${f1}"	
done < ${file}

exit 0