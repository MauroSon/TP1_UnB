#ifndef CONTROLADORAS_HPP_INCLUDED
#define CONTROLADORAS_HPP_INCLUDED

using namespace std;

class CntrIEntidadesServico:public IEntidadesServico {
private:
    ILNEntidadesServico *cntrLNEntidadesServico;

public:
    bool celo();

    void setCntrLNEntidadesServico(ILNEntidadesServico*);
};

void inline CntrIUEntidadesServico::setCntrLNEntidadesServico(ILNEntidadesServico *cntrLNEntidadesServico){
    this->cntrLNEntidadesServico = cntrLNEntidadesServico;
};

#endif // CONTROLADORAS_HPP_INCLUDED
