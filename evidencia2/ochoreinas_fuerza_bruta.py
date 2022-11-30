import random
#Fuerza Bruta
tablero = [[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0]]

def imprimir_tablero(tablero):
    for i in range(8):
        for j in range(8):
            print(tablero[i][j], end=" ")
        print()

def check_attack(i, j):
    for k in range(8):
        if tablero[i][k] == 1 or tablero[k][j] == 1:
            return True
    for k in range(8):
        for l in range(8):
            if (k + l == i + j) or (k - l == i - j):
                if tablero[k][l] == 1:
                    return True

counter = 0
counterIntento = 1
totalIntentos = 1

while True:
    i = random.randint(0, 7)
    j = random.randint(0, 7)

    if not check_attack(i, j):
        tablero[i][j] = 1
        counter += 1
        print("counter: ", counter)
        imprimir_tablero(tablero)

    counterIntento += 1
    if counterIntento > 1000000:
        counter = 0
        counterIntento = 1
        tablero = [[0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0]]

    totalIntentos += 1

    if counter == 8:
        print("Solucion encontrada en el intento: ", totalIntentos)
        imprimir_tablero(tablero)
        break

