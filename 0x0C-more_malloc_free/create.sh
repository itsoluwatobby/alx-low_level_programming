#! /bin/bash

echo -e "Enter file name(s): \c"
read -a file_names

if [ "${#file_names[@]}" -gt 0 ]
then
	touch "${file_names[@]}"
        chmod a+x "${file_names[@]}"
        echo "Files [${file_names[@]}] successfully and execute permission granted"
else	
	echo "File name(s) required"
fi
