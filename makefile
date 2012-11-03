all: src/ShiftMatrix.ino
	ino build -m atmega328
	ino upload -m atmega328