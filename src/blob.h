#ifndef __BLOB_H__
#define __BLOB_H__

#include <memory>
#include <vector>
#include <string>

template <typename T> class BlobPtr;
template<typename> class Blob;
template<typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob
{
    friend class BlobPtr<T>;
  public:
    Blob();
    Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)) {}
    ~Blob() {}

    size_t size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }

    T& back();
    T& operator[](size_t i);

  private:
    std::shared_ptr<std::vector<T>> data;

    void check(size_t i, const std::string msg);
};

template<typename T> T& Blob<T>::back()
{
    check(0, "back on empty blob");
    return data->back();
}

template<typename T> T& Blob<T>::operator[](size_t i)
{
    check(i, "back on empty blob");
    return data->back();
}

template <typename T>
void Blob<T>::check(size_t i, const std::string msg)
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template<typename T>
bool operator==(const Blob<T>& a, const Blob<T>& b)
{
    return a.data == b.data;
}

#endif