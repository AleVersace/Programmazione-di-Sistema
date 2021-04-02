//
// Created by Ale on 28/03/2021.
//

#ifndef LAB1_OUTPUT_OPERATOR_H
#define LAB1_OUTPUT_OPERATOR_H

std::ostream& operator << (std::ostream &out, const Message &m) {
    if(m.getData() != nullptr) {
        std::string s(m.getData());
        out << "[id:" << m.getId() << "]" << "[ size :" << m.getSize()
            << "]" << "[ data :" << s.substr(0, 20) << "]";
    } else
        return out << "Object is empty!\n";
    return out;
}


#endif //LAB1_OUTPUT_OPERATOR_H
