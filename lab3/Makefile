all:
	# recreate the build directory
	rm -rf build
	mkdir build

	# compile programs
	gcc writer.c -o build/writer -Wno-extern-initializer
	gcc reader.c -o build/reader -Wno-extern-initializer
