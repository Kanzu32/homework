$OSSet = Get-WMIObject -class Win32_OperatingSystem # получаем объекты операционной системы
foreach ($OS in $OSSet) {
    $OS.Shutdown() # выключаем компьютер при наличии у пользователя соотв. привелегий
}
