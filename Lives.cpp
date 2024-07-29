#pragma once

class Lives {
protected:
    int count;

public:
    Lives(int count = 3);
    ~Lives();

    int getCount() const;
    void setCount(int newCount);
    void decrement();
};
