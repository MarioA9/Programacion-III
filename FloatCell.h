#ifndef TEMA1_FLOATCELL_H
#define TEMA1_FLOATCELL_H

class FloatCell {
public:
    //implicit constructor
    explicit FloatCell(float newValue = 0);

    //explicit copy constructor
    FloatCell(const FloatCell &rhs);

    //explicit constructor by reference
    FloatCell(FloatCell &&rhs) noexcept;

    //Destroyer, activated when free is used
    ~FloatCell() = default;

    //Assignment by copy, for rvalues
    FloatCell &operator = (const FloatCell &rhs);
    FloatCell &operator = (FloatCell &&rhs) noexcept;

    //It tells you what type of data you are going to work with in this case "float"
    //Because it can only work with data of its own class
    FloatCell &operator = (float rhs);

    //Function to see what value is assigned
    float getValue() const;

    //function to assign value
    void setValue(float newValue);

private:
    //Variable that we use to
    float storedValue;
};


#endif //TEMA1_FLOATCELL_H