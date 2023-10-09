MODE=Debug


Static:
        cd automate && make $@
        @echo "building library OK!"
        cd campuslex && make $@
        @echo "building application OK!"

Dynamic:
        cd automate && make $@
        @echo "building library OK!"
        cd campuslex && make $@
        @echo "building application OK!"
Clean:
        cd campuslex && make $@
        cd automate && make $@


ALL:
        cd automate && make $@ MODE=Debug
        cd automate && make $@ MODE=Release
        cd campuslex && make $@ MODE=Debug
        cd campuslex && make $@ MODE=Release

all:Static Dynamic

.PHONY: campuslex automate all ALL Clean
