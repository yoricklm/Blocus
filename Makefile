#Auteur: yorick LE MOING Groupe: 6

#BUT FINAL

but : blocus

#VARIABLES

OFILES = fenetre1.o fenetre2.o fenetre3.o initialisation.o main.o

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g

#DEPENDANCES

fenetre1.o: fenetre1.h initialisation.h

fenetre2.o: fenetre2.h initialisation.h

fenetre3.o: fenetre3.h initialisation.h

initialisation.o: initialisation.h

main.o: fenetre1.h fenetre2.h fenetre3.h initialisation.h

#DEPENDANCES AVEC COMMANDES

blocus: $(OFILES)
	$(CC) $(CFLAGS) -o blocus $(OFILES) -lgraph

#NETTOYAGE DES FICHIERS GENERES

clean :	-rm -f  $(OFILES) 

#BUTS FACTICES

.PHONY : clean but
