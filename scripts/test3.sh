#!/bin/sh
grep van /etc/passwd
if [ $? -ne 0 ]
then
	echo not reg
fi
