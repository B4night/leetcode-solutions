# this shell script is used for clean executable files, which is files whose names are made up with numbers.
ls | grep -E "^[0-9]*$" | xargs -I {} rm -rf {}

