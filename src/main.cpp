#include <iostream>
#include "blob.h"
#include "blobptr.h"
#include "foo.h"
#include "numbers.h"
#include "debugdelete.h"
#include "util.h"
#include "variadictemplate.h"

void blobTest()
{
    Blob<int> blob = {0, 1, 2, 3, 4, 5};
    blob.push_back(6);
    auto i = blob.back();
    std::cout << "i = " << i << std::endl;

    BlobPtr<int> blogPtr(blob, 5);
    BlobPtr<int> blogPtrold = blogPtr++;
    auto j = *(blogPtr);

    std::cout << "j = " << j << std::endl;
    std::cout << "before increment: " << *blogPtrold << std::endl;
}

void fooTest()
{
    Foo<int> foo1, foo2;
    std::cout << "foo1.count: " << foo1.count() << std::endl;
    std::cout << "foo2.count: " << foo1.count() << std::endl;
    std::cout << "Foo<int>.count: " << Foo<int>::count() << std::endl;
    foo1.incre();
    std::cout << "after incre\n";
    std::cout << "foo1.count: " << foo1.count() << std::endl;
    std::cout << "foo2.count: " << foo1.count() << std::endl;
    std::cout << "Foo<int>.count: " << Foo<int>::count() << std::endl;
}

void testNumbers()
{
    Numbers<double> high_precision;
    high_precision.value(2.2);
    std::cout << "high_precision " << high_precision.value() << std::endl;

    Numbers<> midle_precision;
    midle_precision.value(88);
    std::cout << "midle_precision " << midle_precision.value() << std::endl;
}
void deleteTest()
{
    std::cout << "-------deleteTest--------- " << std::endl;
    double *p = new double;
    DebugDelete dd;
    dd(p);
    if (p == nullptr)
        std::cout << "p is deleted" << std::endl;

    int *ip = new int(99);
    DebugDelete()(ip);
}

void utilTest()
{
    std::cout << "-------utilTest--------- " << std::endl;
    int a = 1;
    long b = 1000;
    auto s = sum<long>(a, b);
    std::cout << "sum: " << s << std::endl;

    std::vector<int> v1 = {1, 2, 3, 4, 5, 6};

    auto &i = func(v1.begin(), v1.end());
    std::cout << "i: " << i << std::endl;

    int j = 7;
    f3(i);

    std::cout << "j = " << j << std::endl;
}

void varidcTest()
{
    std::cout << "-------varidcTest--------- " << std::endl;
    int a = 10;
    std::string b = "hello";
    long c = 1999;
    double d = 1.90099;

    myprint(std::cout, a, b, c, d);
}

int main(int argc, char const *argv[])
{
    /* code */
    blobTest();
    fooTest();
    testNumbers();
    utilTest();
    deleteTest();
    varidcTest();

    return 0;
}
