$Drives = Get-WMIObject -class Win32_LogicalDisk # получаем информацию о логических дисках

Foreach ($Drive in $Drives) {
    $id = $Drive.DeviceID # получаем метку диска
    $size = $Drive.Size # размер диска
    $free = $Drive.FreeSpace # свободное место
    $system = $Drive.FileSystem # тип файловой системы
    Write-output "Name: $id Size: $size Free space: $free File system: $system" # выводим данные
}