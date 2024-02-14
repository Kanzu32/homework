$time = Get-CimInstance -ClassName Win32_TimeZone -Property * # берём все поля класса Win32_TimeZone
$time.Description # Выводим описание текущего часового пояса
Read-Host -Prompt "Press any key to continue..." # Ожидаем ввода от пользователя для предотвращения преждевременного закрытия программы