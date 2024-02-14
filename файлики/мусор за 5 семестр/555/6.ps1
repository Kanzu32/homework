$Devices = Get-WMIObject -class Win32_SoundDevice # получаем все звуковые устройства

Foreach ($Device in $Devices) {
    $Device # выводим информацию о каждом звуковом устройстве
}