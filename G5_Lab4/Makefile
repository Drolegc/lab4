OBJETOS = ICollectible.o IKey.o OrderedKey.o IIterator.o ICollection.o \
ListNode.o ListIterator.o List.o IDictionary.o OrderedDictionaryEntry.o \
OrderedDictionary.o String.o StringKey.o IntKey.o \
DtCine.o DtDireccion.o DtFecha.o DtFuncion.o DtHora.o DtPelicula.o DtSala.o \
Cine.o Credito.o Debito.o Funcion.o Pelicula.o Reserva.o Sala.o Usuario.o \
ControladorSistema.o Fabrica.o ISistema.o

FUENTES = ICollection/interfaces/ICollectible.cpp ICollection/interfaces/ICollectible.h \
ICollection/interfaces/IKey.cpp ICollection/interfaces/IKey.h \
ICollection/interfaces/OrderedKey.cpp ICollection/interfaces/OrderedKey.h \
ICollection/interfaces/IIterator.cpp ICollection/interfaces/IIterator.h \
ICollection/interfaces/ICollection.cpp ICollection/interfaces/ICollection.h \
ICollection/collections/ListNode.cpp ICollection/collections/ListNode.h \
ICollection/collections/ListIterator.cpp ICollection/collections/ListIterator.h \
ICollection/collections/List.cpp ICollection/collections/List.h \
ICollection/interfaces/IDictionary.cpp ICollection/interfaces/IDictionary.h \
ICollection/collections/OrderedDictionaryEntry.cpp ICollection/collections/OrderedDictionaryEntry.h \
ICollection/collections/OrderedDictionary.cpp ICollection/collections/OrderedDictionary.h \
ICollection/String.cpp ICollection/String.h \
IColection/StringKey.cpp ICollection/StringKey.h \
IColection/IntKey.cpp ICollection/IntKey.h \
datatypes/sources/DtCine.cpp datatypes/headers/DtCine.h \
datatypes/sources/DtDireccion.cpp datatypes/headers/DtDireccion.h \
datatypes/sources/DtFecha.cpp datatypes/headers/DtFecha.h \
datatypes/sources/DtFuncion.cpp datatypes/headers/DtFuncion.h \
datatypes/sources/DtHora.cpp datatypes/headers/DtHora.h \
datatypes/sources/DtPelicula.cpp datatypes/headers/DtPelicula.h \
datatypes/sources/DtSala.cpp datatypes/headers/DtSala.h \
classes/sources/Cine.cpp classes/headers/Cine.h \
classes/sources/Credito.cpp classes/headers/Credito.h \
classes/sources/Debito.cpp classes/headers/Debito.h \
classes/sources/Funcion.cpp classes/headers/Funcion.h \
classes/sources/Pelicula.cpp classes/headers/Pelicula.h \
classes/sources/Reserva.cpp classes/headers/Reserva.h \
classes/sources/Sala.cpp classes/headers/Sala.h \
classes/sources/Usuario.cpp classes/headers/Usuario.h \
classes/interfaces/ControladorSistema.cpp classes/interfaces/ControladorSistema.h \
classes/interfaces/Fabrica.cpp classes/interfaces/Fabirca.h \
classes/interfaces/ISistema.cpp classes/interfaces/ISistema.h

CC = g++
OPCIONES = -std=c++11 -g -Wall -Werror

main: $(OBJETOS) main.cpp Makefile
	$(CC) $(OPCIONES) $(OBJETOS) main.cpp -o main

ICollectible.o: ICollection/interfaces/ICollectible.h ICollection/interfaces/ICollectible.cpp
	$(CC) $(OPCIONES) -c ICollection/interfaces/ICollectible.cpp -o ICollectible.o

IKey.o: ICollection/interfaces/IKey.h ICollection/interfaces/IKey.cpp
	$(CC) $(OPCIONES) -c ICollection/interfaces/IKey.cpp -o IKey.o

OrderedKey.o: ICollection/interfaces/OrderedKey.h ICollection/interfaces/OrderedKey.cpp IKey.o
	$(CC) $(OPCIONES) -c ICollection/interfaces/OrderedKey.cpp -o OrderedKey.o

IIterator.o: ICollection/interfaces/IIterator.h ICollection/interfaces/IIterator.cpp ICollectible.o
	$(CC) $(OPCIONES) -c ICollection/interfaces/IIterator.cpp -o IIterator.o

ICollection.o: ICollection/interfaces/ICollection.h ICollection/interfaces/ICollection.cpp IIterator.o
	$(CC) $(OPCIONES) -c ICollection/interfaces/ICollection.cpp -o ICollection.o

ListNode.o: ICollection/collections/ListNode.h ICollection/collections/ListNode.cpp ICollection.o
	$(CC) $(OPCIONES) -c ICollection/collections/ListNode.cpp -o ListNode.o

ListIterator.o: ICollection/collections/ListIterator.h ICollection/collections/ListIterator.cpp ListNode.o
	$(CC) $(OPCIONES) -c ICollection/collections/ListIterator.cpp -o ListIterator.o

List.o: ICollection/collections/List.h ICollection/collections/List.cpp ListNode.o ListIterator.o
	$(CC) $(OPCIONES) -c ICollection/collections/List.cpp -o List.o

