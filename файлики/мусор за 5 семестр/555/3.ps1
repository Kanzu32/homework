$procs = Get-ChildItem -Path Registry::HKEY_LOCAL_MACHINE\HARDWARE\DESCRIPTION\System\CentralProcessor # получаем часть реестрового дерева по соотв. пути
$procs[0] # выводим информацию о процессоре
Read-Host -Prompt "Press any key to continue..."