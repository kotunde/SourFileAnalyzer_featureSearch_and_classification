#!/bin/bash

#chech parameter number
if (($#<2)); then
	echo Usage: gcj_data_ast_func.sh data_dir target_dir
	exit 1
fi

#get parameters
data="$1"
target="$2"
original_loc=$(pwd)
echo PWD: $original_loc

#check directories
if ! [ -d "$data" ]
then
	echo "$data" directory does not exist
	exit 1
fi
chmod -R 774 $data

#if the target directory does not exist, we create it
if ! [ -d "$target" ]
then
	if ! mkdir "$target" 2>/dev/null
	then
		echo cannot create the target directory
		exit 1
	else
		#print it if it succeded
		echo "$target" new directory
		chmod -fR 774 $target
	fi
fi

#check if we can create files in the target directory
if ! [ -w "$target" ]
then
	echo "in" "$target" we cannot create new files
	exit 1
fi

#go through data user by user
for user in $(ls "$data")
do
	if ! mkdir "$target/$user" 2>/dev/null
	then
		echo we cannot create the user directory
		exit 1
	fi
	chmod 774 $target/$user
	echo $pwd
	#go through user directory by cpp sourcefiles
	for sourceFile in $(ls $data/$user |  egrep "*.cpp")
	do
		cd "./$target/$user"
		echo python "${original_loc}/funcNamesFromFile.py"  "$sourceFile"
		python "${original_loc}/funcNamesFromFile.py" "$original_loc/$data/$user/$sourceFile" $sourceFile
		python "${original_loc}/createAstByFuncName.py" "$original_loc/$data/$user/$sourceFile" 
		cd "$original_loc"
	done

done
		
