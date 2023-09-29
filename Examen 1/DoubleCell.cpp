#include "DoubleCell.h"
#include <stdexcept>
//aqui volvemos a hacer los constructores
// Default constructor
DoubleCell::DoubleCell()
        :Storedvalue(0.0){}

// Constructor with value
DoubleCell::DoubleCell(double value)
        : Storedvalue(value){}

// Copy constructor
DoubleCell::DoubleCell(const DoubleCell& other)
        : Storedvalue(other.Storedvalue){}

//Reference  constructor
DoubleCell::DoubleCell(DoubleCell&& other) noexcept
        : Storedvalue(other.Storedvalue)
{
    other.Storedvalue = 0;
}

//tambien establecemos lo que deben hacer el destructor y los operadores
// Destructor
DoubleCell:: ~DoubleCell() //aqui asignamos el valor del Storedvalue a 0
{
    Storedvalue = 0;
}

// Assignment operator by copy
DoubleCell& DoubleCell::operator=(const DoubleCell& other){ //copiamos el valor de otro a Storedvalue
    if (this != &other){
        Storedvalue = other.Storedvalue;
    }
    return *this;
}

// Assignment operator by reference
DoubleCell& DoubleCell::operator=(DoubleCell&& other) noexcept //aqui hacemos la refecia a otro storedvalue
{
    if (this != &other)
    {
        Storedvalue = other.Storedvalue;
        other.Storedvalue = 0;
    }
    return *this;
}

// Assignment operator for double
DoubleCell& DoubleCell::operator=(double value){ //asignamos el valor a Storedvalue
    Storedvalue = value;
    return *this;
}
//usamos estos operadores para hacer nuestras operaciones
// Arithmetic operators
//DoubleCell adding
DoubleCell DoubleCell::operator +(const DoubleCell& other) const{ //usamos la referencia del DoubleCell para sumar el valor que esta almacenado
    return DoubleCell(Storedvalue + other.Storedvalue);
}
//primitive double adding
DoubleCell DoubleCell:: operator +(double value) const //usamos el valor Double para sumar directamente a Storedvalue
{
    return DoubleCell(Storedvalue + value);
}

//DoubleCell substracting
DoubleCell DoubleCell::operator -(const DoubleCell& other) const //usamos la referencia del DoubleCell para restar el valor que esta almacenado
{
    return DoubleCell(Storedvalue - other.Storedvalue);
}

//primitive double substracting
DoubleCell DoubleCell::operator -(double value) const{ //usamos el valor Double para restar directamenta a Storedvalue
    return DoubleCell(Storedvalue - value);
}

//DoubleCell multiplication
DoubleCell DoubleCell::operator *(const DoubleCell& other) const{ //usamos la referencia del DoubleCell para multiplicar el valor que esta almacenado
    return DoubleCell(Storedvalue * other.Storedvalue);
}
//primitive double multiplication
DoubleCell DoubleCell::operator *(double value) const //usamos el valor Double para multiplicar directamente a Storedvalue
{
    return DoubleCell(Storedvalue * value);
}

//DoubleCell division
DoubleCell DoubleCell::operator /(const DoubleCell& other) const{ //usamos la referencia del DoubleCell para dividir el valor que esta almacenado
    if(other.Storedvalue == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / other.Storedvalue);
}

//Primitive souble division
DoubleCell DoubleCell::operator /(double value) const{ //usamos el valor Double para dividir directamenta a Storedvalue
    if(value == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / value);
}

// Setters
void DoubleCell::SetValue(double value){
    Storedvalue = value;
}

// Getters
double DoubleCell::GetValue() const
{
    return Storedvalue;
}