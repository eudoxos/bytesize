test:
	g++ -std=c++17 -I/home/eudoxos/build/fmt/include -pedantic bytesize-test.cc -o bytesize-test && ./bytesize-test 5.55k 5k 05M 5MB '5.23432 MB' '1044356  kiB' 5.M .5M
