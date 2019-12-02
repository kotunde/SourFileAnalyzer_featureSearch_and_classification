#!/bin/bash

#check parameter number
if (($#<2)); then
	echo Usage: sapi_data_ast_func.sh data_dir target_konyvtar
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
		echo we cannot create the target directory
		exit 1
	else
		#print it if we succeded
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
	#go through user directory by cpp sourcefiles
	for labor in $(ls "$data/$user")
	do
		if ! mkdir "$target/$user/$labor" 2>/dev/null
		then
			echo we cannot create "$target/$user/$labor" labor directory
			exit 1
		fi
		chmod 774 $target/$user/$labor
		#go through labor directory by feladat
		for feladat in $(ls "$data/$user/$labor")
		do
			if ! mkdir "$target/$user/$labor/$feladat" 2>/dev/null
			then
				echo we cannot create "$target/$user/$labor/$feladat" directory
				exit 1
			fi
			chmod 774 $target/$user/$labor/$feladat
			echo $pwd
			#go through feladat directory by cpp files
			for sourceFile in $(ls $data/$user/$labor/$feladat |  egrep "*.cpp")
			do
				cd "./$target/$user/$labor/$feladat"
				echo python "${original_loc}/funcNamesFromFile.py"  "$sourceFile"
				python "${original_loc}/funcNamesFromFile.py" "$original_loc/$data/$user/$labor/$feladat/$sourceFile" $sourceFile
				python "${original_loc}/createAstByFuncName.py" "$original_loc/$data/$user/$labor/$feladat/$sourceFile" 
				cd "$original_loc"
			done
			
		done
	done
done
