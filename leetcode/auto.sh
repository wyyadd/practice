#! usr/bin/bash
echo "Please input dir name"
read dir
if [ $dir ]; then
	mkdir $dir
	cd $dir
	vim "$dir.cc"
else
	echo "No dir name detected. Quit"
	exit
fi
echo "done"
