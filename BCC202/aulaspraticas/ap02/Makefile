# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -g
TARGET = exe

# Arquivos objeto
OBJS = regiao.o pratica.o

# Alvo principal
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para aluno.o
aluno.o: regiao.c regiao.h
	$(CC) $(CFLAGS) -c regiao.c

# Regra para pratica.o
pratica.o: pratica.c regiao.h
	$(CC) $(CFLAGS) -c pratica.c

# Limpeza
clean:
	rm -f $(OBJS) $(TARGET)

# Limpeza completa
purge: clean
	rm -f output.out

.PHONY: clean purge
