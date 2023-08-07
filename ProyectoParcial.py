#Equipo 7: Jorge Cerda, Daniel Vega, Luís García, Juan Manuel
#Matrículas: 34628,29938 , 34991, 27380
#Descripción: Programa que checa los brackets de una línea de código
#Fecha: 11/09/22

class Pila():
    #Crear Pila (Constructor)
    def __init__(self, size):

        self.items = []
        self.indice = -1
        self.size = size
    #Comprobar si la pila esta vacía
    def pila_vacia(self):

        if self.indice == -1:
            return True
        else:
            return False
    #Comprobar si la pila esta llena
    def pila_llena(self):
        if self.indice == self.size -1:
            return True
        else:
            return False
    #Agregar un nuevo dato a la pila
    def push_pila(self, dato):
        if self.pila_llena():
            print("Pila llena")
        else:
            self.items.append(dato)
            self.indice += 1
    #Quitar un dato de la pila
    def quitar_pila(self):
        if self.pila_vacia():
            print("No hay elementos para quitar")
        else:
            aux = self.items.pop(self.indice)
            self.indice -= 1
            return aux

#En la función comparador se va a evaluar si los dos brackets son los correspondientes
def Comparador(bracketabierto, bracketcerrado):
    #En cualquier caso donde el bracket abierto corresponda con el bracket cerrado
    #Se regresara como verdadero
    if bracketabierto == '[' and bracketcerrado == ']':
        return True
    if bracketabierto == '{' and bracketcerrado == '}':
        return True
    if bracketabierto == '(' and bracketcerrado == ')':
        return True
    #En el caso donde los brackets no correspondan se regresara falso
    return False


#Función para buscar los brackets y marcar errores si existen
def Inspector(texto):
    #Vamos a crear una variable tamaño para guardar el tamaño que tiene el texto, osea el número de carácteres
    tamaño = len(texto)
    #Vamos a crear un pila para guardar los brackets que habren, '(', '{', '['
    stack = Pila(tamaño)
    #El índice va a marcar la posición donde se encuentre el error
    índice = 0
    #Dentro del for recorreremos el texto completo, un variable string es una lista de caractéres
    for i in range(tamaño):
        #Se sumara cada pasada 1 al índice
        índice += 1
        #Lo primero que se hara sera evaluar si el caracter en esa pasada es un bracket que abre
        if texto[i] in ("(", "{", "["):
            #Si el caracter es un bracket que abre se guardara en nuestra pila
            #Esta forma podemos trabajar con ellos sin manipular la lista directamente
            stack.push_pila(texto[i])
            #La pila se hace porque el último elemento en ingresar a la pila tendra que ser el primero en cerrarse
            #Ejemplo si es un '(' el caracter que sigue tendra que ser un ')', en cualquier otro caso esta mal cerrado
        
        #En el caso donde no se encuentre un bracket que abre pero sí uno que cierre se tendra que regresar el índice
        #Esto porque no puede existir un bracket que cierre sin uno que abra
        #Para hacer esto primero se evalua si es un bracket que cierra este caracter
        elif texto[i] in ("]", ")", "}"):
            #Luego se evalua si la pila donde se guardan los brackets abiertos esta vacía
            if stack.pila_vacia() == True:
                    #Si la pila esta vacía significa que ese bracket nunca se abrió por lo tanto hay un error
                    #Por lo tanto se regresara la posición, que es el índice
                    return índice
            else:
                #En el caso donde la pila si tenga elementos tendremos que evaluar si ese bracket es el correcto
                #Primero sacamos el último valor que entro a la pila y vamos a meterlo en la variable aux
                aux = stack.quitar_pila()
                #Luego vamos a comparar el último valor de la pila con el caracter en el que va el ciclo
                #En el caso donde se regrese el valor de la función como falso, se regresara el índice porque hay un error
                if Comparador(aux ,texto[i]) == False:
                    return índice

    #Al final del ciclo no debe quedar ningún caracter en pila, si eso llega a pasar
    #Significa que todos los brackets estan cerrados correctamente
    if stack.pila_vacia() == True:
        return "Success"
    else:
        #En el caso donde aún quede algún elemento en la pila, se regresara la última posición de todo el texto
        #Esto porque el caracter que se quedo debe estar cerrado al final de la cadena de texto
        return índice

#Inicio

#Lo primero que se va a hacer es meter una cadena de texto a una variable de tipo string
texto = input('Inserte línea de código: \n')

#Validaremos la cantidad de carácteres antes de empezar a buscar los '(', '{', '['
if len(texto) < 1 or len(texto) > 10**5:
    print("Cantidad de texto no valida, mete una cantidad de letras que sea de 1 a 100,000 letras")
else:
    #En caso donde el texto cumpla con la validación, se mandará a la función Inspector
    print(Inspector(texto))

#Última modificación: 11/09/22
#Hecha por: Jorge Cerda, Daniel Vega, Luís García y Juan Manuel