#ifndef ABSTRACTTETRISDB_H
#define ABSTRACTTETRISDB_H

template<typename T>
class AbstractTetrisDb;

#include <string>
#include <vector>

template<typename T>
class AbstractTetrisDb
{
public:
    std::vector<T> get_everything();
    bool get(T& obj);
    bool get_user(T& obj);
    bool add(T& obj);
    bool remove(int _id);
};

#endif // ABSTRACTTETRISDB_H
