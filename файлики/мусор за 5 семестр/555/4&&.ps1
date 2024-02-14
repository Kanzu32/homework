$Username = Read-Host -Prompt "Enter username"
$Password = Read-Host -AsSecureString -Prompt "Enter password"

New-LocalUser -Name $Username -Password $Password -Disabled
Read-Host -Prompt "Press any key to continue..."

# Remove-LocalUser -Name $Username
# Read-Host -Prompt "Press any key to continue..."