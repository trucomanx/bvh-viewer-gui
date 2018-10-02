#!/bin/bash

#make clean
#make distclean

rm -f *.Debug
rm -f *.Release
rm -f *.json
rm -f *.pro.user
rm -f *.pro.user.*
rm -f manifest.json

if [ -f Makefile ]; then
   make distclean
fi

rm -f -r bin

rm -f Makefile


#mv -f */*.deb ../


