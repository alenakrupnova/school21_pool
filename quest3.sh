Переименовали папку:
mv door_management_fi door_management_files

Открыли доступ:
Chmod +x ai_door_management_module.sh

Открыли папку:
cd door_management_files

Создаем папки:
mkdir door_configuration
mkdir door_logs
mkdir door_map

Переносим все файлы с определенным расширением в нужные папки:
mv *.conf door_configuration
migasdel@ga-l1 door_management_files % mv *.log door_logs


Создаем файл src :
touch quest3.sh

Редактируем файл:
vi quest3.sh 
i


