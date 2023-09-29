## Examen primer parcial

### Teoria

**i. ¿Qué es un Rvalor y un Lvalor?** R: Rvalor es un valor que no tiene espacio de memoria, por lo que es el valor que se encuentra en la derecha y el Lvalor es un valor que sí tiene un espacio de memoria, po lo que es el valor que se encuentra a la izquierda.

**ii. ¿Porqué es necesario que una clase tenga constructores y operadores por copia y por referencia?** R: los constructores ayudan a inicializar el objeto y establecer sus valores preterminados, y los operadores ayudan a darle la clase lo que puede hacer.

**iii. ¿Qué función desarrollan los :: en la implementación de la clase?** R: indica que el Lvalor está dentro de la clase.

**iv. ¿Cómo se le denomina a cuando una clase posee un operador puede tener múltiples implementaciones dependiendo de los argumentos que este reciba?** R: Sobrecarga.

**v. ¿Cúal es la funcion del archivo .h ?** R: Sirve para asignar variables y declarar los parametros de una clase.


### Complejidad

``` c++
#include <iostream>
int algoritmo1(int n) {//declaramos la funcion
int resultado = 0;//damos valor a la variable, en este caso el entero
for (int i = 0; i < n; i++) {
resultado += i; // Operación simple O(1)
}
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
resultado += i * j; // Operación simple O(1)
}
}
return resultado;
}
int main() {
int n;
std::cout << "Ingrese el valor de n: ";
std::cin >> n;
Parte 2

Complejidad Temporal

int resultado = algoritmo1(n);
std::cout << "Resultado: " << resultado << std::endl;
return 0;
}
```

La complejidad de este codigo es cuadratica $0(n^2)$, debido a que hay un for dentro de otro for. Hay tres for, pero uno de ellos no interactua con los demas.