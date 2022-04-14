//
// Created by Jonathan on 14.04.2022.
//

#ifndef ARRAY_ARRAY_HPP
#define ARRAY_ARRAY_HPP




template<typename T> class Array {
public:
    Array(const unsigned short size){
        this->size = size;
        data =
    };
    Array(const Array& o){

    };

    ~Array(){

    };

    Array& operator=(const Array& o){

    };

    T& operator[](const unsigned short index){

    };

    const short int size() const{
        return size;
    };

private:
    unsigned short size;
    T data[];
};


#endif //ARRAY_ARRAY_HPP
