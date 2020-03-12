#!/bin/sh
#不更新库的情况
cp -rf ../../DamnPack/DamnGame ../../DamnPack/DG/DamnGame.app
cp -f ../cmake-build-release/Damn ../../DamnPack/DG/DamnGame.app/Contents/MacOS
cp -rf ../media ../../DamnPack/DG/DamnGame.app/Contents
hdiutil create -srcfolder ../../DamnPack/DG -volname DamnGame ./DamnGame.dmg
rm -rf ../../DamnPack/DG/DamnGame.app
