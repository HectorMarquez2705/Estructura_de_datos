def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return factorial(n-1) * n


def valor(c):
    if '0' <= c <= '9':
        return ord(c) - ord('0')
    elif 'A' <= c <= 'Z':
        return ord(c) - ord('A') + 10
    elif 'a' <= c <= 'z':
        return ord(c) - ord('a') + 10
    return -1


def baseadecimal(numero, base, indice):
    if indice == len(numero):
        return 0

    digito = valor(numero[indice])

    return digito * (base ** (len(numero) - indice - 1)) + baseadecimal(numero, base, indice + 1)


def serie(x, n):
    if n == 1:
        return x
    else:
        return serie(x, n-1) + ((-1)**(n+1)) * (x**n) / factorial(n)


opcion = -1

while opcion != 0:

    print("Seleccione una opcion:")
    print("1. Factorial")
    print("2. Transformar de base n a decimal")
    print("3. Serie")
    print("0. Salir")

    opcion = int(input("Opcion: "))

    if opcion == 1:
        num = int(input("Ingrese el numero a calcular el factorial: "))
        print("El factorial de", num, "es:", factorial(num))

    elif opcion == 2:
        numero = input("Ingrese el numero: ")
        base = int(input("Ingrese la base: "))
        resultado = baseadecimal(numero, base, 0)
        print("En decimal es:", resultado)

    elif opcion == 3:
        x = float(input("Ingresar x: "))
        n = int(input("Ingresar n: "))
        print("El resultado de la serie es:", serie(x, n))

    elif opcion == 0:
        print("Hasta luego!")

    else:
        print("Opcion no valida. Intenta de nuevo.")

    input("Presione ENTER para continuar...")
