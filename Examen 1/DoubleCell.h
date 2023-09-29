#ifndef DOUBLE_CELL_H
#define DOUBLE_CELL_H

class DoubleCell {
public:
    //primero declaramos los constructores en el .h
    // Default constructor
    DoubleCell();

    // Constructor with value
    explicit DoubleCell(double value); //aqui declaramos doublecell con un valor preterminado

    // Copy constructor
    DoubleCell(const DoubleCell& other);

    //Reference constructor
    DoubleCell(DoubleCell&& other) noexcept;

    //empezamos a hacer el destructor y los operadores
    // Destructor
    ~DoubleCell();

    // Assignment operator by copy
    DoubleCell& operator=(const DoubleCell& other);

    // Assignment operator by reference
    DoubleCell& operator=(DoubleCell&& other) noexcept;

    // Assignment operator for double
    DoubleCell& operator=(double value);

    // Arithmetic operators
    DoubleCell operator +(const DoubleCell& other) const;
    DoubleCell operator +(const double other) const;
    DoubleCell operator -(const DoubleCell& other) const;
    DoubleCell operator -(const double other) const;
    DoubleCell operator *(const DoubleCell& other) const;
    DoubleCell operator *(const double other) const;
    DoubleCell operator /(const DoubleCell& other) const;
    DoubleCell operator /(const double other) const;

    // Setters
    void SetValue(double value);

    // Getters

    double GetValue() const;


protected:
    double Storedvalue;
};

#endif  // DOUBLE_CELL_H