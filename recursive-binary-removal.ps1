# script to recursively remove all the .exe 
# files generated when compiling and running cpp files
$listItems = Get-ChildItem -Recurse -Include *.exe

foreach ($item in $listItems) {
    Write-Host "deleting" + $item
    Remove-Item -Recurse $item
}