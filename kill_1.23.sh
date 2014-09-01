#!/bin/tcsh
kill `ps -axu | grep 1.23 | grep -v grep | grep -v gam | awk '{print $2}'`
ls -lah;
rm *.core;
