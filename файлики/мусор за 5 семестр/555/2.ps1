$info = Get-CimInstance -ClassName Win32_OperatingSystem # получаем класс WWin32_OperatingSystem
$caption = $info.Caption # сохраняем наименование ОС
$type = $info.BuildType # сохраняем тип версии ОС
$number = $info.BuildNumber # сохраняем номер версии ОС
Write-output "Windows version: $caption $type $number" # Выводим данные
Read-Host -Prompt "Press any key to continue..."