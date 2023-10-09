MODE=Debug
OPT=g
DIROBJ=obj/$(MODE)
ifeq ($(MODE),"Release")
  OPT=O2
endif
ALL:Dynamic Static
        @echo "Success building !!!"
Dynamic:bin/Dynamic/$(MODE)/campuslex
        @ls -l $^
        @echo "$@ Application OK!"
Static:bin/Static/$(MODE)/campuslex
        @ls -l $^
        @echo "$@ Application OK!"

bin/Dynamic/$(MODE)/campuslex: obj/$(MODE)/main.o obj/$(MODE)/lexparser.o \
                                ../automate/bin/Dynamic/$(MODE)/libautomate.so
        @echo "Linking Dynamic Application from $?.."
        mkdir -p bin/Dynamic/$(MODE)
        gcc obj/$(MODE)/*.o -lautomate -L../automate/bin/Dynamic/$(MODE) -o bin/Dynamic/$(MODE)/campuslex
bin/Static/$(MODE)/campuslex: obj/$(MODE)/main.o obj/$(MODE)/lexparser.o \
                                ../automate/bin/Static/$(MODE)/libautomate.a
        @echo "Linking Static Application from $?.."
        mkdir -p bin/Static/$(MODE)
        gcc $^ -o bin/Static/$(MODE)/campuslex
$(DIROBJ):$@
        echo "HERE"
        mkdir -p $@

obj/$(MODE)/%.o:%.c lexparser.h lexparserExt.h ../automate/inc/automate.h
        @echo "compiling $* ($@) sources.."
        mkdir -p $(DIROBJ)
        gcc -c -$(OPT) $< -o $@ -I../automate
Clean:
        @echo "try to clean context ..."
        rm -rf obj
        rm -rf bin
        @echo "Application cleaned !"
Rebuild:Clean ALL
default:ALL
.PHONY: Static Dynamic

