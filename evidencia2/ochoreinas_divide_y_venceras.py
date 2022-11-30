import random
#Fuerza Bruta

def imprimir_tablero(tablero):
    for i in range(len(tablero)):
        for j in range(len(tablero)):
            print(tablero[i][j], end=" ")
        print()

def check_attack(seccion, i, j):
    for k in range(4):
        if seccion[i][k] == 1 or seccion[k][j] == 1:
            return True
    for k in range(4):
        for l in range(4):
            if (k + l == i + j) or (k - l == i - j):
                if seccion[k][l] == 1:
                    return True

def checar_seccion():
    seccion = [[0,0,0,0],
               [0,0,0,0],
               [0,0,0,0],
               [0,0,0,0]]
    counter = 0
    counterIntento = 1
    totalIntentos = 1
    while True:
        i = random.randint(0, 3)
        j = random.randint(0, 3)

        if not check_attack(seccion, i, j):
            seccion[i][j] = 1
            counter += 1
            print("counter: ", counter)
            imprimir_tablero(seccion)

        counterIntento += 1
        if counterIntento > 1000000:
            counter = 0
            counterIntento = 1
            seccion = [[0,0,0,0],
                   [0,0,0,0],
                   [0,0,0,0],
                   [0,0,0,0]]

        totalIntentos += 1

        if counter == 2:
            print("Solucion encontrada en el intento: ", totalIntentos)
            imprimir_tablero(seccion)
            break
    return seccion

def solucion():
    solucion = []
    while True:
        seccion = checar_seccion()
        solucion.append(seccion)
        if not check_attack(solucion, 0, 0):

        if len(solucion) == 4:
            break
    return solucion


imprimir_tablero(solucion())

