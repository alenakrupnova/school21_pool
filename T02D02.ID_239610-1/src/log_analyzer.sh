#!/bin/bash
echo 'What is the path to the file?'
read FILE_PATH

# Проверка существования файла
if [ -f "$FILE_PATH" ]; then
    # Общее количество записей (строк)
    total_entries=$(wc -l < "$FILE_PATH")
    #Кол-во уникальных файлов в папке:
    unique_files=$( cut -d'-' -f1 $FILE_PATH | uniq -c | wc -l )
    #Кол-во изменений хэш-суммы файла:
    hash_changes=$(( $total_entries - $unique_files  ))


    echo "$total_entries $unique_files $hash_changes"
else
    echo "Файла не существует"
fi
