#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

#include "coral.h"

int main(){
  CWaveFunction *wf=new CWaveFunction_pp_schrod("parameters/wfparameters.dat");
  double q,r,ctheta;
  int iq,Nq=wf->GetNQMAX();
  double *cf=new double[Nq];
  int imc,NMC=1000;
  int ir,Nr=100;
  double sigma_r,delr=0.5;
  double *sf=new double[Nr];
  char dummy[100];
  FILE *fptr=fopen("sf.dat","r");
  for(ir=0;ir<Nr;ir++){
    fscanf(fptr,"%lf %lf",&r,&sf[ir]);
    fgets(dummy,100,fptr);
  }
  fclose(fptr);
  CRandom *randy= new CRandom(-1234);




  printf("Nq=%d, Nr=%d, delr=%g\n",Nq,Nr,delr);
  double normcheck=0.0;
  for(ir=0;ir<Nr;ir++){
    r=(0.5+ir)*delr;
    normcheck+=4.0*PI*r*r*delr*sf[ir];
    //printf("r=%6.3f, sf=%g\n",r,sf[ir]);
  } 
  printf("normcheck=%g\n",normcheck);

  for(iq=0;iq<Nq;iq++){
    q=wf->GetQ(iq);
    cf[iq]=0.0;
    for(ir=0;ir<Nr;ir++){
      r=(ir+0.5)*delr;
      for(imc=0;imc<NMC;imc++){
        ctheta=1.0-2.0*randy->ran();
        cf[iq]+=4.0*PI*r*r*delr*sf[ir]*wf->CalcPsiSquared(iq,r,ctheta);
      }
    }
    cf[iq]=cf[iq]/double(NMC);
    printf("%5.2f : %g\n",q,cf[iq]);
  }

  delete [] cf;
  delete [] sf;
}

