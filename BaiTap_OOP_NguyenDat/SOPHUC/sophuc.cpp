#include <iostream>
#include <cmath>
using namespace std;

class Sophuc {
 private:
    double m_phanthuc;
    double m_phanao;

 public:
    Sophuc() {}

    Sophuc(double phanthuc, double phanao) {
        m_phanthuc = phanthuc;
        m_phanao = phanao;
    }

    void setPhanthuc(double phanthuc) {
        m_phanthuc = phanthuc;
    }

    double getPhanthuc() {
        return m_phanthuc;
    }

    void setPhanao(double phanao) {
        m_phanao = phanao;
    }

    double getPhanao() {
        return m_phanao;
    }

    Sophuc operator +(Sophuc const &sophuc) {
        Sophuc add;
        add.m_phanthuc = m_phanthuc + sophuc.m_phanthuc;
        add.m_phanao = m_phanao + sophuc.m_phanao;
        return add;
    }

    Sophuc operator *(Sophuc const &sophuc) {
        Sophuc mul;
        mul.m_phanthuc = m_phanthuc*sophuc.m_phanthuc - m_phanao*sophuc.m_phanao;
        mul.m_phanao = m_phanthuc*sophuc.m_phanao + m_phanao*sophuc.m_phanthuc;
        return mul;
    }

    void show() {
        cout << m_phanthuc << " + " << m_phanao << ".i" << "\n"; 
    }
};

int main () {
    Sophuc s1(10, 5), s2(4, 7);
    Sophuc add = s1 + s2;
    Sophuc mul = s1 * s2;
    cout << "Tong 2 so phuc la: ";
    add.show();
    cout << "Tich 2 so phuc la: ";
    mul.show();
    return 0;
}
