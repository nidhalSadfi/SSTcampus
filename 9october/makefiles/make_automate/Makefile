MODE=Debug
OPT=g
ALL:Dynamic Static
Dynamic:bin/Dynamic/$(MODE)/libautomate.so
Static:bin/Static/$(MODE)/libautomate.a

bin/Dynamic/$(MODE)/libautomate.so:obj/$(MODE)/main.o
        @echo "Linking Dynamic library.."
        mkdir -p bin/Dynamic/$(MODE)
        gcc -shared obj/$(MODE)/*.o -o bin/Dynamic/$(MODE)/libautomate.so
bin/Static/$(MODE)/libautomate.a:obj/$(MODE)/main.o
        @echo "Linking Static library.."
        mkdir -p bin/Static/$(MODE)
        ar -r bin/Static/$(MODE)/libautomate.a obj/$(MODE)/*.o
obj/$(MODE)/main.o:main.c inc/automate.h
        @echo "compiling sources.."
        mkdir -p obj/$(MODE)
        gcc -c -$(OPT) main.c -o obj/$(MODE)/main.o

Clean:
        @echo "try to clean context ..."
