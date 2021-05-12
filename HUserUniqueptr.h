#pragma once


template <typename T, typename... Rest>
class CUniqueptr {
private:
    T* ppointer;
public:
    CUniqueptr() {};
    CUniqueptr(T* pointer)
        : ppointer(pointer)
    {}

   
    CUniqueptr(CUniqueptr&& robject)
        : ppointer{ robject.ppointer } {
        robject.ppointer = nullptr;
    }

   template <class... Args>
    CUniqueptr(Args*... args)
        : ppointer(args...)
    {}

    //CUniqueptr(const CUniqueptr&) = delete;
    CUniqueptr(const CUniqueptr& a) : ppointer(new T(*a.ppointer)) {}

    template <class... Args>
    CUniqueptr& operator = (T& s)
    {
        
    }
   
   

    CUniqueptr& operator=(CUniqueptr&& robject) {
        if (ppointer)
            delete ppointer;
        ppointer = robject.ppointer;
        robject.ppointer = nullptr;
        return *this;
    }

    ~CUniqueptr() {
        if (ppointer)
            delete ppointer;
    }

    T* Getptr() { return ppointer; }
};
