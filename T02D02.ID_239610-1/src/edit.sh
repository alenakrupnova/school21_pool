#!/bin/bash
echo 'What is the path to the file?'
read FILE_PATH
echo 'What is the string to be replaced?'
read string
echo 'What is the replacement itself (as a string)?'
read replace

# Проверка существования файла
if [ -f "$FILE_PATH" ] && [ "$string" ] && [ "$replace" ] ; then
    sed -i '' "s/${string}/${replace}/g" "$FILE_PATH"
    date=$( stat -f "%Sm" -t "%Y-%m-%d %H:%M"  $FILE_PATH )
    size=$( stat -f %z $FILE_PATH )
    shasum=$( shasum -a 256 $FILE_PATH | cut -d ' ' -f 1 )
    echo "$FILE_PATH - $size - $date - $shasum - shasum -a 256"  >> files.log
else
    echo "Неверно введенные данные"
fi
