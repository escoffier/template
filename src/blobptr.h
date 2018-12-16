#ifndef __BLOBPTR_H__
#define __BLOBPTR_H__
#include <memory>
#include <vector>
#include "blob.h"

template <typename T>
class BlobPtr
{
  public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &b, size_t c = 0) : wptr(b.data), curr(c) {}
    T &operator*() const
    {
        auto p = check(curr, "derefence");
        return (*p)[curr];
    }
    BlobPtr& operator++() 
    { 
        ++curr; 
        return *this;
    }

    BlobPtr operator++(int);

  private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    if (auto sptr = wptr.lock())
    {
        if (i >= sptr->size())
        {
            throw std::out_of_range(msg);
        }
        return sptr;
    }

    return nullptr;
}

#endif