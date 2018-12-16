#include "blob.h"

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>())
{
}

// template <typename T>
// Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il))
// {
// }

// template <typename T>
// Blob<T>::~Blob()
// {
// }

