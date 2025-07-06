#include "rk4.h"
#include <cassert>

template<class T>
RungeKutta4<T>::RungeKutta4(DataStruct<T> &_Un):
Un(_Un)
{
  nSteps = 4;
  currentStep = 0;

  coeffsA = new T[4];
  coeffsB = new T[4];
  coeffsA[0] = 0.;
  coeffsA[1] = 0.5;
  coeffsA[2] = 0.5;
  coeffsA[3] = 1.;
  coeffsB[0] = 1.;
  coeffsB[1] = 2.;
  coeffsB[2] = 2.;
  coeffsB[3] = 1.;

  fi_cur.setSize(Un.getSize());
  f_accum.setSize(Un.getSize());
  Ui.setSize(Un.getSize());
};

template<class T>
RungeKutta4<T>::~RungeKutta4()
{
  delete[] coeffsA;
  delete[] coeffsB;
};

template<class T>
int RungeKutta4<T>::getNumSteps()
{
  return nSteps;
};

template<class T>
void RungeKutta4<T>::initRK()
{
  currentStep = 0;
  T *dataFaccum = f_accum.getData();
  for (int n = 0; n < f_accum.getSize(); n++)
  {
    dataFaccum[n] = 0.;
  }
};

template<class T>
void RungeKutta4<T>::stepUi(T dt)
{
  assert(currentStep < nSteps);

  T *dataUi = Ui.getData();
  const T *dataU = Un.getData();
  const T *dataFi = fi_cur.getData();

  if (currentStep == 0)
  {
    for (int n = 0; n < Ui.getSize(); n++)
    {
      dataUi[n] = dataU[n];
    }
  }
  else
  {
    for (int n = 0; n < Ui.getSize(); n++)
    {
      dataUi[n] = dataU[n] + coeffsA[currentStep] * dt * dataFi[n];
    }
  }

  // Acumular término ponderado en f_accum
  T *dataFaccum = f_accum.getData();
  T b = coeffsB[currentStep];
  for (int n = 0; n < Ui.getSize(); n++)
  {
    dataFaccum[n] += b * dataFi[n];
  }

  currentStep++;
};

template<class T>
void RungeKutta4<T>::finalizeRK(const T dt)
{
  T *dataUn = Un.getData();
  const T *dataFaccum = f_accum.getData();
  const T oneDiv6 = 1. / 6.;

  for (int n = 0; n < Un.getSize(); n++)
  {
    dataUn[n] += dt * oneDiv6 * dataFaccum[n];
  }
};

template<class T>
void RungeKutta4<T>::setFi(DataStruct<T> &_F)
{
  T *dataFi = fi_cur.getData();
  const T *dataF = _F.getData();

  for (int n = 0; n < Ui.getSize(); n++)
  {
    dataFi[n] = dataF[n];
  }
};

template<class T>
DataStruct<T> * RungeKutta4<T>::currentU()
{
  return &Ui;
};



template class RungeKutta4<float>;
template class RungeKutta4<double>;