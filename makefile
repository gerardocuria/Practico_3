SRC_DIR =./src
#Leo los archivos guardados en scr
OUT_DIR =./build
#OUT_DIR representa la carpeta build
OBJ_DIR = $(OUT_DIR)/obj
#Guardo los archivo objeto en build/obj
BIN_DIR = $(OUT_DIR)/bin
#Guardo los archivo binario en build/bin
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
#SRC_FILES tiene la lista de archivos c que hay que compilar que estan en SRC_DIR
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
#OBJ:FILES tiene la lista de archivos o que voy a generar a partir de cada archivo c

$(OUT_DIR):
	mkdir $(OUT_DIR)

$(OBJ_DIR) : $(OUT_DIR)
	mkdir $(OBJ_DIR)

$(BIN_DIR) : $(OUT_DIR)
	mkdir $(BIN_DIR)
	
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(OBJ_DIR)
	gcc -c $< -o $@ -I src
# los antecedentes se leen de izquierda a derecha, primero necesito la carpeta obj_dir para luego compilar los archos c y guardarlos dentro	
#-c (compilar) $< (nombre del archivo original), -o (donde lo voy a dejar)												
all: $(OBJ_FILES) $(BIN_DIR)
	gcc -o $(BIN_DIR)/app.elf $(OBJ_FILES)
#echo $(SRC_FILES)
#echo $(OBJ_FILES)  
#echo $(BIN_FILES) 
#echo sirve para ver el contenido de la variable mientras se debaguea el makefile
#Falta comlpletar 

clean: $(OUT_DIR)
	rm -r $(OUT_DIR)

doc:
	doxygen Doxyfile
