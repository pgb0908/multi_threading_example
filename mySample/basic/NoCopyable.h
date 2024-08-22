//
// Created by bong on 24. 8. 22.
//

#ifndef MULTI_THREADING_NOCOPYABLE_H
#define MULTI_THREADING_NOCOPYABLE_H


class NoCopyable {
public:
    NoCopyable(const NoCopyable&) = delete;
    void operator=(const NoCopyable&) = delete;

protected:
    NoCopyable() = default;
    ~NoCopyable() = default;


};


#endif //MULTI_THREADING_NOCOPYABLE_H
