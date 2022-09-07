#include "Thisinh.h"
#include "ThisinhA.h"
#include "ThisinhB.h"
#include "ThisinhC.h"
#include <memory>
#include <vector>

class Manager {
 private:
    vector<pair<unique_ptr <Thisinh>, string>> dsts;
 public:
    Manager() {}
    void addThisinh(unique_ptr<Thisinh> thisinh, string khoithi) {
        pair<unique_ptr<Thisinh>, string> pair = make_pair(move(thisinh), khoithi);
        dsts.push_back(move(pair));
    }
    
    void showInfor() {
        for(int i = 0; i < dsts.size(); i++) {
            cout << "Thi sinh du thi thu " << i + 1 << "\n";
            cout << dsts[i].first->toString() << endl;
        }
    }

    void searchbyID(int SBD) {
        for (int i = 0; i < dsts.size(); i++) {
            if(dsts[i].first->getSBD() == SBD) {
                cout << dsts[i].first->toString() << endl;
            } 
        }   
    }
};