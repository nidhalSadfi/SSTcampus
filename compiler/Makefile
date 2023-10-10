MODE=Debug
Static:
	cd automate && make $@
	@echo "building library OK!"
	cd CampusLex && make $@
	@echo "building application OK!"

Dynamic:
	cd automate && make $@
	@echo "building library OK!"
	cd CampusLex && make $@
	@echo "building application OK!"
Clean:
	cd CampusLex && make $@
	cd automate && make $@


ALL:
	cd automate && make $@ MODE=Debug
	cd automate && make $@ MODE=Release
	cd CampusLex && make $@ MODE=Debug
	cd CampusLex && make $@ MODE=Release

all:Static Dynamic

.PHONY: CampusLex automate all ALL Clean
