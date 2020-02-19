#!/bin/sh
#不更新库的情况
cp -f ../cmake-build-debug/Damn ../../DamnPack/Pack/DamnGame.app/Contents/MacOS
cp -rf ../media ../../DamnPack/Pack/DamnGame.app/Contents
hdiutil create -srcfolder ../../DamnPack/Pack -volname DamnGame ./DamnGame.dmg
