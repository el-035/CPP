#pragma once

#ifndef ITER
#define ITER

#include<iostream>

template <typename T, typename P> void iter(T *arr, const size_t len, P f){
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}



#endif