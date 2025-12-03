#include <iostream>
// Ромбовидное наследование

/*------------------------------------------
              Класс Object
------------------------------------------*/
class Object {
protected:
    int x{0}, y{0};
    int speed {0};
    
public:
    // конструктор
    Object(int x = 0, int y = 0, int speed = 0) : 
        x(x), 
        y(y), 
        speed(speed)
        { }
    
    // виртуальный деструктор
    virtual ~Object() { }
    
    // сеттер
    void set_speed(int speed) { this->speed = speed; }
    
    // геттеры
    int get_speed() const { return speed; }
    int get_x() const { return x; }
    int get_y() const { return y; }
};

/*------------------------------------------
              Класс ObjectFly
------------------------------------------*/
class ObjectFly :  virtual public Object
{
protected:
    int z {0}; 
    double angle {0.0}; 

public:
    int get_z() const { return z; } 
    double get_angle() const { return angle; }
    void set_angle(double angle) { this->angle = angle; }

    ObjectFly() = default;
    ObjectFly(int z) : z(z) { }
    ObjectFly(int z, double angle) : z(z), angle(angle) { } 
    
    virtual ~ObjectFly() {}
};

/*------------------------------------------
              Класс ObjectOperators
------------------------------------------*/
class ObjectOperators : virtual public Object 
{
public:
    void operator+=(int delta) { speed += delta; } 
    void operator-=(int delta) { speed -= delta; } 

    ObjectOperators() = default;
    ObjectOperators(int x, int y) : Object (x, y) { }
    ObjectOperators(int x, int y, int speed) : Object (x, y, speed) { }

    virtual ~ObjectOperators() {}
};

/*------------------------------------------
              Класс Plane
------------------------------------------*/
class Plane : public ObjectOperators, public ObjectFly
{
public:
    Plane() = default;
    Plane(int x, int y, int z) : Object(x,y), ObjectFly(z) { }
};


int main(void)
{   
    Plane  pl(20, 43, 100);
    pl.set_speed(10);
    pl += 5; 
        
    return 0;
}
