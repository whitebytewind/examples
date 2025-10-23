#include <iostream>

class PointND 
{
    short* coords {nullptr}; 
    size_t dims {0}; 
    
    short error_value = 0;
public:    
    // constructors
    PointND() = default;
    PointND(short* cds, size_t len);
    
    // destructors
    ~PointND() { delete[] coords; }

    // getter
    size_t get_dims() const { return dims; }
    
    // operators
    short& operator[](int indx);
    void operator++();     // для префиксной формы
    void operator++(int);  // для постфиксной формы    
    void operator--();     // для префиксной формы    
    void operator--(int);  // для постфиксной формы
    
    void operator= (const PointND&);
    void operator+=(const PointND&); 
    void operator-=(const PointND&); 
};

PointND::PointND(short* cds, size_t len) : dims(len)
{
   coords = new short[dims];
   for(size_t i = 0; i < dims; ++i)
       coords[i] = cds[i];
}

short& PointND::operator[](int ind)
{
    if(ind < 0 || ind >= dims) 
        return error_value;    
    return coords[ind];
}

void PointND::operator++()
{
   for(size_t i = 0; i < dims; ++i)
   ++coords[i];
}

void PointND::operator--()
{
   for(size_t i = 0; i < dims; ++i)
   --coords[i];
}

void PointND::operator++(int)
{
   for(size_t i = 0; i < dims; ++i)
   coords[i]++;  
}

void PointND::operator--(int)
{
   for(size_t i = 0; i < dims; ++i)
   coords[i]--;   
}    

void PointND::operator= (const PointND& arg)
{
    delete[] coords;
    
    dims = arg.dims;
    coords = new short[dims];
    
    for(size_t i = 0; i < dims; ++i)
       coords[i] = arg.coords[i];
}

void PointND::operator+=(const PointND& arg) 
{
    if (arg.dims != dims) return;
    
    for(size_t i = 0; i < dims; ++i)
       coords[i] += arg.coords[i];
}

void PointND::operator-=(const PointND& arg)
{
    if (arg.dims != dims) return;
    
    for(size_t i = 0; i < dims; ++i)
       coords[i] -= arg.coords[i];
}    
