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
   echo "Debe indicar el archivo con el listado de usuarios a eliminar..."
   exit 1
fi

eliminargsrupo(){
	# se hace la evaluacion a partir del nombre del grupo
	eval nombreGrupo="$1"
	# para esto se indica: si grep (se encuentran cincidencias) con
	# el parametro que se lee dentro del archivo group
	if grep -q ${nombreGrupo} /etc/group
	# entonces eliminal (groupdel) el parametro que se te asigno
	# y tambien manda un mensaje indicando que se hizo correctamente
    then  
        groupdel "${nombreGrupo}"
		echo " El grupo [${nombreGrupo}] se elimino correctamente"
	# si no se encuntran coincidencias manda un mensaje
	else
		echo " El grupo [${nombreGrupo}] no se pudo eliminar"
	fi
}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"	
done < ${file}

exit 0