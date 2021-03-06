#ifndef shared_ptr_hpp
#define shared_ptr_hpp

#include <cassert>

namespace ns_memory {

    template <typename T>
    class shared_ptr final {
        using meta_t = struct {
            int count;
        };
        meta_t *meta_;
    public:
        explicit shared_ptr(T *object);
        ~shared_ptr();

        shared_ptr(const shared_ptr& pObject);
        //shared_ptr(shared_ptr&& pObject)                    = delete;
        shared_ptr& operator=(const shared_ptr& pObject)    = delete;
        shared_ptr& operator=(shared_ptr&& pObject)         = delete;
    private:
        T *object_;
    };

    template<typename T>
    shared_ptr<T>::shared_ptr(T *object): object_(object) {
        meta_ = new meta_t {.count = 1};
    }

    template<typename T>
    shared_ptr<T>::~shared_ptr() {
        //if pObject.lock {
            if (--meta_->count == 0) {
                //pObject.unlock
                delete object_;
                delete meta_;
                return;
            }
            else {
                //pObject.unlock
            }
        //}
    }

    template<typename T>
    shared_ptr<T>::shared_ptr(const shared_ptr& pObject) {
        //if pObject.lock {
            meta_ = pObject.meta_;
            ++meta_->count;
            object_ = pObject.object_;
            //pObject.unlock
        //}
    }
}

#endif
