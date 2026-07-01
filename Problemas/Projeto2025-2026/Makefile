CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
TARGET = Projeto2025-2026
OBJS = aluno.o Projeto2025-2026.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

aluno.o: aluno.c aluno.h
	$(CC) $(CFLAGS) -c aluno.c

Projeto2025-2026.o: Projeto2025-2026.c aluno.h
	$(CC) $(CFLAGS) -c Projeto2025-2026.c

clean:
	rm -f $(OBJS) $(TARGET)
