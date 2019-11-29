#pragma once

#include <list>


namespace minimum {

    template <typename object_t, typename info_t, typename _Dp = void>
    struct __object {

    };

    template <typename object_t>
    struct pool {
    private:
    void delete_object() {
    
    }
    std::list<std::unique_ptr<object_t, decltype(delete_object)>> _pool;
    };
}

