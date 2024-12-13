# Nom de l'exécutable
TARGET = analyse_ip

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Fichiers sources et objets
SRCS = analyse_ip.c

# Règle par défaut
all: $(TARGET)

# Lien des objets pour créer l'exécutable
$(TARGET): $(SRCS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	@rm -f $(TARGET)
	@rm -f resultat_ip.txt

# Indiquer que les cibles 'clean' et 'all' ne sont pas des fichiers
.PHONY: clean all
