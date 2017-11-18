CC=cl65
CFLAGS=-ttelestrat

PROGRAM=tar
SOURCE=src/$(PROGRAM).c
LDFILES=


ASFLAGS=-C -W -e error.txt -l xa_labels.txt -DTARGET_ORIX

$(PROGRAM): $(SOURCE)
	$(CC)  $(CFLAGS) -o $(PROGRAM) $(LDFILES) $(SOURCE)

test:
	mkdir -p build/bin/
	mkdir -p build/usr/share/man
	mkdir -p build/usr/share/ipkg  
	mkdir -p build/usr/share/doc/$(PROGRAM)/
	cp $(PROGRAM) build/bin/
	cp src/man/$(PROGRAM).hlp build/usr/share/man
	cp README.md build/usr/share/doc/$(PROGRAM)/
	cp src/ipkg/$(PROGRAM).csv build/usr/share/ipkg
	cd build &&	tar -c * > ../$(PROGRAM).tar &&	cd ..  
	filepack  $(PROGRAM).tar $(PROGRAM).pkg
	gzip $(PROGRAM).tar
	mv $(PROGRAM).tar.gz $(PROGRAM).tgz
	php buildTestAndRelease/publish/publish2repo.php $(PROGRAM).pkg ${hash} 6502 pkg alpha
	php buildTestAndRelease/publish/publish2repo.php $(PROGRAM).tgz ${hash} 6502 tgz alpha 
	echo nothing
