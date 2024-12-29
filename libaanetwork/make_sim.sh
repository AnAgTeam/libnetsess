cmake -G Xcode -B build_sim -DCMAKE_TOOLCHAIN_FILE=ios.toolchain.cmake -DPLATFORM=SIMULATOR64 -DARCHS="arm64 x86_64"
cmake -G Xcode -B build_mob -DCMAKE_TOOLCHAIN_FILE=ios.toolchain.cmake -DPLATFORM=OS64

cmake --build build_sim --config Release
cmake --build build_mob --config Release

mkdir libaanetwork.xcframework
mkdir libaanetwork.xcframework/ios-arm64
mkdir libaanetwork.xcframework/ios-arm64_x86_64-simulator
mkdir include
mkdir include/libaanetwork
cp build_mob/Release-iphoneos/libaanetwork.a libaanetwork.xcframework/ios-arm64/libaanetwork.a
cp build_sim/Release-iphonesimulator/libaanetwork.a libaanetwork.xcframework/ios-arm64_x86_64-simulator/libaanetwork.a
cp Info.plist libaanetwork.xcframework/Info.plist
cp *.hpp include/libaanetwork