.PHONY: all ds ds-clean

all: ds ds-clean pc pc-clean wii wii-clean

ds:
	$(MAKE) -C ./Makefiles -f makefile_ds

ds-clean:
	$(MAKE) -C ./Makefiles -f makefile_ds clean

pc:
	$(MAKE) -C ./Makefiles -f makefile_pc

pc-clean:
	$(MAKE) -C ./Makefiles -f makefile_pc clean

wii:
	$(MAKE) -C ./Makefiles -f makefile_rvl

wii-clean:
	$(MAKE) -C ./Makefiles -f makefile_rvl clean
