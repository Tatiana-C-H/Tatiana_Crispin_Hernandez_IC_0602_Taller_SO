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

# el listado de datos aingresar es el mismo que en crearGrupos

agregarusuarios(){
	# en este caso se reciben los datos importantes
	# como lo es el nombre, password, grupo, etc
	# tambien es necesario registrarlos en el directorio home
	eval username="$1"
	eval password="$2"
	eval userid="$3"
	eval grupoid="$4"
	eval useridiinfo"$5"
	eval homedirectory="$6"
	eval comandshell="$7"
	echo "Directorios en /home"
	# se llama a los directorios de home
	echo "$HOME"

	# se manda un mensaje si el nombre del usuario ya existe
	if grep -q ${username} /etc/passwd
	then
		echo "El usuario [${username}] ya existe"
	else
		echo "Usuario agregado a [${homedirectory}] correctamente"
	
	# se muestran datos del grupo si exite o se informa lo cotrario
	if grep -q ${grupoid} /etc/group
	then
		echo "El grupo con ID [${grupoid}] ya existe"
		echo "Su shell es [${comandshell}]"
	else
		echo "El grupo con ID [${grupoid}] no existe"

	useradd -c "${userid} ${useridiinfo}"  -p "${password}" -d "${homedirectory}""${username}" -s "${comandshell}" "${username}"   -u  "${grupoid}"

	echo "Datos"
	echo "Usuario: ${username}  -  Contraseña: ${password} "
	echo ${username} >>usuariosCreados.csv
	fi

	# en caso de que el grupo no exista 
    else
    echo "El grupo con ID [${grupoid}] no existe, se creara"
    echo "Su shell es [${comandshell}]"

    # para la adicion es necesario vaalidar de nuevo los datos
    groupadd "${grupoid}"

    # se manda un mensaje si el nombre del usuario ya existe
    if grep -q ${username} /etc/passwd
    then 
		echo "El usuario [${username}] ya existe"
	else
		echo "Usuario agregado a [${homedirectory}] correctamente"
    fi

    # de nuevo se agrega el usuario tras la validacion
    useradd -c "${userid} ${useridiinfo}"  -p "${password}" -d "${homedirectory}""${username}" -s "${comandshell}" "${username}"   -u  "${grupoid}"
    echo "Usuario agregado"
    echo "Datos:"
    echo "Usuario: ${username}  -  Contraseña: ${password}" 
	echo ${username} >>usuariosCreados.csv
    fi
}

while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do 
    crearusuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"
done < ${file}

exit 0