//
// Created by Rebek on 11/1/2022.
//

#include "Relation.h"

Relation::Relation(std::string name, Header header){
    this->name = name;
    attributes = header;
}

void Relation::AddTuple(Tuple to_add) {
    tuples.insert(to_add);
}

std::string Relation::To_String() {
    std::string results = "  ";
    for (Tuple t : tuples) {
        for (unsigned int i = 0; i < attributes.GetSize(); i++) {
            results += attributes.GetAttribute(i) + "=" + t.GetValue(i);
            if (i != attributes.GetSize() - 1) {
                results += ", ";
            }
            if (i == attributes.GetSize() - 1) {
                results += "\n  ";
            }
        }
    }
    results.pop_back();
    results.pop_back();
    return results;
}

Relation *Relation::Select(std::string attribute, std::string selector) {
    Relation* select = new Relation(name, attributes);

    unsigned int index = attributes.FindAttribute(attribute);
    for (Tuple t : tuples) {
        if (t.GetValue(index) == selector) {
            select->AddTuple(t);
        }
    }
    return select;
}

Relation *Relation::SelectTwo(std::string attribute1, std::string attribute2) {
    Relation* select = new Relation(name, attributes);
    unsigned int index1 = attributes.FindAttribute(attribute1);
    unsigned int index2 = attributes.FindAttribute(attribute2);
    for (Tuple t : tuples) {
        if (t.GetValue(index1) == t.GetValue(index2)) {
            select->AddTuple(t);
        }
    }
    return select;
}

Relation *Relation::Project(std::vector<std::string> headers) {
    std::vector<int> indices;
    for (unsigned int i = 0; i < headers.size(); i++) {
        indices.push_back(attributes.FindAttribute(headers.at(i)));
    }
    Relation* project = new Relation();
    project->SetName(name);
    Header header;
    for (unsigned int i = 0; i < indices.size(); i++) {
        header.AddAttribute(attributes.GetAttribute(indices.at(i)));
    }
    project->SetHeader(header);
    for (Tuple t : tuples) {
        Tuple newTuple;
        for (unsigned int i = 0; i < indices.size(); i++) {
            newTuple.AddValue(t.GetValue(indices.at(i)));
        }
        project->AddTuple(newTuple);
    }

    return project;
}

Relation *Relation::Rename(std::string attribute, std::string newAttribute) {
    Relation* rename = new Relation();
    rename->SetName(name);
    Header header;
    unsigned int index = attributes.FindAttribute(attribute);
    for (unsigned int i = 0; i < attributes.GetSize(); i++) {
        if (i == index) {
            header.AddAttribute(newAttribute);
        }
        else {
            header.AddAttribute((attributes.GetAttribute(i)));
        }
    }
    rename->SetHeader(header);

    for (Tuple t : tuples) {
        rename->AddTuple(t);
    }
    return rename;
}

Relation::Relation() {

}

Relation *Relation::Select(int index, std::string selector) {
    Relation* select = new Relation(name, attributes);

    for (Tuple t : tuples) {
        if (t.GetValue(index) == selector) {
            select->AddTuple(t);
        }
    }
    return select;
}

Relation *Relation::SelectTwo(int index1, int index2) {
    Relation* select = new Relation(name, attributes);

    for (Tuple t : tuples) {
        if (t.GetValue(index1) == t.GetValue(index2)) {
            select->AddTuple(t);
        }
    }
    return select;
}

Relation *Relation::Project(std::vector<unsigned int> indices) {
    Relation *project = new Relation();
    project->SetName(name);
    Header header;
    for (unsigned int i = 0; i < indices.size(); i++) {
        header.AddAttribute(attributes.GetAttribute(indices.at(i)));
    }
    project->SetHeader(header);
    for (Tuple t: tuples) {
        Tuple newTuple;
        for (unsigned int i = 0; i < indices.size(); i++) {
            newTuple.AddValue(t.GetValue(indices.at(i)));
        }
        project->AddTuple(newTuple);
    }

    return project;
}

Relation *Relation::Rename(int index, std::string newAttribute) {
    Relation* rename = new Relation();
    rename->SetName(name);
    Header header;
    for (unsigned int i = 0; i < attributes.GetSize(); i++) {
        if (i == index) {
            header.AddAttribute(newAttribute);
        }
        else {
            header.AddAttribute((attributes.GetAttribute(i)));
        }
    }
    rename->SetHeader(header);

    for (Tuple t : tuples) {
        rename->AddTuple(t);
    }
    return rename;
}

