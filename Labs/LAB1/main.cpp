#include <iostream>
#include "message/Message.h"
#include "output_operator.h"
#include "durationLogger/DurationLogger.h"
#include "messageStore/MessageStore.h"


int main() {
    int id = 0;
    Message m1(1000000, id++);
    Message m2(1000000, id++);
    Message m3(1000000, id++);
    Message m4(1000000, id++);
    Message m5(1000000, id++);
    Message m6(1000000, id++);
    Message m7(1000000, id++);
    Message m8(1000000, id++);
    Message m9(1000000, id++);
    Message m10(1000000, id++);
    Message m11(10, id++);
    // DurationLogger a = DurationLogger("Copy Costructor");

    MessageStore m_store = MessageStore(10);
    m_store.add(m11);
    m_store.add(m1);
    m_store.add(m2);
    m_store.add(m3);
    m_store.add(m4);
    m_store.add(m5);
    m_store.add(m6);
    m_store.add(m7);
    m_store.add(m8);
    m_store.add(m9);
    m_store.add(m10);
    m_store.remove(m3.getId());
    m_store.remove(m6.getId());
    m_store.compact();

    auto o = m_store.stats();
    auto o1 = m_store.get(7);


    if(o1 != std::nullopt)
        std::cout << std::get<0>(o) << std::endl << std::get<1>(o) << std::endl << o1->getId() << ":" << o1->getData() << std::endl ;

    return 0;
}
