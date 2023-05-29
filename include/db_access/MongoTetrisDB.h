#ifndef MONGOTETRISDB_H
#define MONGOTETRISDB_H

template<typename T>
class MongoTetrisDb;

#include "db_access/AbstractTetrisDB.h"
#include <Serializer/Serializer.h>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/database.hpp>
#include <mongocxx/collection.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/types.hpp>

using bsoncxx::types::b_oid;
using bsoncxx::document::value;
using bsoncxx::builder::basic::kvp;
using bsoncxx::document::view_or_value;
using bsoncxx::builder::basic::make_document;

mongocxx::instance instance{};

static const std::string WILDCARD_PATERN = "$**";
const std::string ID_FIELD_NAME = "_id";
const std::string USERNAME_FIELD_NAME = "username";

template<typename T>
class MongoTetrisDb : AbstractTetrisDb<T>
{
    mongocxx::client client;
    mongocxx::collection collection;
    value serialize(const T& object);
    T deserialize(const value& document);

public:
    MongoTetrisDb(const std::string& uri_string, const std::string& database_name, const std::string& collection_name);
    std::vector<T> get_everything();
    bool get(T& obj);
    bool get_user(T& obj);
    bool add(T& obj);
    bool remove(int _id);
};

template<typename T>
MongoTetrisDb<T>::MongoTetrisDb(const std::string& uri_string, const std::string& database_name, const std::string& collection_name) :
    client(mongocxx::uri(uri_string)), collection(client[database_name][collection_name])
{
    view_or_value options = make_document(kvp("wildcardProjection", make_document(kvp(USERNAME_FIELD_NAME, 1))));
    view_or_value index = make_document(kvp(WILDCARD_PATERN, 1));
    collection.create_index(index, options);
}

template<typename T>
value MongoTetrisDb<T>::serialize(const T& object)
{
    return bsoncxx::from_json(Serializer<T>::serialize(object)->toJsonString());
}

template<typename T>
T MongoTetrisDb<T>::deserialize(const value& document)
{
    int index = 0;
    return Serializer<T>::deserialize(BaseType::fromJsonString(bsoncxx::to_json(document), index));
}

template<typename T>
std::vector<T> MongoTetrisDb<T>::get_everything()
{
    std::vector<T> result;
    auto docs = collection.find({});
    for (const auto& doc : docs)
        result.push_back(deserialize(doc));
    return result;
}

template<typename T>
bool MongoTetrisDb<T>::get(T& obj)
{
    auto mayDoc = collection.find_one(make_document(kvp(ID_FIELD_NAME, obj._id)));
    if (!mayDoc)
        return false;
    obj = deserialize(mayDoc.value());
    return true;
}

template<typename T>
bool MongoTetrisDb<T>::get_user(T& obj)
{
    auto mayDoc = collection.find_one(make_document(kvp(USERNAME_FIELD_NAME, obj.username)));
    if (!mayDoc)
        return false;
    obj = deserialize(mayDoc.value());
    return true;
}

template<typename T>
bool MongoTetrisDb<T>::add(T& obj)
{
    if (get_user(obj))
        return false;
    obj._id = b_oid().value.to_string();
    return static_cast<bool>(collection.insert_one(serialize(obj)));
}

template<typename T>
bool MongoTetrisDb<T>::remove(int _id)
{
    return collection.delete_one(make_document(kvp(ID_FIELD_NAME, _id)))->deleted_count();
}

#endif // MONGOTETRISDB_H
