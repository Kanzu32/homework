lab01.exe < 01-example.input.txt > 01-example.actual.txt 2>NUL
fc /N 01-example.actual.txt 01-example.expected.txt

lab01.exe < 02-example.input.txt > 02-example.actual.txt 2>NUL
fc /N 02-example.actual.txt 02-example.expected.txt
pause