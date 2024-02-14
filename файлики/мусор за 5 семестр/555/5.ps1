$Target = Read-Host -Prompt "Name" # получаем пользовательский ввод имени папки
$Shares = Get-WMIObject -class Win32_share | Where {$_.Name -eq $Target} # получаем объекты класса Win32_share с пользовательским именем
gwmi win32_share # выводим общие папки до удаления
Foreach ($Share in $Shares) {
    $Share.Delete() # Удаляем все папки с именем введённым пользователем
}
gwmi win32_share # выводим общие папки после удаления

Read-Host -Prompt "Press any key to continue..."