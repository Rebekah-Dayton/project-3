//
// Created by Rebek on 11/1/2022.
//

#ifndef PROJECT_1_RELATION_H
#define PROJECT_1_RELATION_H
#include "Tuple.h"
#include "Header.h"
#include <set>

class Relation {
private:
    std::string name;
    Header attributes;
    std::set<Tuple> tuples;
public:
    Relation();
    Relation(std::string name, Header header);
    ~Relation() = default;

    void SetHeader(Header header) {attributes = header;}
    void SetName(std::string id) {name = id;}
    void AddTuple(Tuple to_add);

    unsigned int GetTupleSize() {return tuples.size();}
    std::string GetName() {return name;}
    std::string GetHeader() {return attributes.ToString();}
    std::string To_String();

    Relation* Select(std::string attribute, std::string selector);
    Relation* SelectTwo(std::string attribute1, std::string attribute2);
    Relation* Project(std::vector<std::string> headers);
    Relation* Rename(std::string attribute, std::string newAttribute);

    Relation* Select(int index, std::string selector);
    Relation* SelectTwo(int index1, int index2);
    Relation* Project(std::vector<unsigned int> indices);
    Relation* Rename(int index, std::string newAttribute);
};


#endif //PROJECT_1_RELATION_H
