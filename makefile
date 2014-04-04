compile: parse.cc fooditems.cc fooditems.h warehouses.cc warehouses.h warehouse.cc warehouse.h date.cc date.h item.cc item.h requests.cc requests.h
	g++ -g parse.cc fooditems.cc warehouses.cc warehouse.cc date.cc item.cc requests.cc

run1:
	./a.out tests/data1.txt 
run2:
	./a.out tests/data2.txt 
run3:
	./a.out tests/data3.txt 
run4:
	./a.out tests/data4.txt 
run5:
	./a.out tests/data5.txt 
clean:
	 rm *~ *a.out