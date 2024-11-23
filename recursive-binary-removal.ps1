# script to recursively remove all the .exe 
# files generated when compiling and running cpp files

# DO NOT RUN THIS SCRIPT OUTSIDE OF THIS FOLDER
# IT WILL DELETE ALL EXE FILES IN THE FOLDER YOU MOVE IT INTO AND RUN IT IN
$listItems = Get-ChildItem -Recurse -Include *.exe

foreach ($item in $listItems) {
    Write-Host "deleting" + $item
    Remove-Item -Recurse $item
}