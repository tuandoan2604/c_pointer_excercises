#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room {
 protected:
    string m_category;
    int m_price;

 public:
    Room(){}
    Room(string category, int price) {
        m_category = category;
        m_price = price;
    }

    string getCategory() {
        return m_category;
    }

    void setCategory(string category) {
        m_category = category;
    }

    int getPrice() {
        return m_price;
    }

    void setPrice(int price) {
        m_price = price;
    }
    ~Room(){}
};

#endif