IDictionary.o: ICollection/interfaces/IDictionary.h ICollection/interfaces/IDictionary.cpp IKey.o ICollectible.o IIterator.o
	$(CC) $(OPCIONES) -c ICollection/interfaces/IDictionary.cpp -o IDictionary.o

OrderedDictionaryEntry.o: ICollection/collections/OrderedDictionaryEntry.h ICollection/collections/OrderedDictionaryEntry.cpp OrderedKey.o ICollectible.o
	$(CC) $(OPCIONES) -c ICollection/collections/OrderedDictionaryEntry.cpp -o OrderedDictionaryEntry.o

OrderedDictionary.o: ICollection/collections/OrderedDictionary.h ICollection/collections/OrderedDictionary.cpp OrderedDictionaryEntry.o ListNode.o IDictionary.o ListIterator.o
	$(CC) $(OPCIONES) -c ICollection/collections/OrderedDictionary.cpp -o OrderedDictionary.o

String.o: ICollection/String.h ICollection/String.cpp
	$(CC) $(OPCIONES) -c ICollection/String.cpp -o String.o

StringKey.o: ICollection/StringKey.h ICollection/StringKey.cpp
	$(CC) $(OPCIONES) -c ICollection/StringKey.cpp -o StringKey.o
IntKey.o: ICollection/IntKey.h ICollection/IntKey.cpp
	$(CC) $(OPCIONES) -c ICollection/IntKey.cpp -o IntKey.o

DtCine.o: datatypes/sources/DtCine.cpp datatypes/headers/DtCine.h
	$(CC) $(OPCIONES) -c datatypes/sources/DtCine.cpp -o DtCine.o

DtDireccion.o: datatypes/sources/DtDireccion.cpp datatypes/headers/DtDireccion.h
	$(CC) $(OPCIONES) -c datatypes/sources/DtDireccion.cpp -o DtDireccion.o

DtFecha.o: datatypes/sources/DtFecha.cpp datatypes/headers/DtFecha.h
	$(CC) $(OPCIONES) -c datatypes/sources/DtFecha.cpp -o DtFecha.o

DtFuncion.o: datatypes/sources/DtFuncion.cpp datatypes/headers/DtFuncion.h
	$(CC) $(OPCIONES) -c datatypes/sources/DtFuncion.cpp -o DtFuncion.o

DtHora.o: datatypes/sources/DtHora.cpp datatypes/headers/DtHora.h
	$(CC) $(OPCIONES) -c datatypes/sources/DtHora.cpp -o DtHora.o

DtPelicula.o: datatypes/sources/DtPelicula.cpp datatypes/headers/DtPelicula.h
	$(CC) $(OPCIONES) -c datatypes/sources/DtPelicula.cpp -o DtPelicula.o

DtSala.o: datatypes/sources/DtSala.cpp datatypes/headers/DtSala.h
	$(CC) $(OPCIONES) -c datatypes/sources/DtSala.cpp -o DtSala.o

Cine.o: classes/sources/Cine.cpp classes/headers/Cine.h
	$(CC) $(OPCIONES) -c classes/sources/Cine.cpp -o Cine.o

Credito.o: classes/sources/Credito.cpp classes/headers/Credito.h
	$(CC) $(OPCIONES) -c classes/sources/Credito.cpp -o Credito.o

Debito.o: classes/sources/Debito.cpp classes/headers/Debito.h
	$(CC) $(OPCIONES) -c classes/sources/Debito.cpp -o Debito.o

Funcion.o: classes/sources/Funcion.cpp classes/headers/Funcion.h
	$(CC) $(OPCIONES) -c classes/sources/Funcion.cpp -o Funcion.o

Pelicula.o: classes/sources/Pelicula.cpp classes/headers/Pelicula.h
	$(CC) $(OPCIONES) -c classes/sources/Pelicula.cpp -o Pelicula.o

Reserva.o: classes/sources/Reserva.cpp classes/headers/Reserva.h
	$(CC) $(OPCIONES) -c classes/sources/Reserva.cpp -o Reserva.o

Sala.o: classes/sources/Sala.cpp classes/headers/Sala.h
	$(CC) $(OPCIONES) -c classes/sources/Sala.cpp -o Sala.o

Usuario.o: classes/sources/Usuario.cpp classes/headers/Usuario.h
	$(CC) $(OPCIONES) -c classes/sources/Usuario.cpp -o Usuario.o

ControladorSistema.o: classes/interfaces/ControladorSistema.cpp classes/interfaces/ControladorSistema.h
	$(CC) $(OPCIONES) -c classes/interfaces/ControladorSistema.cpp -o ControladorSistema.o

Fabrica.o: classes/interfaces/Fabrica.cpp classes/interfaces/Fabrica.h
	$(CC) $(OPCIONES) -c classes/interfaces/Fabrica.cpp -o Fabrica.o

ISistema.o: classes/interfaces/ISistema.cpp classes/interfaces/ISistema.h
	$(CC) $(OPCIONES) -c classes/interfaces/ISistema.cpp -o ISistema.o

clean:
	rm -f $(OBJETOS) main

rebuild:
	make clean
	make