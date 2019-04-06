//
// Created by rudri on 3/29/2019.
//
#include <iostream>
#include "Vector.h"

namespace UTEC {
    void vector::push_back(const int &value) {
        // Completarlo
        _size += 1;
        int* temp_arr = new int[_size];
        if(_size == 1){
            _arr = new int[1];
            _arr[1] = value;
        }
        else if(_size > 1){
            for(int i = 0; i < _size-1; i++){
                temp_arr[i] = _arr[i];
                //std::cout << "temp_arr[" << i <<"] :" << temp_arr[i] << std::endl;
            }
            temp_arr[_size-1] = value;  //agregar ultimo elemento
            delete [] _arr;
            _arr = temp_arr;
        }
    }

    void vector::pop_back() {
        _size -= 1;
        //std::cout << "New array size: " << _size << std::endl;
        int* temp_arr_pop = new int[_size];
        for(int i=0;i < _size; i++){
            temp_arr_pop[i] = _arr[i];      // copiar todos los elementos menos el ultimo en temp_arr_pop
            //std::cout << temp_arr_pop[i] << " ";
        }
        delete [] _arr;         // libero la memoria
        _arr = temp_arr_pop;    // el puntero _arr apunta hacia el array dinamico reducido en 1
        //std::cout << std::endl;
    }

    vector::vector() : _arr{nullptr}, _size(0) {}
    vector::~vector() {
        delete [] _arr;
    }

    int vector::size() {return _size;}

    int vector::get_item(int i) {return _arr[i];}

    void vector::insert(int pos, const int &value) {
        _size += 1;
        //std::cout << "Inserta en Posicion: " << pos << " el valor: " << value << std::endl;

        int* temp_arr_ins = new int[_size];
        for(int i=0;i<_size;i++){
            if(i == pos){
                temp_arr_ins[i] = value;
            }
            else{
                temp_arr_ins[i] = _arr[i-1];
            }
        }
    }
}