#include <iostream>

// Задача из курса "Добрый, добрый ООП С++" от Сергея Балакирева

/*------------------------------------------
    Класс VectorIndexError
    для генерации исключения
------------------------------------------*/ 
class VectorIndexError: public std::exception
{    
protected:
    std::string msg;
public:
    VectorIndexError(const std::string& error) noexcept : msg(error)
        { }
    virtual ~VectorIndexError() { }

    const char * what() const noexcept override { return msg.data(); }
};
    
/*------------------------------------------
    Шаблон класса Vector
    для работы динамического массива
------------------------------------------*/ 
template <typename T>
class Vector
{
    size_t length{0};
    size_t volume{8};
    T* mass{nullptr};    
        
public:
    // конструкторы 
    Vector() : mass(new T[volume]) { }
    
    Vector(const Vector& v)
    {
        length = v.length;
        volume = v.volume;
        mass = new T[v.volume];
        
        for (int i = 0; i < v.length; i++)
        {
            mass[i] = v.mass[i];
        }
    }
    
    void push_back(T val) // добавление значения в конец
    {
        if (length < volume) 
        {
            mass[length] = val;
        }
        else
        {
            // создаем новый массив
            T* new_mass = new T[volume * 2];

            // копируем данные
            for (int i = 0; i < volume; i++)
              new_mass[i] = mass[i];                

            // удаляем старый массив
            delete[] mass;            
            mass = new_mass;

            // увеличиваем емкость
            volume *= 2;            
            mass[length] = val;            
        }   
        length++;
    }
 
    void push_front(T val) // добавление значения в начало
    {
        length++;
        if (length < volume) 
        {
            // сдвигаем данные      
            for (int i = length-1; i > 0; i--)
            {               
                mass[i] = mass[i-1];
            }       
            // вставляем первый элемент
            mass[0] = val; 
        }
        
        else 
        {
            // создаем новый массив
            T* new_mass = new T[volume * 2];

            // копируем данные
            for (int i = 0; i < volume; i++)
                new_mass[i+1] = mass[i]; 
            
            // вставляем первый элемент
            mass[0] = val;

            // удаляем старый массив
            delete[] mass;            
            mass = new_mass;

            // увеличиваем емкость
            volume*=2;                 
        }
    }

    void pop_back() // удаление последнего элемента
    {
        length--;
    }
    
    void pop_front() // удаление первого элемента
    {             
        // двигаем данные       
        for (int i = 0; i < length; i++)
              mass[i] = mass[i+1];
        
        length--;
    }

    T& operator[](size_t indx)
    {
        if(indx < 0 || indx > length) 
            throw VectorIndexError("Invalid element index.");
        
        return mass[indx];        
    }
   
    void insert(size_t indx, T val) // вставка элемента по индексу indx
    {
        if(indx < 0 || indx > length) 
            throw VectorIndexError("Invalid element index.");
        
        length++;
        if (length < volume) 
        {
            // двигаем часть данных
            for (int i = length-1; i > indx; i--)
            {               
                mass[i] = mass[i-1];
            } 
            
            // вставляем элемент
            mass[indx] = val;
        }
        
        else 
        {
            // создаем новый массив
            T* new_mass = new T[volume * 2];

            // копируем данные
            for (int i = 0; i < volume; i++)
                new_mass[i+1] = mass[i]; 
            
            // вставляем элемент
            mass[0] = val;

            // удаляем старый массив
            delete[] mass;            
            mass = new_mass;

            // увеличиваем емкость
            volume*=2;                 
        }
    }
    
    void remove(size_t indx)  // удаление элемента по индексу indx
    {   
        if(indx < 0 || indx > length) 
            throw VectorIndexError("Invalid element index.");
        
        for (int i = indx; i < length; i++)
              mass[i] = mass[i+1];
        
        length--;
    }

    size_t capacity() // возвращает поле volume
    {
        return volume;
    }
    
    size_t size() // возвращает поле length
    {
        return length;
    }
   
    void operator +=(const Vector& v) // добавление значений массива ar_d в конец массива ar_d2
    {
        volume += v.volume;
        
        T* new_mass = new T[volume];
        for (int i = 0; i < length; i++)
            new_mass[i] = v.mass[i];
        
        for (int i = 0; i < v.length; i++)
            new_mass[length + i] = v.mass[i];
        
        length += v.length;
        
        delete[] mass;
        mass = new_mass;  
    }
    
    Vector operator +(const Vector& v) // соединение двух массивов (сами массивы ar_d, ar_d2 не меняются)
    {
        Vector vect;
        vect += *this;
        vect += v;
        return vect;
    }
    
    bool empty()  // метод empty возвращает true, если массив пуст, и false иначе
    {
        return length == 0;
    }
    
    void clear() // удаление всех элементов из массива (параметр length равен 0)
    {
        while (length > 0) pop_front(); 
    }
};
