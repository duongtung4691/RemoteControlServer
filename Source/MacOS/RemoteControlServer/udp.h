#ifndef UDP_H
#define UDP_H

class UDP
{
public:
    static UDP *Instance();

    void stopListener();

private:
    UDP();
    static UDP *instance;
};

#endif // UDP_H
