$Target = Read-Host -Prompt "Name"
$Shares = [WMICLASS]"Win32_share"
$Shares.Create("c:\",$Target,0)
gwmi win32_share
Read-Host -Prompt "Press any key to continue..."